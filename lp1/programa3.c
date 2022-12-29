#include <stdio.h>

int main()
{
    
    int contador;
    float valores;
    float valores2;
    int x;
    printf("\n");    
    printf("Digite o numero de transformaçoes desejadas:"); 
    scanf("%i", &contador);
    printf("\n");
    x=1;
    
    for (x=1; x<=contador;x=x+1){
        printf("\n");        
        printf("Digite um valor para a temperatura (em celsius):");
        scanf("%f", &valores);
        
        valores2=valores*9/5 + 32;
        printf("Valor em fahrenheit = %.2f",valores2);
        printf("\n");
    }

    return 0;

}
