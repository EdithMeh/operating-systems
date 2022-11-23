#include <unistd.h>
#include <stdio.h>

int main(void) {
	char buffer[50];
	// cambiar de directorio
	printf("Cambiar directorio a: 'ejemplo/folder1'\n");
	chdir("ejemplo_folder/folder1");
	// verificar el directorio actual;
	getcwd(buffer, sizeof(buffer));
	printf("Directorio actual de trabajo: \n%s\n", buffer);

	printf("Cambiar directorio a: 'ejemplo/folder2'\n");
    chdir("../f3");
    // verificar el directorio actual;
    getcwd(buffer, sizeof(buffer));
    printf("Directorio actual de trabajo: \n%s\n", buffer);
	return 0;
}
