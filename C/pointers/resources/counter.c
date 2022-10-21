/**
Contador del 1 al 10 normal
*/

#include <stdio.h>

int main()
{
    int count = 0;
    while (count < 10) {
        count = count + 1; 
        printf("%d\n", count);
    }
    
    return (0);
}