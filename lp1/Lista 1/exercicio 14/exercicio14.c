#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main(){
    
    printf("********** RELÓGIO **********\n\n");
    int segundos = 0;
    int minutos = 0;
    int horas = 0;
    int aux = 100;

    while (horas < 25)
    {
        printf("\r\t%2d : %2d : %2d",horas,minutos,segundos);
        segundos++;
        usleep(aux*10000);
        if(segundos == 59){
            segundos = 0;
            minutos++;
        }
        if(minutos == 59){
            segundos = 0;
            minutos = 0;
            horas++;
        }
        if(horas == 24){
            segundos = 0;
            minutos = 0;
            horas = 0;
        }
    }
    return 0;
}