#include <stdio.h> //printf
#include <time.h>  //time

int main()
{

    printf("Tiempo en segundos transcurrido desde el epoch (1/1/1970): %i\n", time(NULL));

    return 0;
}