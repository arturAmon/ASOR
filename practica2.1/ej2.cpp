#include <unistd.h>     //para setuid(0)
#include <errno.h>      //para la salida estándar de errores y errno
#include <stdio.h>      //para perror
#include <string.h>     //para strerror

int main(){
    
    if(setuid(0) != 0){
        printf("Error en setuid con numero %i: %s\n", errno, strerror(errno));
    }
    return 1;
}