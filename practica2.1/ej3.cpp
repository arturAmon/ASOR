#include <string.h> // strerror
#include <stdio.h>  // printf

const unsigned int MAX_ERROR = 255;

int main(){
    unsigned int i = 0;

    for (i; i < MAX_ERROR; i++)
    {
        printf("Error num %d: %s\n", i, strerror(i));
    }
    
    return 0;
}