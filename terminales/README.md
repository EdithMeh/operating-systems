# Interfaz de línea de comandos

- No es exclusiva de linux.
- Se escriben comandos en una consola.
- Los comandos se ejecutan.
- Facilita el trabajo.
- Se pueden automatizar tareas fácilmente.

# Linux Shell
- Intérprete de comandos para el sistema.
- En linux, normalmente, se utiliza BASH.
- Una TERMINAL es un programa que permite interactuar con el SHELL.

Para abrir una terminal:
> CTRL + ALT + T


# Comandos básicos 

Normalmente los comandos siguen un formato estándar:
> [comando] -[opciones] [argumentos]

## Navegación

- pwd - Imprime directorio actual.
- cd - cambia de directorio.
- ls - lista archivos y subdirectorios.

## Crear y editar archivos
- touch: crea un archivo.
- nano: es un editor de texto que se ejecuta en la terminal.
- cat: muestra el contenido de un archivo.

## Edición de archivos de texto

- Se usa el programa nano para editar archivos desde la terminal de forma
sencilla.
- Para editar o crear un archivo se usa el siguiente comando:
> nano [nombre del archivo]
- Se puede instalar el programa con el siguiente comando:
> sudo apt install nano

## Archivos ejecutables
- Los archivos ejecutables necesitan obtener permisos para poder ejecutarse por el sistema.
- Para brindar permisos de ejecución se usa el comando chmod:
> chmod +x [nombre del archivo]

## Permisos de archivos
- Además de poder ejecutarse, se puede cambiar los permisos de los archivos
para lectura y escritura usando el mismo comando.
- r=lectura ; w=escritura ; x=ejecución.
- Para añadir permisos se usa chmod +[permisos] [archivo]
- Para quitar permisos se usa chmod -[permisos] [archivo]
- También se puede usar una codificación octal para definir los permisos.
> chmod [codigo] [archivo]

![Figure 0.1](images/permisos.png)

## Diferencias entre LESS, CAT, HEAD y TAIL para lectura de archivos

- cat Recomendado para leer archivos pequeños.
- less Recomendado para leer archivos largos.
- tail Muestra las ultimas 10 lineas de un archivo.
- head Muestra las primeras 10 lineas de un archivo

## Procesos
`ps` muestra los procesos que están corriendo en el sistema. 

`ps aux` muestra **todos** los procesos que están corriendo en el sistema.

pipe operator |  para concatenar instrucciones

ps aux | grep something

## Verificar procesos en el sistema operativo

`top`: muestra información específica del sistema informativo 

`free`: muestra la información de la memoria que se está consumiendo 

`free -h`: con el modificador `-h` muestra la información en un formato más fácil de leer. 

`du`: muestra el uso del disco duro 

`du -hsc`: con el modificador `-hsc` general un total de cada peso. 

Conocer los procesos que más consumen recursos en el sistema operativo `sudo ps auxf | sort -nr - k 3 | head -5`, para conocer con exactitud los modificadores que podemos agregar podemos llamar al comando `man sort`

Para conocer los procesos que consumen más RAM cambiamos `k 3` por `k 4` 

`htop` : un paquete con mejor administración.