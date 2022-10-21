/**
Contador del 1 al 10 con punteros y funcion que recibe puntero
*/ 

#include <stdio.h>

//el parametro de entrada declara que recibira un puntero
void incrementa_count(int *count_ptr)
{
    // tiene la direccion que nos enviaron
    // count_ptr = 1000
    // *count_ptr = 0,1,3....
    *count_ptr = *count_ptr + 1;
}

int main()
{
    //declarado variable y el puntero
    // 1000
    int count = 0; /* number of times through */
    int *count_ptr;
    
    // count_ptr va a apuntar a la direccion de la variable count 
    // count_ptr = 1000
    count_ptr = &count;
    while (count < 10) {
        // incrementa_count(1000)
        incrementa_count(count_ptr);
        printf("%d\n", count);
    }
    
    return (0);
}