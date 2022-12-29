#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main (void)
{
    int cont=0,contt=0;
    char texto[][80],c;
    FILE* arq;
    printf("Lendo o arquivo...");
    arq=fopen("mussum.txt","r");
    while(c!=EOF){
        c=fgetc(arq);
        texto[contt][cont]=c;
        cont++;
        if (cont=80){
            contt++;
        }
    }
    printf("\n %c",texto);
    return 0;
}
