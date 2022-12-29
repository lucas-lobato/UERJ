struct dados
{
    int listanascimento[32];
    char listasexo[32];
    char listaprocedencia[32];
    int porcentagemmenos21;
    int mulherescapital;
    int interiormaisde60;
    bool mulhermaisde60;
};
typedef struct dados DAODS;

void pegadados();
void porcentagem_menos_de_21();
void mulheres_capital();
void mais_de_60_interior();
void mulher_mais_de_60();
void printaresultado();
int main();