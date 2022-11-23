/*
 * abrirarch.c - Abrir/Cerrar archivos
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// SEEK_END Final de archivo.
// SEEK_SET Principio de archivo.
int main(void)
{
    FILE *file;
    char path[] = "bucles.c";
    
    file = fopen(path , "r");
    if(file != NULL) {
        /* con estos tres metodos sacamos la longitud del archivo
         fseek dezplaza el puntero del archivo
         decimos que queremos dezplazar 0 posiciones desde el final del archivo (SEEK_END)
         entonces esto dejaria el puntero al final
        */
        // posiciona el puntero al final
        fseek(file, 0, SEEK_END);
        // ftell cuanta cuantas posiciones dezplazadas tenemos sabiendo la posicion del puntero
        // como nuestro puntero lo dejamos al final del archivo length nos devolvera el total de caracteres que tenemos en el file
        long length = ftell(file);


        // posiciona el puntero al principio de nuevo porque necesitamos leer los datos desde el principio
        fseek(file, 0, SEEK_SET); // rewind(file);
        // Creamos un puntero de caracteres con malloc porque es mas dinamico
        // malloc reserva memoria del tamaño de la longitud del file + 1
        char *buffer = malloc(length + 1);
        buffer[length] = '\0';

        // con fread recien leemos el file y su contenido lo ponemos en el puntero buffer
        fread(buffer, sizeof(char), length, file);
        printf("%s", buffer);

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