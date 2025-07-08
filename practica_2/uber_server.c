
#include "uber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern void uberprog_1(struct svc_req *rqstp, SVCXPRT *transp);

#define N_AUTOS 8

static InfoAuto autos[N_AUTOS];
static int viajes_realizados = 0;
static int ganancia_total = 0;

void inicializa_autos() {
    srand(time(NULL));
    for (int i = 0; i < N_AUTOS; ++i) {
        autos[i].disponible = 1;
        autos[i].pos.x = rand() % 51;
        autos[i].pos.y = rand() % 51;
        autos[i].tipo = rand() % 3;
        switch (autos[i].tipo) {
            case UBER_PLANET: autos[i].tarifa = 10; break;
            case UBER_XL: autos[i].tarifa = 15; break;
            case UBER_BLACK: autos[i].tarifa = 25; break;
        }
        char temp[16];
        snprintf(temp, sizeof(temp), "%03dABC", 100 + i);
        autos[i].placas = strdup(temp);
    }
}

bool_t solicitar_viaje_1_svc(Posicion *argp, InfoAuto *result, struct svc_req *rqstp) {
    int mejor = -1;
    int mejor_dist = 1 << 30;

    for (int i = 0; i < N_AUTOS; ++i) {
        if (autos[i].disponible) {
            int dx = autos[i].pos.x - argp->x;
            int dy = autos[i].pos.y - argp->y;
            int dist = dx * dx + dy * dy;
            if (dist < mejor_dist) {
                mejor = i;
                mejor_dist = dist;
            }
        }
    }
    if (mejor != -1) {
        autos[mejor].disponible = 0;
        *result = autos[mejor];
        return TRUE;
    }
    return FALSE;
}

bool_t terminar_viaje_1_svc(TerminaViajeArgs *argp, void *result, struct svc_req *rqstp) {
    for (int i = 0; i < N_AUTOS; ++i) {
        if (strcmp(autos[i].placas, argp->placas) == 0) {
            autos[i].disponible = 1;
            autos[i].pos = argp->pos_final;
            ganancia_total += argp->costo;
            viajes_realizados++;
            printf("Viaje terminado: placas %s, nueva pos (%d,%d), +$%d\n",
                   autos[i].placas, argp->pos_final.x, argp->pos_final.y, argp->costo);
            break;
        }
    }
    return TRUE;
}

bool_t estado_servicio_1_svc(void *argp, InfoServicio *result, struct svc_req *rqstp) {
    int libres = 0;
    for (int i = 0; i < N_AUTOS; ++i)
        if (autos[i].disponible)
            libres++;
    result->viajes = viajes_realizados;
    result->libres = libres;
    result->ganancia = ganancia_total;
    return TRUE;
}

int uberprog_1_freeresult(SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result) {
    xdr_free(xdr_result, result);
    return 1;
}

int main() {
    inicializa_autos();

    SVCXPRT *transp;

    pmap_unset(UBERPROG, UBERVERS);

    transp = svcudp_create(RPC_ANYSOCK);
    if (transp == NULL) {
        fprintf(stderr, "cannot create UDP service.\n");
        exit(1);
    }
    if (!svc_register(transp, UBERPROG, UBERVERS, uberprog_1, IPPROTO_UDP)) {
        fprintf(stderr, "unable to register (UBERPROG, UBERVERS, udp).\n");
        exit(1);
    }

    transp = svctcp_create(RPC_ANYSOCK, 0, 0);
    if (transp == NULL) {
        fprintf(stderr, "cannot create TCP service.\n");
        exit(1);
    }
    if (!svc_register(transp, UBERPROG, UBERVERS, uberprog_1, IPPROTO_TCP)) {
        fprintf(stderr, "unable to register (UBERPROG, UBERVERS, tcp).\n");
        exit(1);
    }

    printf("Servidor Uber RPC iniciado con %d autos\n", N_AUTOS);
    svc_run();
    fprintf(stderr, "Error: svc_run terminó inesperadamente\n");
    return 1;
}

