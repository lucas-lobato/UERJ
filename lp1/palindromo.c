#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int i = 0, len = 0;
    char frase[50];
    bool igual = true;
    printf("Digite a frase:");
    fgets(frase,50,stdin);
    len = strlen(frase) - 1;
    frase[len + 1] = '\0';
    for(i=0; i<=len/2; i++){
        if(frase[i] != frase[len - i - 1]){
            igual = false;
        }
    }
    if (igual==true){
        printf("\n");
        printf("SIM\n");
    }
    else{
        printf("\n");
        printf("NAO\n");
    }
    return 0;
}