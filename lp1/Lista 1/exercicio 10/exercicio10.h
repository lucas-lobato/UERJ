struct texto
{
    char texto[88][20];
    char textotratado[70][20];
    int contapalavras;
    int auxiliar;
};
typedef struct texto TEXTO;

void pegatexto();
void tratatexto();
void contapalavras();
void limpatexto();
void printaresultado();
int main();