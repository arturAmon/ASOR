#include <stdio.h>     //printf
#include <unistd.h>    //pathconf
#include <string.h>    //strcpy
#include <sys/stat.h>  //stat          se usa para comprobar si existe un directorio
#include <sys/types.h> //struct stat   se usa para comprobar si existe un directorio

int main(int argc, char *argv[])
{

    char * path;    

    if (argc >= 2)
    {
        struct stat info;
        if (stat(argv[1], &info) != 0){
            printf("No se puede acceder a %s\n", argv[1]);
            return -1;
        }
        if( info.st_mode & S_IFDIR)
            path = argv[1];
        else printf("Error: %s no es un directorio!\n", argv[1]);
    }
    else path = "/";

    printf("Datos del directorio %s:\n", path);
    printf("El número máximo de enlaces al fichero. Si descf o camino se refieren a un directorio, entonces el valor se aplica al directorio entero: %i\n", pathconf(path, _PC_LINK_MAX));
    printf("La longitud máxima de una línea de entrada formateada, donde descf o camino deben referirse a una terminal: %i\n", pathconf(path, _PC_MAX_CANON));
    printf("La longitud máxima de una línea de entrada, donde descf o camino deben referirse a una terminal: %i\n", pathconf(path, _PC_MAX_INPUT));
    printf("La máxima longitud de un nombre de fichero en el directorio camino o descf que el proceso es capaz de crear: %i\n", pathconf(path, _PC_NAME_MAX));
    printf("La máxima longitud de un nombre de camino relativo donde camino o descf es el directorio de trabajo: %i\n", pathconf(path, _PC_PATH_MAX));
    printf("El tamaño del búfer de interconexión, donde descf debe referirse a una interconexión o FIFO y camino debe referirse a un fichero FIFO: %i\n", pathconf(path, _PC_PIPE_BUF));

    return 0;
}