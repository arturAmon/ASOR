#include <sys/types.h>  //uid_t
#include <unistd.h>     //getuid()
#include <stdio.h>      //printf
#include <sys/types.h>  //passwd
#include <pwd.h>        //getpwuid

int main(){

    printf("UID real: %d\n", getuid());                             //uid
    printf("UID efectivo: %d\n", geteuid());                        //euid

    struct passwd *pwd= getpwuid(getuid());

    printf("Nombre de usuario: %s\n", pwd->pw_name);                //username
    printf("Directorio home del usuario: %s\n", pwd->pw_dir);                        //directorio home
    printf("Descripción del usuario: %s\n", pwd->pw_gecos);                 //Nombre completo (por descripcion)

}