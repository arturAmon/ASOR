#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void muestraSalidaYError(){

    printf("Inicio\n");

    printf("Salida estandar:\nMúltiplos de 7:\n");
    int i = 0;
    for(i; i < 10; ++i){
        printf("\t%d", (i+1)*7);
    }
    printf("\n");

    fprintf(stderr, "Salida de error\nMúltiplos de 5:\n");
    for(i = 0; i < 10; ++i){
        fprintf(stderr, "\t%d", (i+1)*5);
    }
    fprintf(stderr, "\n");

     printf("Fin\n");

}

int main(int argc, char *argv[]){

    if(argc < 2){
        printf("EJ13: Error, modo de uso ej13 <ruta>\n");
        return -1;
    }

    int file = open(argv[1], O_CREAT | O_WRONLY | O_APPEND);
    if(file != -1){
        int stdSalida = dup2(file, 1);
        int stdError = dup2(file, 2);
       
            muestraSalidaYError();

        dup2(stdError, file);
        dup2(stdSalida, file);

        stdSalida = dup2(file, 2);
        stdError = dup2(file, 1);
       
            muestraSalidaYError();

        dup2(stdError, file);
        dup2(stdSalida, file);  

    }else{
        printf("EJ13: Error, no se pudo acceder a %s\n", argv[1]);
        return -1;
    }

}