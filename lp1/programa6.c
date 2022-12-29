#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    char n[100],m[100];
    int i,f=0,j=0;
    bool t= true;
    printf("Digite algo:");
    fgets(n,100,stdin);
    printf("String digitada:%s",n);
    for (i=(strlen(n)-2); i>=0; i--){
        m[f]=n[i];
        f++;    

    }
    m[f]='\0';
    n[f]='\0';
    printf("String invertida:%s",m);
    printf("\n");
    for (j=(strlen(n)-1);j>=0;j--){
        if (n[j]==' '){
            n[j]=n[j-1];
        }
        
        else if (m[j]==' '){
            m[j]=m[j-1];
        }
        
        else if(n[j]!=m[j]){
            t=false;        
        }
    }
    if (t==false){
        printf("Nao e palindromo");    
    }
    else{
        printf("E palindromo");    
    }
    printf("\n");
    
    return 0;   
}
