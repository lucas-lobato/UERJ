#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "exercicio8.h"

VETOR v;

void pegadados(){

    //colocando um vetor inversamente ordenado para comprovar que a ordenação funciona
    for(int i = 0; i <= 49; i++){
        v.vetor[i] = 49 - i;
    }
}

void ordena(){

    int aux = 0;
    bool ordenado = false, troca = false;

    while(ordenado == false){
        troca = false;
        for(int i = 0; i <= 48; i++){
            if(v.vetor[i] > v.vetor[i + 1]){
                aux = v.vetor[i];
                v.vetor[i] = v.vetor[i + 1];
                v.vetor[i + 1] = aux;
                troca = true;
            }
        }

        if(troca == false){
            ordenado = true;
        }
    }
}

void printaresultado(){

    printf("\nMaior elemento:%d",v.vetor[49]);
    printf("\nSegundo maior elemento:%d\n",v.vetor[48]);

}

int main(){

    pegadados();
    ordena();
    printaresultado();

    return 0;
}