#ifndef TMK_LIB_H
#define TMK_LIB_H

// Inicializa TreadMarks distribuido (arranque de red, procesos, etc.)
void Tmk_startup(int argc, char **argv);

// Sincroniza a todos los procesos (implementado dentro de startup)
void Tmk_barrier(int id);

// Termina el proceso limpiamente
void Tmk_exit(int code);

// Simula malloc en memoria distribuida (por ahora local)
void* Tmk_malloc(int size);
void  Tmk_free(void* ptr);

// Distribuye punteros o estructuras (sin implementación real aún)
void Tmk_distribute(void** ptr, int size);

// Exclusión mutua distribuida (comunicación con coordinador)
void Tmk_lock_acquire(int id);
void Tmk_lock_release(int id);

// ID del proceso actual y cantidad total de procesos
extern int Tmk_proc_id;
extern int Tmk_nprocs;

#endif
