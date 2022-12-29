#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int i = 0, caracter, j = 2, k = 2, n = 0;
    char nomearq[20], nomearqenu[20];
    char vet[512];
    printf("Digite o nome do arquivo a ser enumerado:");
    scanf("%s", nomearq);
    FILE *pont_arq;
    pont_arq = fopen(nomearq,"r");
    if (pont_arq == NULL){
        printf("\n\nImpossivel abrir o arquivo!\n\n");
        return 0;
    }
    vet[0] = '1';
    vet[1] = ':';
    while(true){
        caracter = getc(pont_arq);
        if(caracter == EOF){
            break;
        }
        else if(caracter == '\n'){
            vet[j] = '\n';
            vet[j + 1] = k + '0';
            vet[j + 2] = ':';
            k++;
            j = j + 3;
        }
        else{
            vet[j] = caracter;
            j++;
        }
    }
    vet[j - 2] = '\0';
    fclose(pont_arq);
    int l = strlen(vet);
    printf("Digite o nome do arquivo a ser criado:");
    scanf("%s", nomearqenu);
    FILE *pont_arqenu;
    pont_arqenu = fopen(nomearqenu,"w+");
    for(n = 0; n <= l -1; n++){
        putc(vet[n],pont_arqenu);
    }
    printf("%s",vet);
    fclose(pont_arqenu);
    return 0;   
}