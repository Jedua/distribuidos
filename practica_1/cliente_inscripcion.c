#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ETHSIZE   400

struct sockaddr_in serv;

/*
 *  Sintaxis: cliente <direccion IP> <# puerto> <nombre> <clave> <grupo>
 *  Ejemplo: cliente 127.0.0.1 7780 antonio 4604047 CG02C
 */

int main (int argc, char *argv [])
{
    int fd, result_sendto;
    char request[ETHSIZE];  // Mensaje a enviar
    char buffer[ETHSIZE];

    if (argc != 6) {
        printf("\nSintaxis: cliente <direccion IP> <# puerto> <nombre> <clave> <grupo>\n\n");
        exit(-1);
    }

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1) {
        perror("No se pudo abrir el socket");
        exit(-1);
    }

    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(argv[1]);
    serv.sin_port = htons(atoi(argv[2]));

    // Codificar la petición: "<nombre> <clave> <grupo>"
    snprintf(request, ETHSIZE, "%s %s %s", argv[3], argv[4], argv[5]);

    // Enviar al servidor
    result_sendto = sendto(fd, request, strlen(request), 0,
                           (const struct sockaddr *)&serv, sizeof(serv));
    if (result_sendto < 0) {
        perror("Problemas al enviar la petición");
        exit(-1);
    }

    // Esperar respuesta del servidor
    int n = recvfrom(fd, (void *)buffer, ETHSIZE-1, 0,
                     (struct sockaddr *)NULL, (socklen_t *)NULL);
    if (n < 0) {
        perror("Error al recibir datos del servidor");
        exit(-1);
    }
    buffer[n] = '\0'; // Fin de cadena

    // Tratar de leer los dos números de la respuesta
    int cupo, num_solicitud;
    if (sscanf(buffer, "%d %d", &cupo, &num_solicitud) == 2) {
        printf("\nCupo total del grupo: %d\n", cupo);
        printf("Eres la solicitud número: %d\n\n", num_solicitud);
    } else {
        // Si no son dos números, muestra el mensaje tal cual (error del servidor)
        printf("\nRespuesta del servidor: %s\n", buffer);
    }

    close(fd);
    return 0;
}
