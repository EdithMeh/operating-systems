/* Llamadas al sistema para navegar en el Sistema archivos
Version Cleaned
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

void listar() {
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if(d) {
		while((dir = readdir(d)) != NULL) {
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}

void cambiarDirectorio(char *folderDestinoPtr) {
	int exist = chdir(folderDestinoPtr);
    if (exist != 0) {
        perror("Error");
    }
}

void verFile(char *pathFile) {
	FILE *file;
    file = fopen(pathFile , "r");
    if(file != NULL) {
        char character;
        do {
            character = fgetc(file);
            printf("%c", character);
        //} while (character != EOF);
        } while (!feof(file));

        if(fclose(file) < 0) {
            perror("Error");
        }
    } else {
        perror("Error");
    }
}

int main()
{
    char comando[100];
    char directorioActual[500];
    char *parametro;
    do
    {
        getcwd(directorioActual, sizeof(directorioActual));
        printf("\n%s -> ", directorioActual);

        fgets(comando, sizeof(comando), stdin);
        comando[strlen(comando) - 1] = '\0';

        char *accion = strtok(comando, " ");
        if (strcmp(accion, "listar") == 0) {
            if (strtok(NULL, " ") == NULL) {
                listar();
            } else {
                printf("Error: Este comando no acepta parametros.");
            }
        }
        else if (strcmp(accion, "cd") == 0) {
            parametro = strtok(NULL, " ");
            if (parametro != NULL) { // folder1
                if (strtok(NULL, " ") == NULL) {
                    cambiarDirectorio(parametro);
                } else {
                    printf("Error: Este comando solo acepta un parametro.");
                }
            } else {
                printf("Error: Este comando necesita un parametro.");
            }
            
        }
        else if (strcmp(accion, "ver") == 0) {
            parametro = strtok(NULL, " ");
            if (parametro != NULL) {
                if (strtok(NULL, " ") == NULL) {
                verFile(parametro);
                } else {
                    printf("Error: Este comando solo acepta un parametro.");
                }
            } else {
                printf("Error: Este comando necesita un parametro.");
            }
            
        } else if (strcmp(comando, "salir") != 0) {
            printf("Error: Comando invalido");
        } 
    } while (strcmp(comando, "salir") != 0);

    return 0;
}