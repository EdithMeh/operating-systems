# Paralelismo

## Fork

Dentro del sistema opertivo cadas proceso se identifica con un número único que es el Process ID (pid).

`fork()` Crea un nuevo proceso suplicando el que estamos ejecutando y devuelve el ID del proceso hijo, si la función `fork()` devuelve un número mayor que 0 si se esta ejecutando el proceso padre por el contrario si devuelve 0 esta ejecuntanto el proceso hijo. 

En resumen

- `-1:` Imposible crear el fork.
- `0:` Se ha creado el fork, pero estamos en el proceso hijo.
- `Mayor a 0:` Se ha creado el fork, estamos en el proceso padre y nos ha devuelto el PID del hijo.

``` C
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{ 
    fork();
  
    printf("Hello world!\n");
    return 0;
}
```

Es común que el proceso padre necesite que todos sus hijos hayan terminado su ejecución para continuar su propia ejecución en esos casos utilizamos la función `wait()` 

[fork documentation](https://manpages.ubuntu.com/manpages/bionic/es/man2/fork.2.html)

[wait documentation](https://manpages.ubuntu.com/manpages/bionic/es/man2/wait.2.html)

Las variables definidas no se comparten cada proceso tiene su propia versión. Si queremos comaprtir información entre procesos tenemos que usar `pipe`

## Pipes

Es un metodo de comunicación entre el proceso padre y el proceso hijo. 

![Figure 0.1](images/pipe.png)

Para las pipes se debe definir un array de tipo entero de dos posiciones.[la posición «0» a modo de lectura y la posición «1» a modo de escritura].

Las pipes «solo» tienen un sentido, si queremos hablar del padre al hijo, no podremos usar esa misma pipe para hablar del hijo al padre, para ello necesitamos crear otra pipe.

