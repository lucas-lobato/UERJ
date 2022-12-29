#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    FILE *arq;
    int c, cont_linhas=0, cont_char=0, cont_cimp=0;
    char file[25];
    printf("Coloque o nome do arquivo que deseja abrir:");
    //fgets(file,25,stdin);
    scanf("%s",file);
    file[strlen(file)+1]='\0';
    arq=fopen(file,"r");
    if(arq==NULL){
        printf("Erro no arquivo\n");
        exit(1);
    }
    else if(arq!=NULL){
        //c=fgetc(arq);
        while((c=fgetc(arq))!=EOF){
            if(c=='\n'){
                cont_linhas++;
            }
            else if(c!=' '){
                cont_char++;
            }
            else if(isprint(c)){
                cont_cimp++;
            }
        }
    }
    fclose(arq);
    printf("\nNumero de linhas:%d",cont_linhas);
    printf("\nNumero de caracteres:%d",cont_char);
    printf("\nNumero de caracteres imprimiveis:%d",cont_cimp);
    printf("\n");
    return 0;
}
