#include <stdio.h>

int main()
{
    char nombre[50] = "Sergio Perez";
    long int clave = 4604047;
    char grupo[20] = "CG02C";
    
    // Esto será el buffer para enviar/recibir
    char mensaje[200];
    
    // CODIFICACIÓN
    // El punto y coma ';' nos servirá como separador.
    sprintf(mensaje, "%s;%ld;%s", nombre, clave, grupo);
    printf("El mensaje es: '%s'", mensaje);
    
    
    // DECODIFICACIÓN
    char name[50];
    long int clv;
    char gpo[20];
    
    sscanf(mensaje, "%[^\t\n];%ld;%s", name, &clv, gpo);
    
    printf("\n\nRecibí nombre=%s, clave=%ld, grupo=%s\n", name, clv, gpo);

    return 0;
}
