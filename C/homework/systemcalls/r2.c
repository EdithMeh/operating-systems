#include <dirent.h>
#include <stdio.h>

int main(void) {
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
	return 0;
}
