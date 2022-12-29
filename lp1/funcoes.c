#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int calculoArea(int x, int y){

    int area = x * y;
    
    return area;
}

int main(void){

    int comprimento = 0;
    int altura = 0;
    printf("Digite um numero:");
    scanf("%i", &comprimento);
    printf("Digite outro numero:");
    scanf("%i", &altura);
    int area = calculoArea(comprimento, altura);
    printf("A area é: %i", area);
    printf("\n");

    return 0;
}
