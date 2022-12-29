#include <stdio.h>
#include <string.h>

int leitura()
{
    char entrada[20];
    int len;
    printf("Digite a entrada:");
    fgets(entrada,20,stdin);
    len = strlen(entrada) - 1;
    entrada[len] = '\0';
    return entrada;

}

int conversao(entrada)
{
    int i;
    for(i = 0; i <= strlen(entrada) - 1; i++){
        switch (entrada)
        {
        case entrada[i] == '':
            entrada[i] = '\\34';
            break;

        case entrada[i] == '\t':
            entrada[i] = '\\116';
            break;
        
        case entrada[i] == '\f':
            entrada[i] = '\\102';
            break;

        case entrada[i] == '\v':
            entrada[i] = '\\118';
            break;

        case entrada[i] == '\n':
            entrada[i] = '\\110';
            break;

        case entrada[i] == '\r':
            entrada[i] = '\\114';
            break;

        default:
            break;
        }
    }
    return entrada;
}

char main(entrada)
{
    int i;
    for(i=0; i<=strlen(entrada) - 1; i++){
        printf("%c", entrada[i]);
    }
    return 0;
}
