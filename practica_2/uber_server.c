#include "uber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N_AUTOS 8

// Arreglo de autos y estadísticas globales
static InfoAuto autos[N_AUTOS];
static int viajes_realizados = 0;
static int ganancia_total = 0;

// Inicialización de autos (puedes modularizar si lo deseas)
void inicializa_autos()
{
    srand(time(NULL));
    for (int i = 0; i < N_AUTOS; ++i)
    {
        autos[i].disponible = 1;
        autos[i].pos.x = rand() % 51;
        autos[i].pos.y = rand() % 51;
        autos[i].tipo = rand() % 3; // 0: Planet, 1: XL, 2: Black
        switch (autos[i].tipo)
        {
        case UBER_PLANET:
            autos[i].tarifa = 10;
            break;
        case UBER_XL:
            autos[i].tarifa = 15;
            break;
        case UBER_BLACK:
            autos[i].tarifa = 25;
            break;
        }
        // Genera una placa pseudoaleatoria y ASIGNA memoria
        char temp[16];
        snprintf(temp, sizeof(temp), "%03dABC", 100 + i);
        autos[i].placas = strdup(temp); // <<< ¡CORRECTO!
    }
}

// Lógica del procedimiento RPC: solicitar_viaje
InfoAuto *solicitar_viaje_1_svc(Posicion *pos_p, struct svc_req *rqstp)
{
    static InfoAuto respuesta;
    int mejor = -1;
    int mejor_dist = 1 << 30;
    for (int i = 0; i < N_AUTOS; ++i)
    {
        if (autos[i].disponible)
        {
            int dx = autos[i].pos.x - pos_p->x;
            int dy = autos[i].pos.y - pos_p->y;
            int dist = dx * dx + dy * dy;
            if (dist < mejor_dist)
            {
                mejor = i;
                mejor_dist = dist;
            }
        }
    }
    if (mejor != -1)
    {
        autos[mejor].disponible = 0;
        respuesta = autos[mejor];
        return &respuesta;
    }
    else
    {
        return NULL; // No hay autos disponibles
    }
}

// Lógica del procedimiento RPC: terminar_viaje
void *terminar_viaje_1_svc(TerminaViajeArgs *args, struct svc_req *rqstp)
{
    for (int i = 0; i < N_AUTOS; ++i)
    {
        if (strcmp(autos[i].placas, args->placas) == 0)
        {
            autos[i].disponible = 1;
            autos[i].pos = args->pos_final;
            ganancia_total += args->costo;
            viajes_realizados++;
            printf("Viaje terminado: placas %s, nuevo pos (%d,%d), +$%d\n",
                   autos[i].placas, args->pos_final.x, args->pos_final.y, args->costo);
            break;
        }
    }
    return NULL;
}

// Lógica del procedimiento RPC: estado_servicio
InfoServicio *estado_servicio_1_svc(void *noarg, struct svc_req *rqstp)
{
    static InfoServicio info;
    int libres = 0;
    for (int i = 0; i < N_AUTOS; ++i)
        if (autos[i].disponible)
            libres++;
    info.viajes = viajes_realizados;
    info.libres = libres;
    info.ganancia = ganancia_total;
    return &info;
}

int main()
{
    inicializa_autos();
    printf("Servidor Uber RPC iniciado con %d autos\n", N_AUTOS);
    svc_run(); // Espera y atiende llamadas RPC
    fprintf(stderr, "Error: svc_run terminó inesperadamente\n");
    return 1;
}
