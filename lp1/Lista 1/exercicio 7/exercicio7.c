#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "exercicio7.h"

DADOS d;

void pegadados(){

    for(int i = 0; i < 50; i++){

        printf("\nDigite o nome do aluno: ");
        scanf("%s",(d.nome[i]));
        printf("Digite a nota do aluno: ");
        scanf("%f",&(d.listanotas[i]));
    }
}

void ordena(){

    bool ordenado = false;
    char nome[16];

    while(ordenado == false){
        bool trocou = false;
        for(int i = 0; i < 50; i++){
            if(d.listanotas[i] < d.listanotas[i + 1]){
                int aux = d.listanotas[i];
                strcpy(nome,d.nome[i]);

                d.listanotas[i] = d.listanotas[i + 1];
                strcpy(d.nome[i],d.nome[i + 1]);

                d.listanotas[i + 1] = aux;
                strcpy(d.nome[i + 1],nome);

                trocou = true;
            }
        }
        if(trocou == false){
            ordenado = true;
        }
    }
}

void mediaturma(){

    float soma = 0;
    for(int i = 0; i < 50; i++){
        soma = soma + d.listanotas[i];
    }
    d.media = soma/50;
}

void printa(){

    printf("\nA MEDIA DA TURMA FOI: %0.2f\n", d.media);
    printf("\n5 MELHORES DA TURMA COM NOTA ACIMA DA MEDIA:\n");
    for(int i = 0; i < 5; i++){
        printf("\nNOME: %s --- NOTA: %0.2f", d.nome[i],d.listanotas[i]);
    }
    printf("\n");
    printf("\n****************************************\n");

    printf("\nTURMA COMPLETA E SUAS NOTAS:\n");
    for(int j = 0; j < 50; j++){
        printf("\nNOME: %s --- NOTA: %0.2f", d.nome[j],d.listanotas[j]);
    }
    printf("\n");

}

int main(){

    pegadados();
    ordena();
    mediaturma();
    printa();
    
    return 0;
}