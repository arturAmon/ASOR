#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{

  if (argc < 2)
  {
    printf("Ejercicio7: ERROR introduzca un comando.\n");
    return -1;
  }

  if (execvp(argv[1], argv + 1) == -1)
  {
    printf("Ejercicio7: ERROR No se ha ejecutado el comando %s.\n", argv[1]);
  }

  printf("El comando %s terminó la ejecucuión.\n", argv[1]);

  return 0;
}