#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE* arq;
    char c, name_arq[60];
    int char_lidos = 0, counter_linhas = 0, char_imp = 0;
    scanf("%s",&name_arq);
    if(!(arq = fopen(name_arq,"r"))){
        printf("Erro no arquivo %s\n",name_arq);
        exit(1);
    }
    while((c=fgetc(arq)) != EOF){
        char_lidos++;
        if(c == '\n'){
            counter_linhas++;
        }
        if(isprint(c)){
            char_imp++;
        }
    }
    printf("%d\n%d\n%d\n",char_lidos,char_imp,counter_linhas);
    return 0;
}
















}
