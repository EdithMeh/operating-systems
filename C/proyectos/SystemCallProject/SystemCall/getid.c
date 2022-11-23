/*
 *  * getid.c - Obtener uid y gid
 *   */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    printf("ID Usuario: %d\n", getuid());
    printf("ID Grupo: %d\n", getgid());
}
