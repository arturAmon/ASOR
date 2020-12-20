#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

    if(argc < 2){
        printf("EJ12: Error, modo de uso ej12 <ruta>\n");
        return -1;
    }

    int file = open(argv[1], O_CREAT | O_WRONLY | O_APPEND);
    if(file != -1){
        dup2(file, 1);

        printf("EJ12: Serie Fibonacci:\n");

        int a = 1;
        int b = 1;
        int i = 0;

        for(i; i < 5; ++i){
            printf("\t%d\n", a);
            printf("\t%d\n", b);
            a += b;
            b += a;
        }

        dup2(1, file);

    }else{
        printf("EJ12: Error, no se pudo acceder a %s\n", argv[1]);
        return -1;
    }

}