//Gerar Rotas
#define RAND_MAX_Distancia 100
#define RAND_MAX_Demanda 10 //Definir numero de 1 a 10 que posteriormente ser� multiplicado por 1000
typedef struct{
    int Cod_Cidade;
    float Quant_Demanda;
    int Atendida; //Marcador para saber se foi atendida 0 para n�o e 1 para sim;
}TCidade;

typedef struct{
    TCidade *pCidade;
    int DistCid;
}TCelula;

typedef struct{
    TCelula *pCelula;
    float Tot_Demanda = 0;
    int quantVeiculos;
    int Tamanho; //Ser� usado para condi��o de parada do for ao percorrer a matriz
}TListaCidade;

void CLVaziaCidades(TListaCidade **CLista, int n); //Cria lista vazia de cidades;
int PreencheLista(TListaCidade *CLista, float CapacidadeVeiculo);//Preenche lista com numeros ale�torios de demanda;
int GeraRotas(TListaCidade *CLista); //gerar poss�veis rotas;
int VerificaMelhorRota(TListaCidade *CLista); //Verificar a melhor rota poss�vel;

