#include <stdio.h>
#include <stdbool.h>
#include "exercicio13.h"

VETORES v;

void pegavetores(){

    int j = 9;

    for(int i = 0; i <= 9; i++){
        v.vetorum[j - i] = i;
        v.vetordois[j - i] = i;
        v.vetortres[j - i] = i;
    }
}

void ordenavetores(){

    bool ordenado = false;
    bool troca = false;
    int aux = 0;

    while(ordenado == false){
        troca = false;
        for(int i = 0; i <= 8; i++){
            if(v.vetorum[i] > v.vetorum[i + 1]){
                aux = v.vetorum[i];
                v.vetorum[i] = v.vetorum[i + 1];
                v.vetorum[i + 1] = aux;
                troca = true;
            }
        }

        if(troca == false){
            ordenado = true;
        }
    }

    ordenado = false;

    while(ordenado == false){
        troca = false;
        for(int j = 0; j <= 8; j++){
            if(v.vetordois[j] > v.vetordois[j + 1]){
                aux = v.vetorum[j];
                v.vetordois[j] = v.vetordois[j + 1];
                v.vetordois[j + 1] = aux;
                troca = true;
            }
            
        }
        if(troca == false){
            ordenado = true;
        }
    }

    ordenado = false;

    while(ordenado == false){
        troca = false;
        for(int k = 0; k <= 8; k++){
            if(v.vetortres[k] > v.vetortres[k + 1]){
                aux = v.vetortres[k];
                v.vetortres[k] = v.vetortres[k + 1];
                v.vetortres[k + 1] = aux;
                troca = true;
            }
        }
        if(troca == false){
            ordenado = true;
        }
    }

}

void printavetoresordenados(){

    printf("\nVETOR UM:");
    for(int i = 0; i <= 9; i++){
        printf(" %i",v.vetorum[i]);
    }
    printf("\nVETOR DOIS:");
    for(int j = 0; j <= 9; j++){
        printf(" %i",v.vetorum[j]);
    }
    printf("\nVETOR TRES:");
    for(int k = 0; k <= 9; k++){
        printf(" %i",v.vetorum[k]);
    }
    printf("\n");
}

int main(){

    pegavetores();
    ordenavetores();
    printavetoresordenados();

    return 0;
}