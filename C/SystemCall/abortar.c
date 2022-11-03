/*
 * abortar.c: Uso de llamada al sistema "abort"
 */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    //exit(EXIT_SUCCESS);
    abort();
    
    printf("Programa en ejecucion\n");
    exit(EXIT_SUCCESS);
}
