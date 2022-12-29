#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "exercicio11.h"

TEXTO t;

void pegatexto(){

    FILE *f;
    char c;
    int i = 0;
    int j = 0;

    f = fopen("textoexercicio11.txt","r");
    while(c != EOF){
        c =  fgetc(f);
        if(c != EOF && c != ' ' && c != ',' && c != '.' && c != '\n'){
            t.texto[i][j] = c;
            j++;
        }
        else if(c == ' ' || c == '.' || c == ',' || c == '\n'){
            j = 0;
            i++;
        }
    }
    fclose(f);
}

void tratatexto(){

    for(int i = 0; i <= 88; i++){
        for(int j = 0; j <= 20; j++){
            t.texto[i][j] = toupper(t.texto[i][j]);
        }
    }
}

void calculapalavras(){

    int aux = 0;

    for(int i = 0; i <= 88; i++){
        t.contavogais = 0;
        for(int j = 0; j <= strlen(t.texto[i]); j++){
            if(t.texto[i][j] == 'A' || t.texto[i][j] == 'E' || t.texto[i][j] == 'I' || t.texto[i][j] == 'O' || t.texto[i][j] == 'U'){
                t.contavogais++;
            }
        }
        if(t.contavogais > 2){
            strcpy(t.textotratado[aux],t.texto[i]);
            aux++;
        }
    }
}

void printaresultado(){

    for(int j = 0; j <= 34; j++){
        printf("\nLINHA: %s",t.textotratado[j]);
    }
    printf("\n");
}

int main(){

    pegatexto();
    tratatexto();
    calculapalavras();
    printaresultado();

    return 0;
}