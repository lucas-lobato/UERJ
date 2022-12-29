#include <stdio.h>
#include <stdlib.h>

int main(void){

    struct lista{
        int valor;
        struct lista *proximo, *anterior;
    }; 

    struct lista *elementoAtual, *aux;

    elementoAtual = (struct lista*) malloc(sizeof(struct lista));
    elementoAtual->valor = 1;
    elementoAtual->proximo = NULL;
    elementoAtual->anterior = NULL;
    aux = elementoAtual;

    elementoAtual->proximo = (struct lista*) malloc(sizeof(struct lista));
    elementoAtual = elementoAtual->proximo;
    elementoAtual->valor = 2;
    elementoAtual->proximo = NULL;
    elementoAtual->anterior = aux;

    elementoAtual->proximo = (struct lista*) malloc(sizeof(struct lista));
    elementoAtual = elementoAtual->proximo;
    elementoAtual->valor = 3;
    elementoAtual->proximo = NULL;
    elementoAtual->anterior = aux;

    elementoAtual->proximo = (struct lista*) malloc(sizeof(struct lista));
    elementoAtual = elementoAtual->proximo;
    elementoAtual->valor = 4;
    elementoAtual->proximo = NULL;
    elementoAtual->anterior = aux;

    while (elementoAtual->anterior != NULL)
    {
        elementoAtual = elementoAtual->anterior;
    }
    
    while (1)
    {
        printf("\nValor: %i",elementoAtual->valor);
        if(elementoAtual->proximo == NULL){
            break;
        }
        elementoAtual = elementoAtual->proximo;
    }
    
    while (elementoAtual->anterior != NULL)
    {
        elementoAtual = elementoAtual->anterior;
        free(elementoAtual->proximo);
    }
    free(elementoAtual);
    return 0;
    
}