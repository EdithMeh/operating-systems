/*
 * abrirarch.c - Abrir/Cerrar archivos
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char path[] = "/tmp/holamundo.txt";
    
    if((fd = open(path, O_WRONLY, 0644)) < 0) {
	printf("codigo error abrir archivo: %d\n",fd);
	perror("open");
	//exit(EXIT_FAILURE);
    } else
	printf("opened %s\n", path);
    if(close(fd) < 0) {
	perror("close");
	exit(EXIT_FAILURE);
    } else
	printf("closed %s\n", path);
    exit(EXIT_SUCCESS);
}
  
