#include <stdio.h>
#include <stdlib.h>
#include "exercicio6.h"

DADOS d;
DADOSTRATADOS dt;

void pegadados(){

    printf("Digite o número de reabastecimentos: ");
    scanf("%d",&(d.reabastecimentos));

    for(int i = 0; i <= d.reabastecimentos; i++){

        printf("\nDigite a quantidade de gasolina comprada em litros na parada %d:",i);
        scanf("%f", &(d.litrosgasolinacomprados) );
        d.listalitrosgasolinacomprados[i] = d.litrosgasolinacomprados;

        printf("Digite o gasto em reais de gasolina comprada na parada %d:",i);
        scanf("%f", &(d.gastogasolina) );
        d.listagasolina[i] = d.gastogasolina;

        printf("Digite o registro do odometro na parada %d:",i);
        scanf("%f", &(d.kmrodados) );
        d.listakm[i] = d.kmrodados;
    }
}

void tratadadoskmlparcial(){
    for(int i = 0; i <= (d.reabastecimentos) - 1; i++){

        float distancia = d.listakm[i+1] - d.listakm[i];

        dt.kmlparcial[i] = distancia /  d.listalitrosgasolinacomprados[i + 1];

    }
}

void tratadadoskmltotal(){

    float distancia = 0, litros = 0;

    for(int i = 1; i <= (d.reabastecimentos); i++){

        litros = litros + d.listalitrosgasolinacomprados[i];
    }

    for(int i = 0; i <= (d.reabastecimentos) - 1; i++){

        distancia = distancia + ( d.listakm[i+1] - d.listakm[i] );
    }

    dt.kmltotal = distancia / litros;

}

void tratadadoscustototal(){

    float distancia = 0, valor = 0;

    for(int i = 0; i <= (d.reabastecimentos) - 1; i++){

        distancia = distancia + ( d.listakm[i+1] - d.listakm[i] );
    }
    for(int i = 1; i <= (d.reabastecimentos); i++){

        valor = valor + d.listagasolina[i];
    }
    dt.custototal = valor / distancia;
}

int main(){

    pegadados(&d);
    tratadadoskmlparcial(&d,&dt);
    tratadadoskmltotal(&d,&dt);
    tratadadoscustototal(&d,&dt);

    printf("\n");
    for(int i = 0; i <= d.reabastecimentos - 1; i++){
        printf("km/l entre as paradas %d e %d parada: %0.2f\n",i,i+1, dt.kmlparcial[i]);
    }
    printf("km/l total da viagem: %0.2f\n", dt.kmltotal);
    printf("Custo da gasolina por km da viagem: %0.2f\n", dt.custototal);

    return 0;
}