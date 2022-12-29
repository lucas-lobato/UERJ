#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct horario
    {
        int hora;
        int minuto;
        int segundo;
    };
    
    struct horario agora, *depois;
    struct horario antes;
    int somatorio = 100;

    depois = &agora;
    printf("\n%i:%i:%i", agora.hora, agora.minuto, agora.segundo);
    printf("\n");

    depois -> hora = 10; //( (*depois).hora  ==  depois -> hora)  !!!
    depois -> minuto = 20;
    depois -> segundo = 30;
        
    printf("\n%i:%i:%i", agora.hora, agora.minuto, agora.segundo);
    printf("\n");

    antes.hora = somatorio + depois -> hora;
    antes.minuto = somatorio + depois -> minuto;
    antes.segundo = somatorio + depois -> segundo;

    printf("\n%i:%i:%i", antes.hora, antes.minuto, antes.segundo);
    printf("\n");

    return 0;
}