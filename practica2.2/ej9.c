#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char **argv) {

    if(argc < 2){
        printf("EJ9: ERROR uso: ej9 <fichero/directorio>\n");
    }

    struct stat estado;
    int statNum = stat(argv[1], &estado);

    if(statNum == -1){
        printf("EJ9: ERROR el fichero/directorio %s no existe!", argv[1]);
        return -1;
    }

    printf("\tMinor: %d\n", minor(estado.st_dev));  //minor
    printf("\tMajor: %d\n", major(estado.st_dev));  //major
    printf("\tI-nodo: %d\n", estado.st_mode);         //i-nodo

    mode_t modo = estado.st_mode;
    printf("\tTipo: ");
    if(S_ISDIR(modo)){
        printf("directorio\n");
    }else if(S_ISREG(modo)){
        printf("fichero regular\n");
    }else if(S_ISCHR(modo)){
        printf("dispositivo de carácter\n");
    }else if(S_ISBLK(modo)){
        printf("dispositivo de bloque\n");
    }else if(S_ISFIFO(modo)){
        printf("FIFO\n");
    }else if(S_ISLNK(modo)){
        printf("enlace simbólico\n");
    }else if(S_ISSOCK(modo)){
        printf("socket\n");
    }

    time_t t = estado.st_mtime;
    struct tm *mtime = localtime(&t);
    printf("\tÚltimo acceso (mtime): %d:%d\n", mtime->tm_hour, mtime->tm_min);
    t = estado.st_ctime;
    mtime = localtime(&t);
    printf("\tÚltimo acceso (ctime): %d:%d\n", mtime->tm_hour, mtime->tm_min);
    
}