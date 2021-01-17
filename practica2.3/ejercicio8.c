#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("Ejercicio7: ERROR introduzca un comando.\n");
        return -1;
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        pid_t sessionID = setsid();
        printf("Proceso Hijo: \t\t (%d) padre: %d\n", getpid(), getppid());
        int fd = open("/tmp/daemon.out", O_CREAT | O_RDWR, 777);
        int fdterminal = dup2(fd, 2);
        int fderr = open("/tmp/daemon.err", O_CREAT | O_RDWR, 777);
        int fderrterminal = dup2(fderr, 1);
        int null = open("/tmp/null", O_CREAT | O_RDWR, 777);
        int nullterminal = dup2(null, 0);

        if (execvp(argv[1], argv + 1) == -1)
        {
            printf("Ejercicio7: ERROR No se ha ejecutado el comando %s.\n", argv[1]);
        }
    }
    else
    {
        printf("Proceso Padre: \t\t (%d) padre: %d\n", getpid(), getppid());
    }

    return 0;
}