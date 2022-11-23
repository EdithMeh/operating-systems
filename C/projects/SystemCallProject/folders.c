/* Llamadas al sistema para navegar en el Sistema archivos */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

void listar() {
	// puntero para el directorio padre
	DIR *d;
	// puntero para cada archivo dentro del dir padre
	struct dirent *dir;
	// abrimos padre
	d = opendir(".");
	// si no esta vacio;
	if(d) {
		// para cada archivo dentro el padre
		while((dir = readdir(d)) != NULL) {
			// imprimir nombre de archivo
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}

void cambiarDirectorio(char *folderDestinoPtr) {
    char buffer[50];
	// cambiar de directorio
	printf("Cambiar directorio a: %s\n", folderDestinoPtr);
	chdir(folderDestinoPtr);
}


int main()
{
    char command[100]; 
    do
    {
        // Iniciamos en el directorio de trabajo
        char buffer[500];
        // get current work directory
        getcwd(buffer, sizeof(buffer));
        // mostramos la ruta donde esta ubicado
        printf("Directorio actual de trabajo: \n%s\n", buffer);

        /* 
            equivalente a scanf()
            stdin Entrada estándar
        */
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        /*
        strtok es una funcion parecida al split
        pero guarda esto en "tokens" y ahi hay que trabajarlo con punteros
        */
        char *token = strtok(command, " ");
        printf("%s\n", token);
        if (strcmp(token, "listar") == 0) {
            printf("%s\n", "listando...");
            listar();
        }
        else if (strcmp(token, "cd") == 0) {
            printf("%s\n", "cambiamos de dir");
            token = strtok(NULL, " ");
            printf("%s\n", token);
            cambiarDirectorio(token);

        }
        
    } while (strcmp(command, "salir\n") != 0);

    return 0;
}
