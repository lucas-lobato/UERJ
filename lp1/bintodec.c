#include <stdio.h>
#include <math.h>

int main()
{
    int bin , j=10 , binario = 0, i ,resto=1 , potenc , k;
    printf("Digite o numero em binario:");
    scanf("%i", &bin);
    while(resto > 0){
        binario = binario + i;
        resto = bin % j;
        k = pow(2,potenc);
        i = resto * k;
        potenc++;
        j = j * 10;
    }
    printf("%d",binario);
    printf("\n");
    return 0;
}