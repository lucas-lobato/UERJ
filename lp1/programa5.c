//Tamanho de cada variavel

#include <stdio.h>

int main()
{   

    printf("Char: %lu bytes\n", sizeof(char));
    printf("short %lu bytes\n", sizeof(short));
    printf("Int: %lu bytes\n", sizeof(int));
    printf("Long: %lu bytes\n", sizeof(long));
    printf("Long Long: %lu bytes\n", sizeof(long long));
    printf("Float: %lu bytes\n", sizeof(float));
    printf("Double: %lu bytes\n", sizeof(double));
    printf("Long Double: %lu bytes\n", sizeof(long double));
    
    return 0;
}
