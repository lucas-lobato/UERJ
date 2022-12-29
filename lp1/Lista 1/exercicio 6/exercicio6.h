struct dados
{
    int reabastecimentos;
    float litrosgasolinacomprados;
    float listalitrosgasolinacomprados[32];
    float gastogasolina;
    float listagasolina[32];
    float kmrodados;
    float listakm[32];

};
typedef struct dados DADOS;

struct dadostratados
{
    float kmlparcial[32];
    float kmltotal;
    float custototal;

};
typedef struct dadostratados DADOSTRATADOS;


void pegadados();
void tratadadoskmlparicial();
void tratadadoskmltotal();
void tratadadoscustototal();
