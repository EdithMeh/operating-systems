/*
 * msgerror.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    FILE *pfile;
    
    if((pfile = fopen("foobar", "r")) == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    } else {
        printf("como ocurrio esto!\n");
        fclose(pfile);
    }

    exit(EXIT_SUCCESS);
}
