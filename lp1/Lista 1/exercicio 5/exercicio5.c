#include <stdio.h>

int main(){

    int soma = 0, valor = 0, aux = 0, i = 0;
    float valorf = 0, valorf2 = 0, troco[32] = {};

    printf("Digite o valor: ");
    scanf("%f",&valorf);
    if(valorf > 1.0 || valorf < 0.0){
        printf("Valor inválido, tente outro\n");
        return main();
    }
    valorf = valorf * 100;
    valor = (int)valorf;

    while(valor != soma){
        if(soma + 100 == valor){
            troco[aux] = 1.0;
            soma = soma + 100;
            aux = aux + 1;
        }
        else if((soma + 100 > valor) && (soma + 50 <= valor)){
            troco[aux] = 0.50;
            soma = soma + 50;
            aux = aux + 1;
        }
        else if((soma + 50 > valor) && (soma + 25 <= valor)){
            troco[aux] = 0.25;
            soma = soma + 25;
            aux = aux + 1;
        }
        else if((soma + 25 > valor) && (soma + 10 <= valor)){
            troco[aux] = 0.10;
            soma = soma + 10;
            aux = aux + 1;
        }
        else if((soma + 10 > valor) && (soma + 5 <= valor)){
            troco[aux] = 0.05;
            soma = soma + 5;
            aux = aux + 1;
        }
        else{
            troco[aux] = 0.01;
            soma = soma + 1;
            aux = aux + 1;
        }
    }
    troco[aux] = '\0';
    valorf2 = (float)valor/100;
    printf("\nValor %0.2f em moedas:\n",valorf2);
    for(i = 0; i <= aux - 1; i++){
        printf("%0.2f\n",troco[i]);
    }
    return 0;
}