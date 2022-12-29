#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct horario
    {
        int *pHora;
        int *pMinuto;
        int *pSegundo;

    };
    struct horario hoje;

    int hora = 10;
    int minuto = 20;
    int segundo = 30;

    hoje.pHora = &hora;
    hoje.pMinuto = &minuto;
    hoje.pSegundo = &segundo;

    printf("Hora - %i", *hoje.pHora);
    printf("\nMinuto - %i", *hoje.pMinuto);
    printf("\nSegundo - %i", *hoje.pSegundo);
    printf("\n");

    printf("Endereço Hora - %ls", hoje.pHora);
    printf("\nEndereço Minuto - %ls", hoje.pMinuto);
    printf("\nEndereço Segundo - %ls", hoje.pSegundo);
    printf("\n");

    return 0;
}