#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int i=0,len_bin,c=0;
    char bin[50];
    printf("Digite um numero octal:");
    fgets(bin,50,stdin);
    len_bin=strlen(bin);
    for(i=0;i<=len_bin-2;i++){
        bin[i]=(i+1)*3;
        int inteiro=bin[i]-'0';
        for(inteiro-1;){


        }

    }
    bin[len_bin]='\0';


}
