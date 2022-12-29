#include <stdio.h>

int main()
{
    int base, altura, area;
    
    printf("Digite a base:");
    scanf("%i", &base);
    
    printf("Digite a altura:");
    scanf("%i", &altura); 
    
    area=base*altura;
    
    printf("A area e' %i ", area);
    printf("\n");
    
    return 0;

}
