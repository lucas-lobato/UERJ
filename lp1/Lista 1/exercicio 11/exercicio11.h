struct texto
{
    char texto[88][20];
    char textotratado[36][20];
    int contavogais;
    int auxiliar;
};
typedef struct texto TEXTO;

void pegatexto();
void tratatexto();
void calculapalavras();
void printaresultado();
int main();