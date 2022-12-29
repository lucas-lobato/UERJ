#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    int i=0,k=0,c=0,cont=0,a=0,l=0,j=0;
    char num[50],b[50],hex[50],aux[50];
    printf("Digite um numero octal:");
    fgets(num,50,stdin);
    int ln=strlen(num)-2;
    num[ln+2]='\0';
    for(i=0;i<=ln+1;i++){
        if(num[i]=='0'){
            b[c]='0';
            b[c+1]='0';
            b[c+2]='0';
        }
        else if(num[i]=='1'){
            b[c]='0';
            b[c+1]='0';
            b[c+2]='1';
        }
        else if(num[i]=='2'){
            b[c]='0';
            b[c+1]='1';
            b[c+2]='0';
        }
        else if(num[i]=='3'){
            b[c]='0';
            b[c+1]='1';
            b[c+2]='1';
        }
        else if(num[i]=='4'){
            b[c]='1';
            b[c+1]='0';
            b[c+2]='0';
        }
        else if(num[i]=='5'){
            b[c]='1';
            b[c+1]='0';
            b[c+2]='1';
        }
        else if(num[i]=='6'){
            b[c]='1';
            b[c+1]='1';
            b[c+2]='0';
        }
        else if(num[i]=='7'){
            b[c]='1';
            b[c+1]='1';
            b[c+2]='1';
        }
        c=c+3;
    }
    b[c-3]='\0';
    printf("\nbinario:%s",b);
    if(strlen(b)==3){
        aux[0]='0';
        aux[1]=b[0];
        aux[2]=b[1];
        aux[3]=b[2];
        aux[4]='\0';
        if(aux[j]=='0' && aux[j + 1]=='0' && aux[j + 2]=='0' && aux[j + 3]=='0'){
            hex[cont]='0';
        }
        else if(aux[j]=='0' && aux[j + 1]=='0' && aux[j + 2]=='0' && aux[j + 3]=='1'){
            hex[cont]='1';
        }
        else if(aux[j]=='0' && aux[j + 1]=='0' && aux[j + 2]=='1' && aux[j + 3]=='0'){
            hex[cont]='2';
        }
        else if(aux[j]=='0' && aux[j + 1]=='0' && aux[j + 2]=='1' && aux[j + 3]=='1'){
            hex[cont]='3';
        }
        else if(aux[j]=='0' && aux[j + 1]=='1' && aux[j + 2]=='0' && aux[j + 3]=='0'){
            hex[cont]='4';
        }
        else if(aux[j]=='0' && aux[j + 1]=='1' && aux[j + 2]=='0' && aux[j + 3]=='1'){
            hex[cont]='5';
        }
        else if(aux[j]=='0' && aux[j + 1]=='1' && aux[j + 2]=='1' && aux[j + 3]=='0'){
            hex[cont]='6';
        }
        else if(aux[j]=='0' && aux[j + 1]=='1' && aux[j + 2]=='1' && aux[j + 3]=='1'){
            hex[cont]='7';
        }
       // tratamento do aux.
    }
    else if(strlen(b)>3){
        if(strlen(b)%4==0){
            for(l=0;l<=strlen(b);l++){
                aux[l]=b[l];
            }
        }
        else if(strlen(b)%4==1){
            aux[0]='0';
            aux[1]='0';
            aux[2]='0';
            int a=0;
            for (l=3;l<=strlen(b)+1;l++){
                aux[l]=b[a];
                a++;
            }
        }
        else if(strlen(b)%4==2){
            aux[0]='0';
            aux[1]='0';
            int a=0;
            for (l=2;l<=strlen(b)+1;l++){
                aux[l]=b[a];
                a++;
            }
        }
        else if(strlen(b)%4==3){
            aux[0]='0';
            int a=0;
            for (l=1;l<=strlen(b)+1;l++){
                aux[l]=b[a];
                a++;
            }
        }
        for(cont=0;cont<=strlen(b)/4;cont++){
            if(aux[j]=='0' && aux[j + 1]=='0' && aux[j + 2]=='0' && aux[j + 3]=='0'){
                hex[cont]='0';
            }
            else if(aux[j]=='0' && aux[j + 1]=='0' && aux[j + 2]=='0' && aux[j + 3]=='1'){
                hex[cont]='1';
            }
            else if(aux[j]=='0' && aux[j + 1]=='0' && aux[j + 2]=='1' && aux[j + 3]=='0'){
                hex[cont]='2';
            }
            else if(aux[j]=='0' && aux[j + 1]=='0' && aux[j + 2]=='1' && aux[j + 3]=='1'){
                hex[cont]='3';
            }
            else if(aux[j]=='0' && aux[j + 1]=='1' && aux[j + 2]=='0' && aux[j + 3]=='0'){
                hex[cont]='4';
            }
            else if(aux[j]=='0' && aux[j + 1]=='1' && aux[j + 2]=='0' && aux[j + 3]=='1'){
                hex[cont]='5';
            }
            else if(aux[j]=='0' && aux[j + 1]=='1' && aux[j + 2]=='1' && aux[j + 3]=='0'){
                hex[cont]='6';
            }
            else if(aux[j]=='0' && aux[j + 1]=='1' && aux[j + 2]=='1' && aux[j + 3]=='1'){
                hex[cont]='7';
            }
            else if(aux[j]=='1' && aux[j + 1]=='0' && aux[j + 2]=='0' && aux[j + 3]=='0'){
                hex[cont]='8';
            }
            else if(aux[j]=='1' && aux[j + 1]=='0' && aux[j + 2]=='0' && aux[j + 3]=='1'){
                hex[cont]='9';
            }
            else if(aux[j]=='1' && aux[j + 1]=='0' && aux[j + 2]=='1' && aux[j + 3]=='0'){
                hex[cont]='A';
            }
            else if(aux[j]=='1' && aux[j + 1]=='0' && aux[j + 2]=='1' && aux[j + 3]=='1'){
                hex[cont]='B';
            }
            else if(aux[j]=='1' && aux[j + 1]=='1' && aux[j + 2]=='0' && aux[j + 3]=='0'){
                hex[cont]='C';
            }
            else if(aux[j]=='1' && aux[j + 1]=='1' && aux[j + 2]=='0' && aux[j + 3]=='1'){
                hex[cont]='D';
            }
            else if(aux[j]=='1' && aux[j + 1]=='1' && aux[j + 2]=='1' && aux[j + 3]=='0'){
                hex[cont]='E';
            }
            else if(aux[j]=='1' && aux[j + 1]=='1' && aux[j + 2]=='1' && aux[j + 3]=='1'){
                hex[cont]='F';
            }
            j=j+4;
        }
    }
    hex[(strlen(b)/4)+1]='\0';
    printf("\nhexadecimal:%s",hex);
    printf("\n");
    return 0;   
}

