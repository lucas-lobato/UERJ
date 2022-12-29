#include <stdio.h>

int main()
{
    int numero;
    int contador;
    printf("Digite um numero:");
    scanf("%i",&numero);
    for(contador=numero-1;contador>=1;contador--)
    {
        numero=numero*contador;
    } 
    printf("o farorial desse numero e:%i",numero);
    printf("\n");
    return 0;
}
