CC=gcc
CFLAGS=-Wall

all: nodo suma_tmk

nodo: nodo.c tmk_lib.c
	$(CC) $(CFLAGS) -o nodo nodo.c tmk_lib.c -lpthread

suma_tmk: suma_tmk.c tmk_lib.c
	$(CC) $(CFLAGS) -o suma_tmk suma_tmk.c tmk_lib.c -lpthread

clean:
	rm -f nodo suma_tmk
