#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "exercicio10.h"

TEXTO t;

void pegatexto(){

    FILE *f;
    char c;
    int i = 0;
    int j = 0;

    f = fopen("textoexercicio10.txt","r");
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

void contapalavras(){

    t.contapalavras = 0;
    int aux = 1;

    for(int j = 0; j <= 88; j++){
        int contador = 1;
        char arrayaux[10] = " = ";
        for(int i = j + 1; i <= 88; i++){
            if(strcmp(t.texto[j],t.texto[i]) == 0){
                t.texto[i][0] = 'X';
                t.texto[i][1] = 'X';
                t.texto[i][2] = 'X';
                t.texto[i][3] = 'X';
                t.texto[i][4] = 'X';
                contador++;
            }
        }
        contador = contador + '0';
        arrayaux[3] = contador;
        strcat(t.texto[j],arrayaux);
        contador = 1;
    }
}

void limpatexto(){

    int aux = 0;
    for(int i = 0; i <= 87; i++){
        if(t.texto[i][0] != 'X' && t.texto[i][0] != ' '){
            strcpy(t.textotratado[aux],t.texto[i]);
            aux++;
        }
    }
    t.auxiliar = aux;
}

void printaresultado(){
    
    for(int k = 0; k < t.auxiliar; k++){
        printf("\n%s",t.textotratado[k]);
    }
    printf("\n");
}

int main(){

    pegatexto();
    tratatexto();
    contapalavras();
    limpatexto();
    printaresultado();

    return 0;
}