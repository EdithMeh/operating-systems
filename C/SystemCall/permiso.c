/*
 * permiso.c - Crear y cambiar permisos a un archivo
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
    mode_t mode = 0777;
    int fd;
    
    /* crear el archivo */
    if((fd = open("empty.file", O_CREAT, 0777)) < 0) {
	perror("open");
	exit(EXIT_FAILURE);
    }
    /* Mostrar detalles archivo */
    system("ls -l empty.file");
    printf("File Descriptor: %d", fd,"\n");
    /* Cambiar permiso */
    if((fchmod(fd, mode)) < 0) {
	perror("fchmod");
	exit(EXIT_FAILURE);
    }
    /* Mostrar permisos nuevamente */
    system("ls -l empty.file");
    exit(EXIT_SUCCESS);
}
