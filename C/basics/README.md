# Lenguaje C

Programación estructurada

[Clion](https://www.jetbrains.com/es-es/clion/)

[Compilador de C online](https://www.onlinegdb.com/online_c_compiler)

[Github student](https://education.github.com/pack)

# Comandos importantes

para compilar

> gcc {fileName}.c -o {output_fileName} && ./{output_fileName}

> gcc {fileName}.c -o {output_fileName} | ./{output_fileName}

para mostrar advertencias -W

> gcc -Wall {fileName}.c -o {output_fileName}

medir el tiempo en el que tarda al ejecutar

> time ./{output_fileName}

Cambiar idioma del teclado

> setxkbmap us

# Estructura de un programa en C

``` C
/*
Zona donde se incluyen las librerias
(Preprocessors Comands).
*/
#include <stdio.h> 

int main()  //Funcion principal, aqui es donde inicia la ejecución del programa
{
    /*First hello world in C language*/
    printf("Hola Mundo");
    return 0; //=> return 0 termina la funcion.
}
```

## Preprocessors Comands
Todas las directivas comienzan siempre por el símbolo #.

Algunas de las mas importantes:
- `#include`: inclusión de ficheros.
- `#define`: Creación de constantes simbólicas.
- `#undef`: Eliminación de constantes simbólicas.
- `#if (#else, #enif)`: inclusión condicional del código.

## Basic types

| Type  | Bytes | Range |
| ------------- | ------------- | ------------- | 
| `char`  | 1 Bytes  | -128 to 127 (**unicodes**) |
| `unsigned char`  | 1 Bytes *  | 0 to 255 |
| `int`  | 2 Bytes  | -32,768 to 32,757  |
| `int`  | 4 Bytes*  | -2,147,483,648 to 2,147,483,647  |
| `unsigned int`  | 2 Bytes  | 0 to 65.535  |
| `unsigned int`  | 4 Bytes*  | 0 to 4,294,967,295 |
| `short`  | 2 Bytes  | -32,768 to 32,767 |
| `unsigned short`  | 2 Bytes  | 0 to 65,535 |
| `long`  | 8 Bytes  | -9223372036854775808 to 9223372036854775807 |
| `unsigned long`  | 8 Bytes  | 0 to 18446744073709551615 |
| `float`  | 4 Bytes  | 1.2E-38 to 3.4E+38 (**6 decimal places**)  |
| `double`  | 8 Bytes  | 2.3E-308 to 1.7E+308 (**15 decimal places**)  |
| `long double`  | 10 Bytes  | 3.4E-4932 to 1.1E+4932 (**19 decimal places**)  |

[Type field characters](https://learn.microsoft.com/es-es/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170&viewFallbackFrom=vs-2019#type-field-characters)

### void
Es una palabra reservada de no atribución, la cuál no retorna valores.
The type specifier void indicates that no value is available.

**Función que no retorna ningun valor**
``` C
void funcion() {}
```
    
**Función que recibe argumentos como tipo void**

Función con argumentos/parametros vacios, este tipo de funciones puede aceptar un tipo void
``` C
int funcion(void) {}
```

**Punteros**

Puntero o apuntador. Va a la dirección de un objeto pero no le importa el tipo de dato que tenga el objeto. (Y se puede hacer un cast a cualquier otro tipo de dato).

``` C
void *malloc( size_t size );
``` 

### Enums
Es un tipo de dato que asigna valores a una lista de constantes 

``` C
#include <stdio.h>

enum weekDays
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main()
{
    enum weekDays today;
    today = Wednesday;
    printf("Day %d", today + 1);
    return 0;
}
``` 

### Struct

Este tipo de dato agrupa campos de otros tipos de datos

``` C
#define NAME_SIZE 100
#define LAST_SIZE 200

/* Definición de la estructura */
struct user 
{
    char firstname[NAME_SIZE];
    char lastname[LAST_SIZE];
    unsigned int phone;
};

/* Declaración de variables con esta estructura */
struct user user1, user2, contacts[10];
```

`strcpy` or `memcpy`

### Unions
Es como una estructura en la que todos los campos comparten el mismo espacio de memoria. Pero solo uno de eso campos se utiliza. Entonces reserva el espacio definido en el mayor de los campos.

``` C
union Data {
   int i;
   float f;
   char str[20];
}
```

![Figure 0.1](images/data-types-hierarchy.png)


# Bucles
`break`: termina el ciclo.

`continue`: salta una iteracion del ciclo.

## while - do while

``` C
#include <stdio.h>

const int TOTAL = 10;

int	main (void)
{
	int i = 1;
	while ( i <= TOTAL)
	{
		printf ("\n number %d", i);
		i++;
	}
	return (0);
}
```

## for
``` C
#include <stdio.h>

int main()
{
    int n = 30;
    for(int i=0; i < n; i++)
        printf("number %d\n",i );

    return 0;
}
```

# Variables y contantes

``` C
#define SIZE 6
char letra = 77;
char b[SIZE] = "hello";
const char LETRA = 77;
``` 

# Define

Cuando se usa el Define lo que ocurre es que antes de compilar, el preprocesador reemplaza en el código todas las ocurrencias del nombre que definimos por su valor, es decir, esos valores pasan a ser parte del programa y no van a ocupar memoria RAM.

**Diferencia con una constante** 

En un **const** global la información se guarda en un espacio de memoria de solo lectura y es accesible desde cualquier parte del código.

*Declarar valores globales es una mala practica*

``` C
#include <stdio.h>

#define COST 5.1
#define p printf

const char NEWLINE = '\n';

int main()
{
    float numberOfProducts = 2;
    float total = COST * numberOfProducts;
    p("Total: %c %f", NEWLINE, total);
    return 0;
}
``` 

Otro uso del define es para anotar internamente si un simbolo esta definido
``` C
#include <stdio.h>

#define TEST

int main()
{
    #ifdef TEST
        printf("Test environment");
    #else
        printf("Prod environment");
    #endif
    return 0;
}
``` 

El uso del `#define` es lo mismo que usar `-D` en la consola.
Ejemplo:
> -DNUM = 100

``` C
#define NUM 100
``` 

> -DTEST

``` C
#define TEST
``` 

- Pueden crear un file solo para guardar "definiciones" un file .h
- Tener cuidado al nombrarlos porque el reemplazo tambien incluye a los peroprocesor commands

``` C
#include <stdio.h>
#define TEST 500
#define OTRO_TEST TEST

int main() 
{
    printf("%d\n", OTRO_TEST);
}
``` 

# ifdef, else y endif
#ifdef, #else y #endif

Podemos decir que eliminamos el bloque de código de la condición que no se cumple y el compilador solo recibe el bloque de código que cumplió la condición. Por esta razón el compilador ignora si existe o no errores en el código eliminado.

# Uso de #define como "macro"

El reemplazo que hace el preprocesador puede incluir parametros.

``` C
#include <stdio.h>
#define LESS_THAN_TEN(v) (v < 10)

int main() {
    int i = 5;
    if (LESS_THAN_TEN(i))
    { 
      printf("Number less than 10");
    }
}
``` 

# Librerias
[C libraries](https://devdocs.io/c/)

## stdio

``` C
#include <stdio.h>
```

[documentacion](https://cplusplus.com/reference/cstdio/)

Manejo de entradas y salidas estandares.

`printf`	Print formatted data to stdout [function](https://cplusplus.com/reference/cstdio/printf/)

`scanf` Recive un valor de entrada
``` C
scanf("%d", &x);
```

## ncurses

``` C
#include <curses.h>
```

Compile using -lncurses

> gcc {fileName}.c -o {output_fileName} -lncurses && ./{output_fileName}

> gcc {fileName}.c -o {output_fileName} -lncurses | ./{output_fileName}

Interfaces

`initscr()` It allocates memory for present window which is called stdscr.

## stdlib

[documentation](https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm)

``` C
#include <stdlib.h>
```

## math

> gcc {fileName}.c -o {output_fileName} -lm && ./{output_fileName}

[documentation](https://www.tutorialspoint.com/c_standard_library/math_h.htm)

``` C
#include <math.h>
```

## string

[documentation](https://www.tutorialspoint.com/c_standard_library/string_h.htm)

``` C
#include <string.h>
```

``` C
#include <stdio.h>
#include <string.h>

int main()
{
    char string1[60];
    char string2[60];
    printf("First string\n");
    scanf("%59s", string1);
    printf("Second string\n");
    scanf("%59s", string2);
    
    if (strcmp(string1, string2) == 0) {
        printf("Identicos\n");
    }
    
    strcat(string1, string2);
    printf("concat> %s\n", string1);   

    return 0;
}
```

