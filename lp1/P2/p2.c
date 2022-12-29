#include <stdio.h>
#include <stdlib.h>

struct no {
	unsigned long int chave;
	struct no *pSeguinte;
};


int insereOrdRec (struct no **, unsigned long int);
void imprimeListaRec (struct no *);
void esvaziaListaRec(struct no **);

int insereOrdIterativo (struct no **, unsigned long int);
void imprimeListaIterativo (struct no *);
void esvaziaListaIterativo(struct no **);

int main (void)
{
	
	struct no* pPrimeiro = NULL;

	FILE* arq = NULL;
	if (!(arq = fopen("Dados.txt", "r")))
	{
		fprintf(stderr,"Arquivo dados não pode ser aberto\n");
		return -1; 
	} 
	
	unsigned long int chave, repetidos =0, inseridos=0;
	while (fscanf(arq,"%lu",&chave)==1)
	{
		if (ferror(arq))
		{
			fprintf(stderr,"Erro na leitura do arquivo\n");		
			return -2;		
		}
//		if (insereOrdRec(&pPrimeiro, chave))
		if (insereOrdIterativo(&pPrimeiro, chave))
			inseridos++;
		else 
			repetidos++;
	}	
	if (fclose(arq)==EOF)
	{
			fprintf(stderr,"Erro no fechamento do arquivo\n");		
			return -3;		
	}
	printf("Repetidos: %lu\nInseridos: %lu\n", repetidos, inseridos);
	printf("Início da lista\n");
	imprimeListaIterativo (pPrimeiro);
//	imprimeListaRec (pPrimeiro);
	printf("Fim da lista\n");
	esvaziaListaIterativo (&pPrimeiro);
//	esvaziaListaRec (&pPrimeiro);
	printf("Início da lista\n");
	imprimeListaIterativo (pPrimeiro);
//	imprimeListaRec (pPrimeiro);
	printf("Fim da lista\n");
}

int insereOrdRec (struct no **pp, unsigned long int chave)
{
	if ((*pp) && (*pp)->chave < chave){
		return insereOrdRec(&((*pp)->pSeguinte),chave);
    }
	else
		if (!(*pp) || (*pp)->chave > chave)
		{
			struct no *novoNo = malloc (sizeof *novoNo);
			novoNo->chave = chave;
			novoNo->pSeguinte = *pp;
			*pp =  novoNo;
			return 1;
		}
		else
			return 0;
}

int insereOrdIterativo (struct no **pp, unsigned long int chave)
{
    struct no *aux = *pp;
    if(*pp==NULL)
    {
	    struct no *novoNo = malloc (sizeof *novoNo);
	    novoNo->chave = chave;
	    novoNo->pSeguinte = NULL;
	    *pp =  novoNo;
	    return 1;
    }
    if(aux->chave>=chave)
    {
	    struct no *novoNo = malloc (sizeof *novoNo);
	    novoNo->chave = chave;
	    novoNo->pSeguinte = aux;
	    *pp=novoNo;
	    return 1;
    }
	struct no *ant= NULL;
    while((aux) && (aux)->chave < chave)
    {
	    aux=aux->pSeguinte;
	    if(ant==NULL)
        {
		    ant=*pp;
	    }
        else
        {
		ant=ant->pSeguinte;
        }
	    
    }
    struct no *novoNo = malloc (sizeof *novoNo);
	novoNo->chave = chave;
	novoNo->pSeguinte = aux;
	ant->pSeguinte =  novoNo;
	return 1;
}

void imprimeListaRec (struct no *p)
{
	if (p)
	{
		printf("%lu\n",p->chave);
		imprimeListaRec(p->pSeguinte);
	}
}

void imprimeListaIterativo (struct no *p)
{
    struct no* aux = p;
    if(p){
        while(aux->pSeguinte!=NULL){
		    printf("%lu\n", aux->chave);
		    aux=aux->pSeguinte;
	    }
        printf("%lu\n", aux->chave);
    }
}

void esvaziaListaRec(struct no **pp)
{	
	if (*pp)
	{
		esvaziaListaRec(&((*pp)->pSeguinte));
		free(*pp);
		*pp = NULL;
	}
}

void esvaziaListaIterativo(struct no **pp)
{
    struct no* aux ;
    if (*pp)
	{
        while(aux->pSeguinte!=NULL)
        {
	    aux=*pp;
            *pp= (*pp)->pSeguinte;
		    free(aux);
        }
	}

}