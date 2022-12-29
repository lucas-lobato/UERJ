#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "exercicio12.h"

NUMERO n;

void peganumero(){

    char aux[6];
    printf("Digite um numero de 0 a 9.999: ");
    fgets(aux,6,stdin);
    if(strlen(aux) == 2){
        n.numero[3] = aux[0];
    }
    else if(strlen(aux) == 3){
        n.numero[2] = aux[0];
        n.numero[3] = aux[1];
    }
    else if(strlen(aux) == 4){
        n.numero[1] = aux[0];
        n.numero[2] = aux[1];
        n.numero[3] = aux[2];
    }
    else if(strlen(aux) == 5){
        n.numero[0] = aux[0];
        n.numero[1] = aux[1];
        n.numero[2] = aux[2];
        n.numero[3] = aux[3];
    }
    
}

void tratanumero(){

    switch (n.numero[0])
    {
    case '9':
        strcpy(n.extenso[0],"nove mil ");
        break;
    case '8':
        strcpy(n.extenso[0],"oito mil ");
        break;
    case '7':
        strcpy(n.extenso[0],"sete mil ");
        break;
    case '6':
        strcpy(n.extenso[0],"seis mil ");
        break;
    case '5':
        strcpy(n.extenso[0],"cinco mil ");
        break;
    case '4':
        strcpy(n.extenso[0],"quatro mil ");
        break;
    case '3':
        strcpy(n.extenso[0],"tres mil ");
        break;
    case '2':
        strcpy(n.extenso[0],"dois mil ");
        break;
    case '1':
        strcpy(n.extenso[0],"mil ");
        break;

    }

    switch (n.numero[1])
    {
    case '9':
        strcpy(n.extenso[1],"novecentos e ");
        break;
    case '8':
        strcpy(n.extenso[1],"oitocentos e ");
        break;
    case '7':
        strcpy(n.extenso[1],"setecentos e ");
        break;
    case '6':
        strcpy(n.extenso[1],"seiscentos e ");
        break;
    case '5':
        strcpy(n.extenso[1],"quinhetos e ");
        break;
    case '4':
        strcpy(n.extenso[1],"quatrocentos e ");
        break;
    case '3':
        strcpy(n.extenso[1],"trezentos e ");
        break;
    case '2':
        strcpy(n.extenso[1],"duzentos e ");
        break;
    case '1':
        strcpy(n.extenso[1],"cento e ");
        break;

    }

    switch (n.numero[2])
    {
    case '9':
        strcpy(n.extenso[2],"noventa e ");
        break;
    case '8':
        strcpy(n.extenso[2],"oitenta e ");
        break;
    case '7':
        strcpy(n.extenso[2],"setenta e ");
        break;
    case '6':
        strcpy(n.extenso[2],"sessenta e ");
        break;
    case '5':
        strcpy(n.extenso[2],"cinquenta e ");
        break;
    case '4':
        strcpy(n.extenso[2],"quarenta e ");
        break;
    case '3':
        strcpy(n.extenso[2],"trinta e ");
        break;
    case '2':
        strcpy(n.extenso[2],"vinte e ");
        break;
    case '1':
        switch (n.numero[3])
        {
        case '9':
            strcpy(n.extenso[2],"dezenove");
            break;
        case '8':
            strcpy(n.extenso[2],"dezoito");
            break;
        case '7':
            strcpy(n.extenso[2],"dezessete");
            break;
        case '6':
            strcpy(n.extenso[2],"dezesseis");
            break;
        case '5':
            strcpy(n.extenso[2],"quinze");
            break;
        case '4':
            strcpy(n.extenso[2],"catorze");
            break;
        case '3':
            strcpy(n.extenso[2],"treze");
            break;
        case '2':
            strcpy(n.extenso[2],"doze");
            break;
        case '1':
            if(n.numero[3] == '1'){
                strcpy(n.extenso[2],"onze");
            }
            else{
                strcpy(n.extenso[2],"dez");
            }
            break;

        }

    }
    if(n.numero[2] != '1'){
        switch (n.numero[3])
        {
        case '9':
            strcpy(n.extenso[3],"nove");
            break;
        case '8':
            strcpy(n.extenso[3],"oito");
            break;
        case '7':
            strcpy(n.extenso[3],"sete");
            break;
        case '6':
            strcpy(n.extenso[3],"seis");
            break;
        case '5':
            strcpy(n.extenso[3],"cinco");
            break;
        case '4':
            strcpy(n.extenso[3],"quatro");
            break;
        case '3':
            strcpy(n.extenso[3],"tres");
            break;
        case '2':
            strcpy(n.extenso[3],"dois");
            break;
        case '1':
            strcpy(n.extenso[3],"um");
            break;

        }
    }
}

void printaresultado(){

    printf("\n%s",n.extenso[0]);
    printf("%s",n.extenso[1]);
    printf("%s",n.extenso[2]);
    printf("%s\n",n.extenso[3]);
}

int main(){

    peganumero();
    tratanumero();
    printaresultado();

    return 0;
}