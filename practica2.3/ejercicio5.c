#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <linux/limits.h>

void main()
{

    printf("PID: \t\t\t%d\n", getpid());
    printf("PPID: \t\t\t%d\n", getpid());
    printf("Grupo de procesos: \t%d\n", getpgid(getpid()));
    printf("ID se session: \t\t%d\n", getsid(getpid()));

    struct rlimit limit;
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1)
    {
        perror("Ejercicio5: error al acceder a limit\n");
        return;
    }
    printf("Num. max. de ficheros: \t %d\n", limit.rlim_max);

    char *path = malloc((PATH_MAX + 1) * sizeof(char));
    getcwd(path, PATH_MAX + 1);
    printf("Directorio actual: \t %s\n", path);
    free(path);
    return;
}