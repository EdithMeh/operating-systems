#include <stdio.h>
#include <unistd.h>

int main(void) {
	char buffer[500];
	getcwd(buffer, sizeof(buffer));
	printf("Directorio actual de trabajo: \n%s\n", buffer);
	return 0;
}
