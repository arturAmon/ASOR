#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("ERROR: Introducezca una PID\n");
    return -1;
  }

  int pid = atoi(argv[1]);
  int planificador = sched_getscheduler(pid);

  printf("Planificador: \t");
  switch (planificador)
  {
  case SCHED_OTHER:
    printf("Otro");
    break;
  case SCHED_FIFO:
    printf("FiFo");
    break;
  case SCHED_RR:
    printf("RR");
    break;
  default:
    printf("Desconocido");
    break;
  }

  pritnf("\n");

  //Prioridad
  struct sched_param p;
  sched_getparam(pid, &p);
  printf("Prioridad: %i\n", p.sched_priority);

  //Max y min
  int max = sched_get_priority_max(planificador);
  int min = sched_get_priority_min(planificador);
  printf("Prioridad Maxima: %i \t Prioridad Mínima: %i\n", max, min);
}