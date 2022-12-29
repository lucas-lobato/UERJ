struct pedidos
{
    int codigo;
    int preco;
    char nome[32];
    struct pedidos *proximo, *inicio;
};
typedef struct pedidos PEDIDOS;

struct mesas
{
    int valor;
    struct pedidos *pedido;
    struct mesas *proximo, *anterior;
};
typedef struct mesas MESAS;

struct restaurante
{
    int quantidade_de_opcoes;
    int quantidade_de_garcons;
    int quantidade_de_mesas;
};
typedef struct restaurante RESTAURANTE;

struct opcoes
{
    char nome[32];
    int preco;
    int codigo;
    struct opcoes *proximo, *anterior;
};
typedef struct opcoes OPCOES;

struct garcons
{
    char nome[32];
    int codigo;
    struct garcons *proximo, *anterior;
};
typedef struct garcons GARCONS;


int main();
void mudapedido();
void excluipedido();
void criamesas();
void colocapedidos();
void printamesas();
void notafiscal();
void ADMPratos();
void novo_prato();
int excluir_prato();
void alterar_prato();
void ADMGarcons();
void novo_garcon();
void excluir_garcon();
void alterar_garcon();
void programa();
void pegadados_garcons();
void pegadados_opcoes();
void declaramesasepedidos();
void fechaprograma();

