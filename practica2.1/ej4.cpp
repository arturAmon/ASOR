#include <sys/utsname.h> //utsname
#include <stdio.h>       //printf

int main()
{

    struct utsname unameSalida;

    if (uname(&unameSalida) != 0)
    {
        printf("Error en setuid con numero %i: %s\n, errno");
        return -1;
    }
    printf("System data: \n");
    printf("Domain:\t\t%s\n", unameSalida.domainname);
    printf("Machine:\t%s\n", unameSalida.machine);
    printf("Nodename:\t%s\n", unameSalida.nodename);
    printf("Release:\t%s\n", unameSalida.release);
    printf("Sysname:\t%s\n", unameSalida.sysname);
    printf("Version:\t%s\n", unameSalida.version);
    return 0;
}