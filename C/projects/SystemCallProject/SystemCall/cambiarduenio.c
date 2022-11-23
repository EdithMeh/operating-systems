/*
 * chgown.c - Create a file and change its mode
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    uid_t owner = 12;
    gid_t group = 17;
    int fd;
    
    /* create the file */
    if((fd = open("some.txt", O_CREAT, 0644)) < 0) {
	perror("open");
	exit(EXIT_FAILURE);
    }
    /* ls the file */
    system("ls -l some.txt");
    /* change its ownership */
    if((fchown(fd, owner, group)) < 0) {
	perror("fchown");
	exit(EXIT_FAILURE);
    }
    /* ls it again */
    system("ls -l some.txt");
    exit(EXIT_SUCCESS);
}
