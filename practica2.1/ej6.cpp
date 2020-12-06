#include <stdio.h>      //printf
#include <unistd.h>     //sysconf

int main(){

    printf("La longitud máxima de los argumentos para la familia de funciones exec(): %i\n", sysconf(_SC_ARG_MAX));
    printf("El número de procesos simultáneos por cada id. de usuario: %i\n", sysconf(_SC_CHILD_MAX));
    printf("El número de pulsos de reloj por segundo: %i\n", sysconf(_SC_CLK_TCK));
    printf("El máximo número de flujos que un proceso puede tener abiertos en cualquier momento: %i\n", sysconf(_SC_STREAM_MAX));
    printf("El máximo número de bytes en un nombre de huso horario: %i\n", sysconf(_SC_TZNAME_MAX));
    printf("El número máximo de ficheros que un proceso puede tener abiertos en cualquier momento: %i\n", sysconf(_SC_OPEN_MAX));
    printf("El año y el mes en los que se aprobó el estándar POSIX.1, en el formato YYYYMML.El valor 199009L indica la revisión de Septiembre de 1990: %i\n", sysconf(_SC_VERSION));

    return 0;
}