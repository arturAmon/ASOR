#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char * argv[]) {

    if(argc < 2){
        printf("EJ15: Error, modo de uso ej12 <ruta>\n");
        return -1;
    }

    int file = open(argv[1], O_CREAT | O_RDWR, 00777);
    if(file != -1){

      int tam;
        tam = lseek(file, 0, SEEK_END);

       if(lockf(file, F_TEST, tam) == 0){
            if(lockf(file, F_LOCK, tam) == -1){
                printf("EJ15: Error al crear el cerrojo!\n");
                close(file);
                return -1;
            }

            time_t tim = time(NULL);

            struct tm *tm = localtime(&tim);

            char buff[1024];

            sprintf (buff, "Hora: %d:%d\n", tm->tm_hour, tm->tm_min);

            write(file, &buff, strlen(buff));

            sleep(30);

            lockf(file, F_ULOCK, tam);
       }else{
           printf("EJ15: Cerrojo bloqueado!\n");
       }

    }else{
        printf("EJ15: Error, no se pudo acceder a %s\n", argv[1]);
        return -1;
    }


}