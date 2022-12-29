#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int contador1 = 0, i = 0, j = 0, k = 0 ,linha = 0, caracter;
    char nomearq[32], imagem[1024], intro[256];
    printf("Digite o arquivo a ser analisado:");
    scanf("%s", nomearq);
    FILE *pont_arq;
    pont_arq = fopen(nomearq,"r");
    if(pont_arq == NULL){
        printf("Erro, arquivo vazio\n");
        return 0;
    }
    while(true){
        caracter = getc(pont_arq);

        if(caracter == EOF){
            break;
        }
        if(caracter == '\n'){
            linha++;
        }
        if(linha < 4){
            intro[j] = caracter;
            j++;
        }
        else if(linha > 3){
            imagem[i] = caracter;
            i++;    
        }
    }
    fclose(pont_arq);
    imagem[i]='\0';
    intro[j]='\0';
    printf("%s",intro);
    printf("\n%s",imagem);    
    printf("\n");
    return 0;

}
