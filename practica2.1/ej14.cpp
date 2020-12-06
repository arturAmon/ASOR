#include <time.h> //time, localtime
#include <stdio.h>//printf

int main(){

    time_t tiempo = time(NULL);
    struct tm *lt = localtime(&tiempo);

    printf("El año es %d.\n", 1900 + lt->tm_year);
    return 0;
}