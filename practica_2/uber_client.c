#include "uber.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

int distancia(Posicion a, Posicion b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return (int) sqrt(dx * dx + dy * dy);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <host_servidor> <pasajero|admin>\n", argv[0]);
        return 1;
    }

    CLIENT *clnt = clnt_create(argv[1], UBERPROG, UBERVERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(argv[1]);
        return 1;
    }

    srand(time(NULL));

    if (strcmp(argv[2], "pasajero") == 0) {
        Posicion origen = {rand() % 51, rand() % 51};
        InfoAuto info;

        if (solicitar_viaje_1(&origen, &info, clnt) != RPC_SUCCESS) {
            printf("No hay autos disponibles.\n");
            clnt_destroy(clnt);
            return 0;
        }

        printf("Auto asignado (%s), tipo %d, pos (%d,%d), tarifa $%d/km\n",
               info.placas, info.tipo, info.pos.x, info.pos.y, info.tarifa);

        Posicion destino = {rand() % 51, rand() % 51};
        int dist = distancia(origen, destino);
        printf("Simulando viaje a (%d,%d)... distancia %d\n", destino.x, destino.y, dist);
        sleep(dist / 2);

        TerminaViajeArgs fin = {destino, dist * info.tarifa, info.placas};
        void *dummy;
        terminar_viaje_1(&fin, &dummy, clnt);
    }
    else if (strcmp(argv[2], "admin") == 0) {
        while (1) {
            InfoServicio estado;
            if (estado_servicio_1(NULL, &estado, clnt) == RPC_SUCCESS) {
                printf("Viajes: %d | Autos libres: %d | Ganancia: $%d\n",
                       estado.viajes, estado.libres, estado.ganancia);
            } else {
                printf("Error al obtener estado del servicio.\n");
            }
            sleep(2);
        }
    } else {
        printf("Rol inválido. Usa: pasajero o admin\n");
    }

    clnt_destroy(clnt);
    return 0;
}
