#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "exercicio16.h"

DADOS d;

void lancamento(){

    srand (time(NULL));
    d.jogador1dado1 = (rand() % 6) + 1;
    d.jogador1dado2 = (rand() % 6) + 1;
    d.jogador2dado1 = (rand() % 6) + 1;
    d.jogador2dado2 = (rand() % 6) + 1;
}

void rodada(){

    if(d.jogador1dado1 == d.jogador1dado2 && d.jogador2dado1 != d.jogador2dado2){
        d.vitorias_jogador_1++;
        printf("\nRodada %d:",d.rodada);
        printf("\nDados -> jogador 1 (%d - %d) // jogador 2 (%d - %d)",d.jogador1dado1,d.jogador1dado2,d.jogador2dado1,d.jogador2dado2);
        printf("\nO jogador 1 venceu a rodada\n");
    }
    else if(d.jogador1dado1 != d.jogador1dado2 && d.jogador2dado1 == d.jogador2dado2){
        d.vitorias_jogador_2++;
        printf("\nRodada %d:",d.rodada);
        printf("\nDados -> jogador 1 (%d - %d) // jogador 2 (%d - %d)",d.jogador1dado1,d.jogador1dado2,d.jogador2dado1,d.jogador2dado2);
        printf("\nO jogador 2 venceu a rodada\n");
    }
    else if(d.jogador1dado1 == d.jogador1dado2 && d.jogador2dado1 == d.jogador2dado2){
        if(d.jogador1dado1 > d.jogador2dado1){
            d.vitorias_jogador_1++;
            printf("\nRodada %d:",d.rodada);
            printf("\nDados -> jogador 1 (%d - %d) // jogador 2 (%d - %d)",d.jogador1dado1,d.jogador1dado2,d.jogador2dado1,d.jogador2dado2);
            printf("\nO jogador 1 venceu a rodada\n");
        }
        else if(d.jogador1dado1 < d.jogador2dado1){
            printf("\nRodada %d:",d.rodada);
            printf("\nDados -> jogador 1 (%d - %d) // jogador 2 (%d - %d)",d.jogador1dado1,d.jogador1dado2,d.jogador2dado1,d.jogador2dado2);
            printf("\nO jogador 2 venceu a rodada\n");
        }
        else{
            printf("\nRodada %d:",d.rodada);
            printf("\nDados -> jogador 1 (%d - %d) // jogador 2 (%d - %d)",d.jogador1dado1,d.jogador1dado2,d.jogador2dado1,d.jogador2dado2);
            printf("\nOs jogadores empataram nesta rodada\n");
        }
    }
    else if(d.jogador1dado1 != d.jogador1dado2 && d.jogador2dado1 != d.jogador2dado2){
        if(d.jogador1dado1 + d.jogador1dado2 < d.jogador2dado1 + d.jogador2dado2){
            d.vitorias_jogador_2++;
            printf("\nRodada %d:",d.rodada);
            printf("\nDados -> jogador 1 (%d - %d) // jogador 2 (%d - %d)",d.jogador1dado1,d.jogador1dado2,d.jogador2dado1,d.jogador2dado2);
            printf("\nO jogador 2 venceu a rodada\n");
        }
        else if(d.jogador1dado1 + d.jogador1dado2 > d.jogador2dado1 + d.jogador2dado2){
            d.vitorias_jogador_1++;
            printf("\nRodada %d:",d.rodada);
            printf("\nDados -> jogador 1 (%d - %d) // jogador 2 (%d - %d)",d.jogador1dado1,d.jogador1dado2,d.jogador2dado1,d.jogador2dado2);
            printf("\nO jogador 1 venceu a rodada\n");
        }
        else{
            printf("\nRodada %d:",d.rodada);
            printf("\nDados -> jogador 1 (%d - %d) // jogador 2 (%d - %d)",d.jogador1dado1,d.jogador1dado2,d.jogador2dado1,d.jogador2dado2);
            printf("\nOs jogadores empataram nesta rodada\n");
        }
    }
}

void resultado(){

    if(d.vitorias_jogador_1 > d.vitorias_jogador_2){
        printf("\nO jogador 1 venceu o jogo!. Total de rodadas ganhas: %d",d.vitorias_jogador_1);
    }
    else if(d.vitorias_jogador_1 < d.vitorias_jogador_2){
        printf("\nO jogador 2 venceu o jogo!. Total de rodadas ganhas: %d",d.vitorias_jogador_2);
    }
    else{
        printf("\nOs jogadores terminaram o jogo empatados, cada um venceu %d rodadas e empataram %d rodadas",d.vitorias_jogador_1, (11 - d.vitorias_jogador_2));
    }
}

int main(){

    d.vitorias_jogador_1 = 0;
    d.vitorias_jogador_2 = 0;
    d.rodada = 1;
    int aux = 100;

    for(int i = 0; i < 11; i++){
        usleep(aux*10000);
        lancamento();
        rodada();
        d.rodada++;
    }
    printf("\n");
    resultado();
    printf("\n");

    return 0;
}