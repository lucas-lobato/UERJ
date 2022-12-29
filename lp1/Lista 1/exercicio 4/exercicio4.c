#include <stdio.h>

int main(){

    int numero = 0, i = 0, fatorial = 1;

    printf("\nDigite um numero: ");
    scanf("%d",&numero);
    if(numero < 0){
        printf("\nErro, é permitido apenas numeros inteiros positivos...\n");
        return main();
    }

    for(i = 1; i <= numero; i++){
        fatorial = fatorial * i;
    }

    printf("O fatorial de %d é %d\n", numero, fatorial);

    return 0;
}