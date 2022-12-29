struct dados
{
    int rodada;
    int rand;
    int jogador1dado1;
    int jogador1dado2;
    int jogador2dado1;
    int jogador2dado2;
    int vitorias_jogador_1;
    int vitorias_jogador_2;
    char resultado[32];
};
typedef struct dados DADOS;

void lancamento();
void rodada();
void resultado();
int main();