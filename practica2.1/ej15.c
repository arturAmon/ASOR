#include <time.h>       //time, localtime
#include <stdio.h>      //printf
#include <locale.h>     //setlocale

const int BUFF_TAM = 150;

int main(){

    setlocale(LC_ALL, "es_ES.utf8");

    time_t tiempo = time(NULL);
    struct tm *lt = localtime(&tiempo);

    char buffer[BUFF_TAM];
    strftime(buffer, BUFF_TAM, "%A, %e de %B de %G, %H:%M%n",lt);
    printf("%s", buffer);
    return 0;
}