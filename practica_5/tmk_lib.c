#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "tmk_lib.h"

#define BARRIER_PORT 9000
#define LOCK_PORT 9100
#define DIST_PORT 9200
#define MAX_QUEUE 10

int Tmk_proc_id = 0;
int Tmk_nprocs = 1;
int server_socket = -1;
int client_socket = -1;

// Para lock distribuido
pthread_t lock_thread;
int lock_in_use = 0;
int lock_queue[MAX_QUEUE];
int queue_front = 0, queue_rear = 0;

void* lock_server(void* arg);
void enqueue(int pid);
int dequeue();

void Tmk_startup(int argc, char **argv) {
    char *id_env = getenv("TMK_PROC_ID");
    char *n_env  = getenv("TMK_NPROCS");

    if (id_env) Tmk_proc_id = atoi(id_env);
    if (n_env)  Tmk_nprocs  = atoi(n_env);

    // --- Barrera TCP simple ---
    if (Tmk_proc_id == 0) {
        int opt = 1;
        struct sockaddr_in address;
        int addrlen = sizeof(address);

        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(BARRIER_PORT);

        bind(server_socket, (struct sockaddr *)&address, sizeof(address));
        listen(server_socket, Tmk_nprocs - 1);
        printf("[Coordinador] Esperando %d conexiones...\n", Tmk_nprocs - 1);

        for (int i = 1; i < Tmk_nprocs; i++) {
            int new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
            send(new_socket, "OK", 2, 0);
            close(new_socket);
        }

        // Lanzar servidor de locks
        pthread_create(&lock_thread, NULL, lock_server, NULL);

    } else {
        struct sockaddr_in serv_addr;
        client_socket = socket(AF_INET, SOCK_STREAM, 0);

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(BARRIER_PORT);
        serv_addr.sin_addr.s_addr = inet_addr("172.28.0.2"); // Coordinador

        while (connect(client_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            sleep(1);
        }

        char buffer[10] = {0};
        read(client_socket, buffer, 2); // Espera "OK"
        close(client_socket);
    }
}

void Tmk_barrier(int id) {
    // Implementada dentro de Tmk_startup()
}

void Tmk_exit(int code) {
    if (server_socket != -1) close(server_socket);
    if (client_socket != -1) close(client_socket);
    exit(code);
}

void* Tmk_malloc(int size) { return malloc(size); }
void  Tmk_free(void* ptr)  { free(ptr); }

// ---------------------- LOCK DISTRIBUIDO ------------------------

void enqueue(int pid) {
    lock_queue[queue_rear++] = pid;
    if (queue_rear >= MAX_QUEUE) queue_rear = 0;
}

int dequeue() {
    int pid = lock_queue[queue_front++];
    if (queue_front >= MAX_QUEUE) queue_front = 0;
    return pid;
}

void* lock_server(void* arg) {
    int sockfd, new_sock;
    struct sockaddr_in addr;
    char buffer[32];
    socklen_t len = sizeof(addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(LOCK_PORT);

    bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    listen(sockfd, MAX_QUEUE);

    while (1) {
        new_sock = accept(sockfd, (struct sockaddr *)&addr, &len);
        memset(buffer, 0, sizeof(buffer));
        read(new_sock, buffer, sizeof(buffer));

        if (strncmp(buffer, "LOCK", 4) == 0) {
            int pid = atoi(buffer + 5);
            if (!lock_in_use) {
                lock_in_use = 1;
                send(new_sock, "GRANT", 5, 0);
            } else {
                enqueue(pid);
                send(new_sock, "WAIT", 4, 0); // opcional
            }
        } else if (strncmp(buffer, "RELEASE", 7) == 0) {
            if (queue_front != queue_rear) {
                int next_pid = dequeue();
                printf("[LockServer] Grant pendiente a PID %d (simulado)\n", next_pid);
                lock_in_use = 1;
            } else {
                lock_in_use = 0;
            }
        }

        close(new_sock);
    }

    return NULL;
}

void Tmk_lock_acquire(int id) {
    if (Tmk_proc_id == 0) return;

    int sockfd;
    struct sockaddr_in serv_addr;
    char msg[32], buffer[32] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(LOCK_PORT);
    serv_addr.sin_addr.s_addr = inet_addr("172.28.0.2");

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    sprintf(msg, "LOCK %d", Tmk_proc_id);
    send(sockfd, msg, strlen(msg), 0);
    read(sockfd, buffer, sizeof(buffer));

    if (strncmp(buffer, "GRANT", 5) == 0) {
        printf("[Nodo %d] Acceso concedido al lock\n", Tmk_proc_id);
    }

    close(sockfd);
}

void Tmk_lock_release(int id) {
    if (Tmk_proc_id == 0) return;

    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(LOCK_PORT);
    serv_addr.sin_addr.s_addr = inet_addr("172.28.0.2");

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(sockfd, "RELEASE", 7, 0);
    close(sockfd);
}

// ---------------------- DISTRIBUCIÓN ------------------------

void Tmk_distribute(void** ptr, int size) {
    if (Tmk_proc_id == 0) {
        for (int i = 1; i < Tmk_nprocs; i++) {
            int sockfd;
            struct sockaddr_in addr;

            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            addr.sin_family = AF_INET;
            addr.sin_port = htons(DIST_PORT);
            char ip[32];
            snprintf(ip, sizeof(ip), "172.28.0.%d", i + 2);
            addr.sin_addr.s_addr = inet_addr(ip);

            printf("[Coordinador] Enviando datos a nodo %d (%s)...\n", i, ip);
            fflush(stdout);

            while (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
                perror("[Coordinador] Esperando conexión a worker");
                sleep(1);
            }

            send(sockfd, *ptr, size, 0);
            printf("[Coordinador] Datos enviados a nodo %d\n", i);
            close(sockfd);
        }
    } else {
        int sockfd;
        struct sockaddr_in addr;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(DIST_PORT);

        bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        listen(sockfd, 1);

        printf("[Nodo %d] Esperando datos del coordinador...\n", Tmk_proc_id);
        fflush(stdout);

        int client = accept(sockfd, NULL, NULL);

        *ptr = malloc(size);
        read(client, *ptr, size);
        close(client);
        close(sockfd);

        printf("[Nodo %d] Recibí datos del coordinador\n", Tmk_proc_id);
        fflush(stdout);
    }
}

