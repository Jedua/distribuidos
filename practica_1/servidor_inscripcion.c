#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SOLICITUDES 100
#define ETHSIZE   400
#define PORT 7780

struct sockaddr_in serv, cli;

typedef struct {
    char nombre[100];
    int clave;
    char grupo[20];
} Solicitud;

Solicitud lista[MAX_SOLICITUDES];
int total_solicitudes = 0;

int main ()
{
    int fd, idb, cli_len, size_recv;
    char request[ETHSIZE];

    printf("\nCreando el socket...\n");
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1) {
        perror("Error al crear el socket");
        exit(-1);
    }

    printf("Asignando atributos al socket...\n");
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(PORT);

    idb = bind(fd, (struct sockaddr *)&serv, sizeof(serv));
    if (idb < 0) {
        perror("Error en bind");
        close(fd);
        exit(-1);
    }
    printf("Escuchando en el puerto %d...\n", PORT);

    // Ciclo infinito para atender múltiples peticiones
    while (1) {
        printf("\nEsperando petición de un cliente...\n");

        cli_len = sizeof(cli);
        size_recv = recvfrom(fd, (void *)request, ETHSIZE-1, 0,
                             (struct sockaddr *)&cli, (socklen_t *)&cli_len);

        if (size_recv < 0) {
            perror("Error en recvfrom");
            continue;
        }

        request[size_recv] = '\0';
        printf("Mensaje recibido de %s:%d: '%s'\n",
               inet_ntoa(cli.sin_addr), ntohs(cli.sin_port), request);

        // Decodificar los datos (nombre, clave, grupo)
        char nombre[100], grupo[20];
        int clave;
        int n = sscanf(request, "%s %d %s", nombre, &clave, grupo);

        if (n == 3 && total_solicitudes < MAX_SOLICITUDES) {
            // Guardar la solicitud
            strcpy(lista[total_solicitudes].nombre, nombre);
            lista[total_solicitudes].clave = clave;
            strcpy(lista[total_solicitudes].grupo, grupo);
            total_solicitudes++;

            // Mostrar la lista de solicitudes
            printf("\nLista de solicitudes:\n");
            for (int i = 0; i < total_solicitudes; ++i) {
                printf("%d: %s %d %s\n", i+1, lista[i].nombre, lista[i].clave, lista[i].grupo);
            }

            // Responder con el cupo total y el número de solicitud
            int cupo = 4;
            char respuesta[100];
            snprintf(respuesta, sizeof(respuesta), "%d %d", cupo, total_solicitudes);
            sendto(fd, respuesta, strlen(respuesta), 0,
                   (struct sockaddr *)&cli, (socklen_t)cli_len);
        } else {
            char error_msg[] = "Error: Formato de petición inválido o cupo lleno.";
            sendto(fd, error_msg, strlen(error_msg), 0,
                   (struct sockaddr *)&cli, (socklen_t)cli_len);
        }
    }

    close(fd);
    return 0;
}
