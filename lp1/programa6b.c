#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    char frase[500];
    int cont=0,f=0,i=0;
    bool t= true;
    
    printf("Digite uma frase:");
    fgets(frase,500,stdin);
    printf("Frase digitada:%s",frase);
    for (i=strlen(frase)-2;i>=(strlen(frase)-2)/2;i--){
        frase[cont]=tolower(frase[cont]);
        if (frase[cont]==' '){
            frase[cont]=frase[cont+1];
        }
        if (frase[cont]!=frase[(strlen(frase)-2)-(cont)]){
            t=false;
	  cont++;
        }
	
    }
    frase[f]='\0';

    if (t==true){
        printf("SIM\n");
    }
    if (t==false){
        printf("NAO\n");
    }
    printf("\n");
    return 0;
}
