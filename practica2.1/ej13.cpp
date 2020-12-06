#include <sys/types.h>      //timeval
#include <sys/time.h>       //gettimeofday
#include <stdio.h>          //NULL

int main(){

    unsigned int i;

    struct timeval tiempo_antes;
    gettimeofday(&tiempo_antes, NULL);

    for (i = 0; i < 1000000; i++);    

    struct timeval tiempo_despues;
    gettimeofday(&tiempo_despues, NULL);

    printf("Tiempo para incrementar una variable en 1, 1.000.000 veces: %i\n", tiempo_despues.tv_usec - tiempo_antes.tv_usec);
}