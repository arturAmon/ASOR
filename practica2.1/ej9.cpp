#include <sys/types.h>  //uid_t
#include <unistd.h>     //getuid()
#include <stdio.h>      //printf

int main(){

    printf("UID real: %d\n", getuid());
    printf("UID efectivo: %d\n", geteuid());

}