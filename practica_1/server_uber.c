#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 7780
#define NUM_AUTOS 5

// 1 = libre (V), 0 = ocupado (F)
int autos[NUM_AUTOS];
int viajes = 0;
int ganancia = 0;

// Imprime el estado actual de los autos
void mostrar_autos() {
    printf("Estado actual de autos: [");
    for (int i = 0; i < NUM_AUTOS; i++)
        printf(" %d:%c", i, autos[i] ? 'V' : 'F');
    printf(" ]\n");
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;
    char buffer[200];
    srand(time(NULL));

    // Inicializar autos como libres
    for (int i = 0; i < NUM_AUTOS; i++) autos[i] = 1;

    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&cli_addr, 0, sizeof(cli_addr));

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); exit(1); }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }
    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Servidor activo en puerto %d...\n", PORT);

    while (1) {
        cli_len = sizeof(cli_addr);
        client_fd = accept(server_fd, (struct sockaddr*)&cli_addr, &cli_len);
        if (client_fd < 0) { perror("accept"); continue; }

        printf("\n----------------------\n");
        printf("Conexión de %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        memset(buffer, 0, sizeof(buffer));
        int n = read(client_fd, buffer, sizeof(buffer)-1);
        if (n < 0) { perror("read"); close(client_fd); continue; }
        buffer[n] = 0;

        printf("Petición recibida: '%s'\n", buffer);

        // 1. viaje_terminado
        if (strncmp(buffer, "viaje_terminado", 15) == 0) {
            int placa;
            printf("-> Servicio solicitado: VIAJE_TERMINADO\n");
            if (sscanf(buffer, "viaje_terminado %d", &placa) == 1) {
                printf("   [DEBUG] Placa recibida: %d\n", placa);
                if (placa >= 0 && placa < NUM_AUTOS) {
                    printf("   [DEBUG] Estado antes de liberar auto %d: %c\n", placa, autos[placa] ? 'V' : 'F');
                    if (autos[placa] == 0) {
                        autos[placa] = 1;
                        char respuesta[100];
                        snprintf(respuesta, sizeof(respuesta), "Viaje terminado para el auto %d", placa);
                        write(client_fd, respuesta, strlen(respuesta));
                        printf("   [INFO] Auto %d liberado correctamente.\n", placa);
                    } else {
                        write(client_fd, "Auto ya estaba libre", strlen("Auto ya estaba libre"));
                        printf("   [WARN] Auto %d ya estaba libre.\n", placa);
                    }
                } else {
                    write(client_fd, "Error en placas", strlen("Error en placas"));
                    printf("   [ERROR] Placa fuera de rango: %d\n", placa);
                }
            } else {
                write(client_fd, "Error en formato de placa", strlen("Error en formato de placa"));
                printf("   [ERROR] No se pudo leer la placa correctamente.\n");
            }
        }
        // 2. viaje_cancelado
        else if (strncmp(buffer, "viaje_cancelado", 15) == 0) {
            int placa;
            printf("-> Servicio solicitado: VIAJE_CANCELADO\n");
            if (sscanf(buffer, "viaje_cancelado %d", &placa) == 1) {
                printf("   [DEBUG] Placa recibida: %d\n", placa);
                if (placa >= 0 && placa < NUM_AUTOS) {
                    printf("   [DEBUG] Estado antes de liberar auto %d: %c\n", placa, autos[placa] ? 'V' : 'F');
                    if (autos[placa] == 0) {
                        autos[placa] = 1;
                        char respuesta[100];
                        snprintf(respuesta, sizeof(respuesta), "Viaje cancelado y auto liberado para el auto %d", placa);
                        write(client_fd, respuesta, strlen(respuesta));
                        printf("   [INFO] Auto %d liberado por cancelación.\n", placa);
                    } else {
                        write(client_fd, "Auto ya estaba libre", strlen("Auto ya estaba libre"));
                        printf("   [WARN] Auto %d ya estaba libre.\n", placa);
                    }
                } else {
                    write(client_fd, "Error en placas", strlen("Error en placas"));
                    printf("   [ERROR] Placa fuera de rango: %d\n", placa);
                }
            } else {
                write(client_fd, "Error en formato de placa", strlen("Error en formato de placa"));
                printf("   [ERROR] No se pudo leer la placa correctamente.\n");
            }
        }
        // 3. viaje
        else if (strncmp(buffer, "viaje", 5) == 0) {
            printf("-> Servicio solicitado: VIAJE\n");
            int encontrado = 0, placa = -1, costo = 0;
            for (int i = 0; i < NUM_AUTOS; ++i) {
                printf("   [DEBUG] Auto %d estado antes: %c\n", i, autos[i] ? 'V' : 'F');
                if (autos[i] == 1) { // auto libre
                    placa = i;
                    costo = 40 + rand() % 61; // 40-100
                    autos[i] = 0;
                    viajes++;
                    ganancia += costo;
                    encontrado = 1;
                    printf("   [INFO] Asignado auto %d con costo %d\n", placa, costo);
                    break;
                }
            }
            if (encontrado) {
                char respuesta[100];
                snprintf(respuesta, sizeof(respuesta), "%d %d", placa, costo);
                write(client_fd, respuesta, strlen(respuesta));
            } else {
                const char *sin_conductor = "No hay conductores";
                write(client_fd, sin_conductor, strlen(sin_conductor));
                printf("   [WARN] No hay autos disponibles\n");
            }
        }
        // 4. estado
        else if (strncmp(buffer, "estado", 6) == 0) {
            printf("-> Servicio solicitado: ESTADO\n");
            char respuesta[100];
            snprintf(respuesta, sizeof(respuesta), "%d %d", viajes, ganancia);
            write(client_fd, respuesta, strlen(respuesta));
        }
        // 5. Servicio desconocido
        else {
            write(client_fd, "Servicio desconocido", strlen("Servicio desconocido"));
            printf("   [WARN] Servicio desconocido recibido.\n");
        }

        mostrar_autos();
        close(client_fd);
    }
    close(server_fd);
    return 0;
}
