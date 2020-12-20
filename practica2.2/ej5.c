#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

	const char PATH[] = "./ej5.practica";
	int desc_fichero = open(PATH, O_CREAT, 0645);
	return 0;
}

/*
-rw-r--r-x 1 cursoredes cursoredes    0 Dec 20 16:24 ej5.practica
*/