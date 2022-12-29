#include <stdio.h>

int main()
{
    int i,j;
    float n,numc;
    printf("Digite o numero de transformações desejadas:");
    scanf("%d",&j);
    for(i=0;i<=j-1;i++)
    {
        printf("Temperatura em celsius:");
        scanf("%f",&n);
        numc=(n*(1.8))+32;
        printf("temperatura convertida:%.2f",numc);
        printf("\n");
        printf("\n");
    }

    return 0;
}
