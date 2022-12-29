#include <stdio.h>
#include <stdbool.h>

int main(){

    int numero = 0, i = 0;
    bool resultado = false;

    while(resultado == false){
        numero = numero + 1;
        if(numero % 3 == 2 && numero % 5 == 3 && numero % 7 == 4){
            resultado = true;
            printf("\n%d\n", numero);
        }
    } 
    return 0;
}