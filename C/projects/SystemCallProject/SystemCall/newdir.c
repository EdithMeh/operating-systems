/*
 * newdir.c - Create a directory
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
     if(mkdir(argv[1], 0755)) {
	  perror("mkdir");
	  exit(EXIT_FAILURE);
     }
     exit(EXIT_SUCCESS);
}
