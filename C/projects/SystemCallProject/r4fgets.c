#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    FILE *file;
    char path[] = "define.c";
    
    file = fopen(path , "r");
    if(file != NULL) {
        char ch;
        do {
            ch = fgetc(file);
            printf("%c", ch);
            // si es EOF dejar de leer
        } while (ch != EOF); // /0
        //} while (!feof(file)); // otra opcion

        if(fclose(file) < 0) {
            perror("close");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("codigo error abrir archivo: %d\n", file);
        perror("open");
    }
    exit(EXIT_SUCCESS);
}