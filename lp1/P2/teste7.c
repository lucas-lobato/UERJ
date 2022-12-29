#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista{
    int elemento;
    struct lista *proximo;
}celula;

void insere(celula **topo, int ele){
    celula *novo;
    novo = malloc(sizeof(celula));
    novo->elemento = ele;
    if(*topo == NULL){
        novo->proximo = NULL;
        *topo = novo;
    }
    else{
        novo->proximo = *topo;
        *topo = novo;
    }

}

void printar(celula *topo){
    celula *aux;
    aux = topo;
    if(aux == NULL){

    }
    else{
        do{
            printf("%d->", aux->elemento);
            aux = aux->proximo;
        }while (aux!=NULL);
        
    }

}

int main(void)
{
    int numero;
    celula *topo = NULL;
    while(true){
        printf("\nDigite um numero a ser inserido na lista:");
        scanf("%i", &numero);
        insere(&topo, numero);
        printar(topo);
        if(numero == ' '){
            break;
        }
    }

    return 0;
}