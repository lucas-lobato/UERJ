#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int valor;
    struct lista *proximo;
};
struct lista *procurarValor(struct lista *pLista, int valor)
{
    while(pLista != NULL)
    {
        if(pLista->valor == valor)
        {
            return pLista;
        }
        else
        {
            pLista = pLista->proximo;
        }
    }
    return NULL;
    
}

int main(void)
{
    int valor;

    struct lista *procurarValor(struct lista *pLista, int valor);
    struct lista m1, m2, m3;
    struct lista *resultado, *gancho = &m1;

    m1.valor = 1;
    m2.valor = 2;
    m3.valor = 3;

    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = NULL;

    printf("Digite o valor da pesquisa:");
    scanf("%i",&valor);

    resultado = procurarValor(gancho, valor);
    if(resultado == NULL)
    {
        printf("Valor nao encontrado...");
        printf("\n");
    }
    else
    {
        printf("valor %i encontrado", resultado->valor);
        printf("\n");
    }

    return 0;
}