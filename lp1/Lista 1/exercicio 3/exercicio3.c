#include <stdio.h>
#include <stdbool.h>

int main(){

    int n = 0, limite = 32767, i = 0;

    printf("1 é um inteiro perfeito\n");

    for(n = 1; n <= limite; n++){

        int divisores[32767] = {}, aux = 0, soma = 0;

        for(i = 1; i <= n -1; i++){
            if(n % i == 0){
                divisores[aux] = i;
                aux = aux + 1;
            }
        }
        divisores[aux] = '\0';

        for(i = 0; i <= aux - 1; i++){
            soma = soma + divisores[i];
        }

        if(soma == n){
            printf("%d é um inteiro perfeito\n", n);
        }
    }

    return 0;
}