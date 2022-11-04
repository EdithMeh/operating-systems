/*
 * abrirarch.c - Abrir/Cerrar archivos
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    FILE *file;
    char path[] = "bucles.c";
    //char buffer[500];
    
    file = fopen(path , "rb");
    if(file != NULL) {
|       char* wholeFile;
        long fileSize;

        /* con estos tres metodos sacamos la longitud del archivo
         fseek dezplaza el puntero del archivo
         decimos que queremos dezplazar 0 posiciones desde el final del archivo (SEEK_END)
         entonces esto dejaria el puntero al final
        */
        // posiciona el puntero al final
        fseek(file, 0, SEEK_END); 
        // ftell cuanta cuantas posiciones dezplazadas tenemos sabiendo la posicion del puntero
        // como nuestro puntero lo dejamos al final del archivo length nos devolvera el total de caracteres que tenemos en el file
        fileSize = ftell(file);
        // posiciona el puntero al principio de nuevo porque necesitamos leer los datos desde el principio
        rewind(file); // fseek(file, 0, SEEK_SET);

        // Creamos un puntero de caracteres con malloc porque es mas dinamico
        // malloc reserva memoria del tamaño de la longitud del file + 1
        wholeFile = (char*)malloc(fileSize + 1);
        wholeFile[fileSize] = '\0';

        // con fread recien leemos el file y su contenido lo ponemos en el puntero buffer
        fread(wholeFile, sizeof(char), fileSize, file);
        printf(wholeFile);

        // libera la memoria que habiamos reservado con malloc
        free(wholeFile);
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