#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ETHSIZE 400
#define PORT 7780

int main() {
    int server_fd, client_fd;
    struct sockaddr_in serv, cli;
    socklen_t cli_len;
    char buffer[ETHSIZE] = {0};
    char datos_para_el_cliente[] = "El clima para hoy se anuncia nublado";

    // Crear socket TCP
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("No se pudo crear el socket");
        exit(EXIT_FAILURE);
    }

    // Configurar dirección y puerto
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(PORT);

    // Asignar dirección al socket
    if (bind(server_fd, (struct sockaddr*)&serv, sizeof(serv)) < 0) {
        perror("Error en bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Escuchar conexiones entrantes
    if (listen(server_fd, 5) < 0) {
        perror("Error en listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Servidor activo en el puerto %d, esperando conexiones...\n", PORT);

    // Ciclo principal: aceptar y atender clientes
    while (1) {
        cli_len = sizeof(cli);
        client_fd = accept(server_fd, (struct sockaddr*)&cli, &cli_len);
        if (client_fd < 0) {
            perror("Error en accept");
            continue;
        }

        printf("Conexión recibida de %s:%d\n", inet_ntoa(cli.sin_addr), ntohs(cli.sin_port));

        // Leer mensaje del cliente
        int bytes_recv = read(client_fd, buffer, ETHSIZE-1);
        if (bytes_recv < 0) {
            perror("Error en read");
            close(client_fd);
            continue;
        }
        buffer[bytes_recv] = '\0';
        printf("Mensaje recibido: %s\n", buffer);

        // Enviar respuesta al cliente
        write(client_fd, datos_para_el_cliente, strlen(datos_para_el_cliente));

        close(client_fd);
    }

    close(server_fd);
    return 0;
}
