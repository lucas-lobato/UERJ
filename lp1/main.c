#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arquivo1.h"
int main(void)
{
    int i = 0, linhas = 0, imprimiveis = 0, total = 0, caracter;
    char nomearq[20];
    printf("Digite o nome do arquivo a ser analisado:");
    scanf("%s", nomearq);
    FILE *pont_arq;
    pont_arq = fopen(nomearq,"r");
    if (pont_arq == NULL){
        printf("\n\nImpossivel abrir o arquivo!\n\n");
        return 0;
    }
    while(caracter != EOF){
        caracter = getc(pont_arq);
        if(caracter == '\n'){
            linhas = linhas + 1;
        }
        else if(caracter != ' ' && caracter != '\n'){
            imprimiveis = imprimiveis + 1;
        }
    }
    fclose(pont_arq);
    total = imprimiveis + linhas;
    printar(total, linhas, imprimiveis);
    return 0;   
}
