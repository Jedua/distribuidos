#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ETHSIZE 200

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Uso:\n  %s <IP servidor> <puerto> <servicio>\n", argv[0]);
        printf("Ejemplo servicios:\n  estado\n  viaje\n  viaje_terminado <placas>\n");
        return 1;
    }

    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[ETHSIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) { perror("socket"); exit(1); }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect"); exit(1);
    }

    // Armar la petición según argumentos
    char peticion[ETHSIZE] = {0};
    strcpy(peticion, argv[3]);
    if (argc > 4) {
        strcat(peticion, " ");
        strcat(peticion, argv[4]);
    }

    write(sockfd, peticion, strlen(peticion));

    // Esperar respuesta
    int n = read(sockfd, buffer, ETHSIZE-1);
    if (n > 0) {
        buffer[n] = 0;
        printf("Respuesta del servidor: %s\n", buffer);
    } else {
        printf("Sin respuesta o viaje terminado.\n");
    }

    close(sockfd);
    return 0;
}
