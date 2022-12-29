#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "exercicio15.h"

DAODS d;

void pegadados(){

    FILE* f;
    f = fopen("dados.txt","r");

    char c;
    int contador = 0;
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;

    while(c != EOF){

        c = getc(f);
        if(c == '\0' || c == EOF){
            break;
        }
        if(contador == 0){
            num1 = c - '0';
        }
        if(contador == 1){
            num2 = c - '0';
        }
        if(contador == 2){
            num3 = c - '0';
        }
        if(contador == 3){
            num4 = c - '0';
            d.listanascimento[aux3] = (num1 * 1000) + (num2 * 100) + (num3 * 10) + (num4 * 1);
            aux3++;
        }
        if(contador == 5){
            d.listasexo[aux] = c;
            aux++;
        }
        if(contador == 7){
            d.listaprocedencia[aux2] = c;
            aux2++;
            contador = -2;
        }
        contador++;
    }
    fclose(f);
}

void porcentagem_menos_de_21(){

    int soma = 0;

    for(int i = 0; i < 32; i++){
        if(2020 - d.listanascimento[i] < 22){
            soma = soma + 1;
        }
    }
    d.porcentagemmenos21 = (soma * 100) / 32;
}

void mulheres_capital(){

    int soma = 0;

    for(int i = 0; i < 32; i++){
        if(d.listasexo[i] == 'F' && d.listaprocedencia[i] == '0'){
            soma++;
        }
    }
    d.mulherescapital = soma;
}

void mais_de_60_interior(){

    int soma = 0;

    for(int i = 0; i < 32; i++){
        if(2020 - d.listanascimento[i] > 60 && d.listaprocedencia[i] == '1'){
            soma = soma + 1;
        }
    }
    d.interiormaisde60 = soma;
}

void mulher_mais_de_60(){

    bool existe = false;

    for(int i = 0; i < 32; i++){
        if(2020 - d.listanascimento[i] > 60 && d.listasexo[i] == 'F'){
            existe = true;
        }
    }
    if(existe = true){
        d.mulhermaisde60 = true;
    }
    else{
        d.mulhermaisde60 = false;
    }
}

void printaresultado(){

    printf("\nPorcentagem de motoristas com menos de 21 anos: %d%%", d.porcentagemmenos21);
    printf("\nQuantidade de mulheres da capital: %d", d.mulherescapital);
    printf("\nMotoristas do interior do estado com idade maior que 60 anos: %d",d.interiormaisde60);
    printf("\nExiste mulher com idade maior que 60 anos ?:");
    if(d.mulhermaisde60 == true){
        printf(" Sim");
    }
    else{
        printf(" Não");
    }
    printf("\n");
}

int main(){

    pegadados();
    porcentagem_menos_de_21();
    mulheres_capital();
    mais_de_60_interior();
    mulher_mais_de_60();
    printaresultado();

    return 0;
}