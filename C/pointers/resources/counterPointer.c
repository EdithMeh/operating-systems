/**
Contador del 1 al 10 con punteros
*/

#include <stdio.h>

int main()
{
    int count = 0;
    int *count_ptr;
    while (count < 10) {
        count_ptr = &count;
        *count_ptr = *count_ptr + 1;
        printf("%d\n", count);
    }
    
    return (0);
}