#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

    mode_t prev = umask(027); // 027

	const char PATH[] = "./ej7.practica";
	int desc_fichero = open(PATH, O_CREAT, 0645);
	return 0;
}