#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trabalho.h"

MESAS m;
PEDIDOS p;
RESTAURANTE r;
OPCOES o;
GARCONS ga;
FILE *f;
FILE *g;

struct mesas *atualM, *aux;
struct pedidos *aux2, *inicio;
struct opcoes *atualO, *auxopcoes;
struct garcons *atualG, *auxgarcons;


void colocapedidos(){

    int codigo;
    char nome[32];
    int mesa;
    bool achei = false;

    printf("\nDigite o numero da mesa: ");
    scanf("%i",&mesa);
    while(atualM -> anterior != NULL){
        atualM = atualM->anterior;
    }
    while(atualM -> proximo != NULL){
        if(atualM->valor == mesa){
            achei = true;
            break;
        }
        atualM = atualM->proximo;
    }
    if(achei == true){
        printf("Digite o codigo do pedido:");
        scanf("%i",&codigo);
        
        while(atualM->pedido->proximo != atualM->pedido->inicio){
            atualM->pedido = atualM->pedido->proximo;
        }
        atualM->pedido->proximo = NULL;
        atualM->pedido = (struct pedidos*)malloc(sizeof(struct pedidos));
        atualM->pedido->proximo = atualM->pedido->inicio;

        while(atualO -> anterior != NULL){
            atualO = atualO->anterior;
        }
        while(atualO -> proximo != NULL){
            if(atualO->codigo == codigo){
                atualM->pedido->codigo = codigo;
                atualM->pedido->preco = atualO->preco;
                strcpy(atualM->pedido->nome,atualO->nome);
                printf("\nColoquei o pedido // %s \\\\ na mesa %i",atualO->nome,atualM->valor);
                break;
            }
            atualO = atualO->proximo;
        }
        while(atualO -> proximo != NULL){
            atualO = atualO->proximo;
        }
        
    }
    else{
        printf("ERRO!, Essa mesa não esta ocupada\n");
    }
    while(atualM->proximo != NULL){
        atualM = atualM->proximo;
    }
}


void criamesas(){

    int i;
    printf("\nDigite o numero da mesa: ");
    scanf("%i",&i);
    atualM->valor = i;
    atualM = (struct mesas*)malloc(sizeof(struct mesas));
    atualM->pedido = (struct pedidos*)malloc(sizeof(struct pedidos));
    atualM->proximo = NULL;
    atualM->pedido->inicio = atualM->pedido;
    atualM->pedido->proximo = atualM->pedido->inicio;
    atualM->anterior = aux;
    aux->proximo = atualM;
    aux = atualM;
}


void mudapedido(){

}


void excluipedido(){

    int codigo;
    int numero_mesa;

    printf("\nDigite o numero da mesa: ");
    scanf("%i",&numero_mesa);
    printf("\nDigite o codigo do pedido a ser cancelado: ");
    scanf("%i",&codigo);

    while(atualM -> anterior != NULL){
        atualM = atualM->anterior;
    }

    while(atualM -> proximo != NULL){
        if(atualM->valor == codigo){
            break;
        }
        atualM = atualM->proximo;
    }
    while(atualM->pedido != atualM->pedido->inicio){
        atualM->pedido = atualM->pedido->proximo;
    }
    while(atualM->pedido->proximo != atualM->pedido->inicio){
        if(atualM->pedido->proximo->codigo == codigo){
            atualM->proximo = atualM->proximo->proximo;
        }
        atualM->pedido = atualM->pedido->proximo;
    }
    while(atualM -> proximo != NULL){
        atualM = atualM->proximo;
    }
}


void printamesas(){

    while(atualM -> anterior != NULL){
        atualM = atualM->anterior;
    }
    printf("\n");
    while(atualM->proximo != NULL){
        while(atualM->pedido->proximo != atualM->pedido->inicio){
            atualM->pedido = atualM->pedido->proximo;
        }
        atualM->pedido = atualM->pedido->proximo;
        printf("MESA %i  //  PEDIDOS:",atualM->valor);
        while(atualM->pedido->proximo != atualM->pedido->inicio){
            printf(" %s",atualM->pedido->nome);
            atualM->pedido = atualM->pedido->proximo;
        }
        atualM = atualM->proximo;
        printf("\n");
    }
    printf("\n\n");
}


void notafiscal(){


}


void ADMPratos(){

    int opcao = 0;
    while(true){

        printf("\r\n*************************************************");
        printf("\r\n********** M-E-N-U  A-D-M  P-R-A-T-O-S  *********");
        printf("\r\n*************************************************\n");
        printf("\r\nDigite uma das opçẽs abaixo:\n");
        printf("\r\n(1)Novo prato\n(2)Excluir prato\n(3)Alterar prato\n(4)Voltar para o menu principal\n->:");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            novo_prato();
            break;
        case 2:
            excluir_prato();
            break;
        case 3:
            alterar_prato();
            break;
        case 4:
            programa();
            break;
        }
    }
}


void novo_prato(){

    char nome[32];
    int codigo;
    int preco;

    printf("\nDigite o nome do prato:");
    scanf("%s",nome);
    printf("Digite o codigo do prato:");
    scanf("%i",&codigo);
    printf("Digite o preço do prato:");
    scanf("%i",&preco);
    atualO = (struct opcoes*)malloc(sizeof(struct opcoes));
    atualO->proximo = NULL;
    atualO->anterior = auxopcoes;
    auxopcoes->proximo = atualO;
    auxopcoes = atualO;
    strcpy(atualO->nome,nome);
    atualO->codigo = codigo;
    atualO->preco = preco;
    
    
}


int excluir_prato(){

    char codigoaux[3];
    char nome[32];
    char codigo[3];
    char preco[3];
    bool achei = false;
    char vazio[] = {' '};
    char c;
    char caux[1];
    int contador = 0;
    int line = 1;
    int contador2 = 0;
    int i = 0;

    printf("\nDigite o codigo do prato a ser excluido do prato:");
    scanf("%s",codigo);
    f = fopen("opcoes.bin","r+b");

    while(c != EOF){
        c = getc(f);
        if(c == ' '){
            contador++;
        }
        if(c == ' ' && (contador % 2 == 1)){
            c = getc(f);
            codigoaux[i] = c;
            i++;
        }
        if(strcmp(codigoaux,codigo)){
            printf("\nACHEI");
            achei = true;
            break;
        }
        if(contador == 2){
            contador = 0;
            i = 0;
            codigoaux[0] = ' ';
            codigoaux[1] = ' ';
            codigoaux[2] = ' ';
        }
    }

    if(achei == false){
        printf("\nDesculpe, não achei esse código no banco de dados...");
        fclose(f);
        return 0;
    }

    rewind(f);
    g = fopen("opcoesaux.bin","w");
    while(c != EOF){
        c = getc(f);
        caux[0] = c;
        if(c == '\n'){
            contador2++;
        }
        if(contador2 == line - 1){
            while(c != '\n'){
                c = getc(f);
            }
            c = getc(f);
            caux[0] = c;
            if(line == 1){
                c = getc(f);
                caux[0] = c;
            }
        }
        fwrite(caux , sizeof(char), strlen(caux), g);
    }
    
    rewind(f);
    rewind(g);

    while(c != EOF){
        c = getc(g);
        caux[0] = c;
        fwrite(caux, sizeof(char), strlen(caux), f);
    }
    fclose(f);
    fclose(g);
}


void alterar_prato(){

}


void ADMGarcons(){

    int opcao = 0;
    
    while(true){
        printf("\r\n***************************************************");
        printf("\r\n********** M-E-N-U  A-D-M  G-A-R-Ç-O-N-S  *********");
        printf("\r\n***************************************************\n");
        printf("\r\nDigite uma das opçẽs abaixo:\n");
        printf("\r\n(1)Novo garçon\n(2)Excluir garçon\n(3)Alterar garçon\n(4)Voltar para o menu principal\n->:");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            novo_garcon();
            break;
        case 2:
            excluir_garcon();
            break;
        case 3:
            alterar_garcon();
            break;
        case 4:
            programa();
            break;
        }
    }
}


void novo_garcon(){

}


void excluir_garcon(){

}


void alterar_garcon(){

}

void programa(){

    int opcao = 0;

    while(true){

        printf("\r\n**************************************************");
        printf("\r\n***********  M-E-N-U  C-L-I-E-N-T-E-S  ***********");
        printf("\r\n**************************************************\n");
        printf("\r\nDigite uma das opçẽs abaixo:\n");
        printf("\r\n(1)Consultar mesas\n(2)Nova mesa\n(3)Novo pedido\n(4)Alterar pedido\n(5)Excluir pedido\n(6)Fechar conta\n(7)ADM Pratos\n(8)ADM garçons\n(9)Fechar programa\n->:");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            printamesas();
            break;
        case 2:
            r.quantidade_de_mesas++;
            criamesas();
            break;
        case 3:
            colocapedidos();
            break;
        case 4:
            mudapedido();
            break;
        case 5:
            excluipedido();
            break;
        case 6:
            notafiscal();
            break;
        case 7:
            ADMPratos();
            break;
        case 8:
            ADMGarcons();
            break;
        case 9:
            fechaprograma();
            break;
        }
    }
}


void pegadados_garcons(){

    char nome[32];
    int codigo;
    char c;

    f = fopen("garcons.bin","rb");
    rewind(f);
    while(c != EOF){
        c = getc(f);
        if(c == ' '){
            r.quantidade_de_garcons++;
        }
    }
    printf("\nQuantidade de garçons no restaurante: %i\n\n",r.quantidade_de_garcons);

    rewind(f);

    for(int i = 0; i < r.quantidade_de_garcons; i++){
        fscanf(f,"%s %i",nome,&codigo);
        atualG->codigo = codigo;
        strcpy(atualG->nome,nome);
        atualG = (struct garcons*)malloc(sizeof(struct garcons));
        atualG->proximo = NULL;
        atualG->anterior = auxgarcons;
        auxgarcons->proximo = atualG;
        auxgarcons = atualG;
        
    }
    fclose(f);
    
    while(atualG -> anterior != NULL){
        atualG = atualG->anterior;
    }
    while(atualG->proximo != NULL){
        printf("NOME: %s  //  CODIGO: %i",atualG->nome,atualG->codigo);
        atualG = atualG->proximo;
        printf("\n");
    }
    while(atualG -> anterior != NULL){
        atualG = atualG->anterior;
    }
}


void pegadados_opcoes(){

    char nome[32];
    int preco;
    int codigo;
    char c;

    f = fopen("opcoes.bin","rb");
    rewind(f);
    while(c != EOF){
        c = getc(f);
        if(c == '\n'){
            r.quantidade_de_opcoes++;
        }
    }
    printf("\nQuantidade de opcoes no restaurante: %i\n\n",r.quantidade_de_opcoes);

    rewind(f);
    for(int i = 0; i < r.quantidade_de_opcoes; i++){
        fscanf(f,"%s %i %i",nome,&codigo,&preco);
        atualO->codigo = codigo;
        atualO->preco = preco;
        strcpy(atualO->nome,nome);
        atualO = (struct opcoes*)malloc(sizeof(struct opcoes));
        atualO->proximo = NULL;
        atualO->anterior = auxopcoes;
        auxopcoes->proximo = atualO;
        auxopcoes = atualO;
    }
    fclose(f);
    while(atualO -> anterior != NULL){
        atualO = atualO->anterior;
    }
    while(atualO->proximo != NULL){
        printf("NOME: %s  //  CODIGO: %i  //  PRECO: %i",atualO->nome,atualO->codigo,atualO->preco);
        atualO = atualO->proximo;
        printf("\n");
    }
    while(atualO -> anterior != NULL){
        atualO = atualO->anterior;
    }
}


void declaramesasepedidos(){

    atualM = aux = NULL; // "Aterramento"
    atualM = (struct mesas*)malloc(sizeof(struct mesas));
    atualM->pedido = (struct pedidos*)malloc(sizeof(struct pedidos));
    atualM->pedido->inicio = atualM->pedido;
    atualM->pedido->proximo = atualM->pedido->inicio;
    atualM->proximo = NULL;
    aux = atualM;
    atualM -> anterior = atualM -> proximo = NULL;

}


void declaraopcoesegarcons(){

    atualG = auxgarcons = NULL; // "Aterramento"
    atualG = (struct garcons*)malloc(sizeof(struct garcons));
    atualG->proximo = NULL;
    auxgarcons = atualG;
    atualG -> anterior = atualG -> proximo = NULL;

    atualO = auxopcoes = NULL; // "Aterramento"
    atualO = (struct opcoes*)malloc(sizeof(struct opcoes));
    atualO->proximo = NULL;
    auxopcoes = atualO;
    atualO -> anterior = atualO -> proximo = NULL;

}


void fechaprograma(){

}


int main(){

    declaraopcoesegarcons();
    r.quantidade_de_mesas = 0;
    pegadados_garcons();
    r.quantidade_de_mesas = 0;
    pegadados_opcoes();
    r.quantidade_de_opcoes = 0;
    declaramesasepedidos();
    r.quantidade_de_garcons = 0;
    programa();
    
    return 0;
}