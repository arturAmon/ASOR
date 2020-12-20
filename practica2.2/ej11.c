#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    if(argc < 2){
        printf("EJ11: Error, no se ha especificado ruta!\n");
        return -1;
    }

    struct stat estado;
    int statNum = stat(argv[1], &estado);

    if(statNum == -1){
        printf("EJ11: Error, el directorio no existe!\n");
        return -1;
    }

    mode_t modo = estado.st_mode;

    char * hard = malloc(sizeof(char) * (strlen(argv[1]) + 5));
    char * sym = malloc(sizeof(char) * (strlen(argv[1]) + 4));

    strcpy(hard, argv[1]);
    strcpy(sym, argv[1]);

    hard = strcat(hard, ".hard");
    sym = strcat(sym, ".sym");

    if(S_ISREG(modo)){
        if(link(argv[1], hard) == -1) printf("EJ11: Error, no se ha creado el enlace duro\n");
        if(link(argv[1], sym) == -1) printf("EJ11: Error, no se ha creado el enlace simbolico\n");
    }else{
        printf("EJ11:Error, la ruta %s no es un fichero ordinario\n", argv[1]);
    }

    return 0;
}