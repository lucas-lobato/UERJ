#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int i = 0, j = 0, linha = 0, caracter;
    int x = 0, y = 0;
    char nomearq[32], texto[100][81];
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
        if(i <= 80){
            texto[linha][i] = caracter;
            i++;
        }
        else if(i > 80){
            while(true){
                if(texto[linha][i] == ' '){
                    texto[linha][i] = '\n';
                    break;
                }
                else{
                    i = i - 1;    
                }
            }
            linha++;
            i = 0;
        } 
    }
    fclose(pont_arq);
    texto[linha][i]='\0';
    for(x = 0; x <= linha; x++){
        for(y = 0; y <= 80; y++){
            printf("%c", texto[x][y]);
        }
    }    
    printf("\n");
    return 0;

}