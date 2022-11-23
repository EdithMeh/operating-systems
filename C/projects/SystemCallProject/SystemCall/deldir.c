/*
 * deldir.c - Delete a directory
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("#Arg: %d\n", argc);
    printf("Argumento(0): %s\n", argv[0]);
    if(rmdir(argv[1])) {
	perror("rmdir");
	exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
