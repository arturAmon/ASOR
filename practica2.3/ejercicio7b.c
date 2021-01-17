#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    if (argc < 2)
    {
        printf("Ejercicio7: ERROR introduzca un comando.\n");
        return -1;
    }

    if (system(argv[1]) == -1)
    {
        printf("ERROR: No se ha ejecutado correctamente.\n");
    }

    printf("El comando %s terminó la ejecucuión.\n", argv[1]);

    return 0;
}