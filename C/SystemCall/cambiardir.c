/*
 * chdir.c - Change to a new directory
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{

    if (argc > 1)
    {
	if(chdir(argv[1]) < 0) {
	    perror("chdir");
	    exit(EXIT_FAILURE);
	}
	system("ls");
    }
    else {
	    printf("Necesito argumento\n");
	 }
    exit(EXIT_SUCCESS);
}
