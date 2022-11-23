#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    // creamos un nuevo proceso
	int pid = fork();
    int shared = 2;
    int status;
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // verificamos si es el proceso padre o el proceso hijo
	if (pid > 0) {
        shared = 1;
		printf("Proceso padre. PID padre:  %d   PID hijo: %d\n", getpid(), pid);
        printf("Variable en padre:  %d\n", shared);
        
        // esperamos hasta que todos los hijos terminen
		// wait(NULL);
        waitpid(pid, &status, 0);
		printf( "Proceso padre de nuevo \n" );
        printf("Variable en padre de nuevo:  %d\n", shared);
	} else {
        shared = 0;
		printf( "Proceso hijo, PID hijo:  %d Confirmamos que el pid es cero: %d\n", getpid(), pid);
        // sleep agragado solo para ver la ejecucion
		sleep(2);
        printf("Variable en hijo:  %d\n", shared);
	}

	return 0;
}