#include <stdio.h>
#include <stdbool.h>

int main(){

    int numero = 0, i = 0;
    bool primo = true;

    printf("Digite um número:");
    scanf("%d",&numero);
    
    for(i = 2; i <= numero - 1; i++){
        if(numero % i == 0){
            printf("%d não é primo\n", numero);
            primo = false;
            break;
        }
    }
    if(primo == true){
        printf("%d é primo\n", numero);
    }

    return 0;
}