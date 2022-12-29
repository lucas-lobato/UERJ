#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "exercicio9.h"

TEXTO t;

void pegatexto(){

    FILE *f;
    char c;

    f = fopen("textoexercicio9.txt","r");
    for(int i = 0; i <= 6; i ++){
        for(int j = 0; j <= 79; j++){
            c =  fgetc(f);
            if(c != EOF && c != '\n'){
                t.texto[i][j] = c;
            }
            if(c == '\n'){
                j = 80;
            }
        }
    }
    fclose(f);
    
}

void contador(){

    t.contaletras = 0;

    int  conta = 0;
    int  contb = 0;
    int  contc = 0;
    int  contd = 0;
    int  conte = 0;
    int  contf = 0;
    int  contg = 0;
    int  conth = 0;
    int  conti = 0;
    int  contj = 0;
    int  contk = 0;
    int  contl = 0;
    int  contm = 0;
    int  contn = 0;
    int  conto = 0;
    int  contp = 0;
    int  contq = 0;
    int  contr = 0;
    int  conts = 0;
    int  contt = 0;
    int  contu = 0;
    int  contv = 0;
    int  contw = 0;
    int  contx = 0;
    int  conty = 0;
    int  contz = 0;
   

    for(int i = 0; i <= 6; i++){
        for(int j = 0; j <= 79; j++){
            t.texto[i][j] = toupper(t.texto[i][j]);
        }
    }

    for(int k = 0; k <= 6; k++){
        for(int l = 0; l <= 79; l++){
            switch (t.texto[k][l])
            {
            case 'A':
                conta = 2;
                break;
            case 'B':
                contb = 2;
                break;
            case 'C':
                contc = 2;
                break;
            case 'D':
                contd = 2;
                break;
            case 'E':
                conte = 2;
                break;
            case 'F':
                contf = 2;
                break;
            case 'G':
                contg = 2;
                break;
            case 'H':
                conth = 2;
                break;
            case 'I':
                conti = 2;
                break;
            case 'J':
                contj = 2;
                break;
            case 'K':
                contk = 2;
                break;
            case 'L':
                contl = 2;
                break;
            case 'M':
                contm = 2;
                break;
            case 'N':
                contn = 2;
                break;
            case 'O':
                conto = 2;
                break;
            case 'P':
                contp = 2;
                break;
            case 'Q':
                contq = 2;
                break;
            case 'R':
                contr = 2;
                break;
            case 'S':
                conts = 2;
                break;
            case 'T':
                contt = 2;
                break;
            case 'U':
                contu = 2;
                break;
            case 'V':
                contv = 2;
                break;
            case 'W':
                contw = 2;
                break;
            case 'X':
                contx = 2;
                break;
            case 'Y':
                conty = 2;
                break;
            case 'Z':
                contz = 2;
                break;

            }
        }
        
       
    }
    t.contaletras = conta + contb + contc + contd + conte + contf + contg + conth + conti + contj + contk + contl;
    t.contaletras = t.contaletras + contm + contn + conto + contp + contq + contr + conts + contt + contu + contv;
    t.contaletras = t.contaletras + contx + conty + contz + contw;
}

void printaresultado(){
    printf("\nO número de caracteres diferentes no texto é: %d\n",(t.contaletras / 2));
    printf("\n");
}

int main(){

    pegatexto();
    contador();
    printaresultado();

    return 0;
}