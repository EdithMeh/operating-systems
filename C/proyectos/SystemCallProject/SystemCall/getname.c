/*
 * getname.c - Obtener login name
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    char *login;
    
    /* Obtener el login name */
    if((login = getlogin()) == NULL) { 
	perror("getlogin");
	exit(EXIT_FAILURE);
    }
    printf("Cuenta: %s\n", login);
    printf("ID Usuario: %d\n", getuid());
    printf("ID Grupo: %d\n", getgid());
}

