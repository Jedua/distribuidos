#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tmk_lib.h"

#define COORDINADOR 0

int main(int argc, char **argv) {
    Tmk_startup(argc, argv);

    if (Tmk_proc_id == COORDINADOR) {
        printf("[Nodo %d] Soy el coordinador\n", Tmk_proc_id);
    } else {
        printf("[Nodo %d] Soy un worker\n", Tmk_proc_id);
    }

    Tmk_barrier(0);
    printf("[Nodo %d] Terminé la barrera\n", Tmk_proc_id);

    // Simular acceso a sección crítica
    if (Tmk_proc_id != COORDINADOR) {
        sleep(Tmk_proc_id);  // simula llegada desordenada
        printf("[Nodo %d] Solicitando acceso al lock\n", Tmk_proc_id);
        Tmk_lock_acquire(0);

        printf("[Nodo %d] >>> EN SECCIÓN CRÍTICA <<<\n", Tmk_proc_id);
        sleep(2);  // simula trabajo crítico
        printf("[Nodo %d] <<< SALIENDO DE SECCIÓN CRÍTICA >>>\n", Tmk_proc_id);

        Tmk_lock_release(0);
    }

    Tmk_exit(0);
}
