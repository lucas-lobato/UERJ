#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int i = 0, j = 0;
    bool quebra = false;
    char octal[20];
    printf("Digite o numero octal:");
    fgets(octal,20,stdin);
    int len = strlen(octal) - 1;
    char octal1[len];
    octal[len] = '\0';
    printf("%d",len);
    if((len-1)%3 == 1){
        quebra = true;
        for(j = 1; j <= len-1; j++){
            octal1[0]='0';
            octal1[j]=octal[j-1];
        }
    }

    else if((len-1)%3 == 2){
        quebra = true;
        for(j = 2; j <= len-1; j++){
            octal1[0]='0';
            octal1[1]='0';
            octal1[j]=octal[j-2];
        }
    }
        
    if (quebra == true){
        octal = octal1;
    }

    printf("\n%s", octal);
    char bin[(len-1)*3];
    for(i = 0; i <= len -3; i++){
        if (octal[i] == '0' && octal[i+1] == '0' && octal[i+2] == '0'){
            bin[0] = '0';
        }
        else if (octal[i] == '0' && octal[i+1] == '0' && octal[i+2] == '1'){
            bin[0] = '1';
        }
        else if (octal[i] == '0' && octal[i+1] == '1' && octal[i+2] == '0'){
            bin[0] = '2';
        }
        else if (octal[i] == '0' && octal[i+1] == '1' && octal[i+2] == '1'){
            bin[0] = '3';
        }
        else if (octal[i] == '1' && octal[i+1] == '0' && octal[i+2] == '0'){
            bin[0] = '4';
        }
        else if (octal[i] == '1' && octal[i+1] == '0' && octal[i+2] == '1'){
            bin[0] = '5';
        }
        else if (octal[i] == '1' && octal[i+1] == '1' && octal[i+2] == '0'){
            bin[0] = '6';
        }
        else if (octal[i] == '1' && octal[i+1] == '1' && octal[i+2] == '1'){
            bin[0] = '7';
        }
    }
    printf("\n%s",bin);
    return 0;
}