#include "uber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void cliente_pasajero(CLIENT *clnt) {
    // Posición de origen y destino aleatoria
    Posicion origen, destino;
    srand(time(NULL) + getpid());
    origen.x = rand() % 51;
    origen.y = rand() % 51;
    destino.x = rand() % 51;
    destino.y = rand() % 51;

    printf("Solicitando viaje de (%d,%d) a (%d,%d)...\n", origen.x, origen.y, destino.x, destino.y);

    InfoAuto *auto_asignado = solicitar_viaje_1(&origen, clnt);

    if (auto_asignado == NULL) {
        printf("No hay autos disponibles, intente más tarde.\n");
        return;
    }

    printf("Asignado auto: Placas %s | Tipo %d | Tarifa $%d/km | Origen auto (%d,%d)\n",
        auto_asignado->placas, auto_asignado->tipo, auto_asignado->tarifa,
        auto_asignado->pos.x, auto_asignado->pos.y);

    // Calcular distancia euclidiana (como int)
    int dx = destino.x - auto_asignado->pos.x;
    int dy = destino.y - auto_asignado->pos.y;
    int distancia = abs(dx) + abs(dy); // Puedes usar sqrt(dx*dx+dy*dy) si prefieres real

    int costo = distancia * auto_asignado->tarifa;
    printf("Distancia estimada: %d km, Costo: $%d\n", distancia, costo);

    // Simular viaje (espera proporcional a distancia)
    printf("Realizando viaje...\n");
    sleep(2 + distancia/10);

    // Termina el viaje
    TerminaViajeArgs fin;
    fin.pos_final = destino;
    fin.costo = costo;
    strncpy(fin.placas, auto_asignado->placas, sizeof(fin.placas));
    terminar_viaje_1(&fin, clnt);
    printf("Viaje terminado, ¡gracias por usar mini-Uber!\n");
}

void cliente_admin(CLIENT *clnt) {
    while (1) {
        InfoServicio *info = estado_servicio_1(NULL, clnt);
        if (info) {
            printf("[ADMIN] Viajes: %d | Autos libres: %d | Ganancia: $%d\n",
                info->viajes, info->libres, info->ganancia);
        }
        sleep(2); // Actualiza cada 2 segundos
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <host_servidor> <rol>\n", argv[0]);
        printf("Roles: pasajero | admin\n");
        exit(1);
    }

    CLIENT *clnt = clnt_create(argv[1], UBERPROG, UBERVERS, "tcp");
    if (!clnt) {
        clnt_pcreateerror(argv[1]);
        exit(1);
    }

    if (strcmp(argv[2], "pasajero") == 0) {
        cliente_pasajero(clnt);
    } else if (strcmp(argv[2], "admin") == 0) {
        cliente_admin(clnt);
    } else {
        printf("Rol no reconocido. Use 'pasajero' o 'admin'.\n");
    }

    clnt_destroy(clnt);
    return 0;
}
