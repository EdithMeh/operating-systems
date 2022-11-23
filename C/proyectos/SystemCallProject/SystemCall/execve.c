/*
 * execve.c - Uso execve
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char *argv[] = {"/bin/ps", NULL};
    
    if(execve("/bin/ps", argv, NULL) == -1) {
	perror("execve");
	exit(EXIT_FAILURE);
    }
    
    printf("Seccion no ejecutado");
    
    exit(EXIT_SUCCESS);
}
