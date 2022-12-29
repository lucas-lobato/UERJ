#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct lista
    {
        int valor;
        struct lista *proximo;
        
    };
    struct lista m1, m2, m3;
    struct lista *gancho = &m1;

    m1.valor = 10;
    m2.valor = 20;
    m3.valor = 30;

    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = NULL;

    while(gancho != NULL)
    {
        printf("%i\n", gancho -> valor);
        gancho = gancho -> proximo;
    }

    return 0;
}