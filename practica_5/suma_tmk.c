#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include "tmk_lib.h"

#define DIM 10
#define COORDINADOR 0

typedef struct {
    int array[DIM];
    int sum_global;
} Info;

Info* shared;

int main(int argc, char **argv) {

    printf("[Nodo %d] Arrancando ejecución\n", Tmk_proc_id);
    fflush(stdout);

    int start, end, local_sum = 0;

    Tmk_startup(argc, argv);

    if (Tmk_proc_id == COORDINADOR) {
        shared = Tmk_malloc(sizeof(Info));
        for (int i = 0; i < DIM; i++) {
            shared->array[i] = i + 1;
        }
        shared->sum_global = 0;
    }

    Tmk_distribute((void**)&shared, sizeof(Info));

    Tmk_barrier(0);  // asegurarse que todos tienen la estructura

    // Dividir el trabajo
    int per_proc = DIM / Tmk_nprocs;
    int extra = DIM % Tmk_nprocs;

    start = Tmk_proc_id * per_proc + (Tmk_proc_id < extra ? Tmk_proc_id : extra);
    end = start + per_proc + (Tmk_proc_id < extra ? 1 : 0);

    printf("[Nodo %d] Sumaré array[%d .. %d)\n", Tmk_proc_id, start, end);

    for (int i = start; i < end; i++) {
        local_sum += shared->array[i];
    }

    Tmk_barrier(0);  // todos terminan de calcular local_sum

    if (Tmk_proc_id == COORDINADOR) {
        // 1. Servidor: espera sumas
        int sockfd, client;
        struct sockaddr_in addr;
        socklen_t len = sizeof(addr);

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(9300);
        bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        listen(sockfd, Tmk_nprocs - 1);

        for (int i = 1; i < Tmk_nprocs; i++) {
            int temp = 0;
            client = accept(sockfd, (struct sockaddr *)&addr, &len);
            read(client, &temp, sizeof(int));
            shared->sum_global += temp;
            close(client);
        }

        shared->sum_global += local_sum;  // suma del coordinador
        close(sockfd);

        printf("[Coordinador] Suma total: %d\n", shared->sum_global);

    } else {
        // 2. Workers envían la suma
        Tmk_lock_acquire(0);

        int sockfd;
        struct sockaddr_in serv_addr;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(9300);
        serv_addr.sin_addr.s_addr = inet_addr("172.28.0.2");

        // Esperar hasta que el coordinador esté escuchando
        while (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            sleep(1);
        }

        send(sockfd, &local_sum, sizeof(int), 0);
        close(sockfd);
        Tmk_lock_release(0);
    }

    Tmk_exit(0);
}
