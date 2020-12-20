#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char * argv[]){

    DIR *d;
    struct dirent *dir;
    d = opendir(argv[1]);
    if(d){
        while((dir = readdir(d)) != NULL){
            
            struct stat estado;
            int statNum = stat(dir->d_name, &estado);

            mode_t modo = estado.st_mode;
            printf("\t");

            if (modo & S_IXUSR)
                printf("*");

            if(S_ISDIR(modo)){
                printf("%s/\n", dir->d_name);
            }else if(S_ISREG(modo)){
                printf("%s\n", dir->d_name);
            }else if(S_ISCHR(modo)){
                printf("dispositivo de carácter\n");
            }else if(S_ISBLK(modo)){
                printf("dispositivo de bloque\n");
            }else if(S_ISFIFO(modo)){
                printf("FIFO\n");
            }else if(S_ISLNK(modo)){

                char buf[30];

                printf("%s->%s",dir->d_name, readlink(dir->d_name, buf, sizeof(buf)));
            }else if(S_ISSOCK(modo)){
                printf("socket\n");
            }


        }
        closedir(d);
    }
    else{
        printf("EJ17: Error %s no es un directorio\n", argv[1]);
    }
    return 0;
}