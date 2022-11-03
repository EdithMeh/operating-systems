/*
 * deldir.c - Delete a directory
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(remove(argv[1])) {
	perror("remove");
	exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
