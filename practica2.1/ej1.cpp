#include <unistd.h>     //para setuid(0)
#include <stdio.h>      //para perror

int main(){
    
    char *c;
    if(setuid(0) != 0){
        perror(c);
    }
    return 1;
}