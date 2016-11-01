#include <stdio.h>
#include <stdlib.h>
#include "TADGeraItem.h"

void CLVaziaCidades(TListaCidade **CLista, int n){  //Cria lista(matriz) vazia de cidades;
    int i;
    srand(time);
    *(CLista->pCelula) = (TCelula*) malloc(n*sizeof(TCelula));
    for(i = 0; i<n; i++){
        *(CLista.pCelula[i])=(TCelula*) malloc(n*sizeof(TCelula));
    }
    CLista->Tamanho = n; //Tamanho da lista;
};


int PreencheLista(TListaCidade *CLista, float CapacidadeVeiculo){ //Preenche lista com numeros aleátorios de demanda;
    int i,j,maior,aux1;
    for(i = 0; i < CLista->Tamanho; i++){
        for(j = 0; j < CLista->Tamanho; j++){
            if(i==j){ //refere-se a propria cidade, ou seja, onde vou armazenar os dados de cada cidade;
                if (i == 0 && j == 0){
                    CLista->pCelula[i][j]->DistCid = 0;
                }
                else {
                    CLista->pCelula[i][j]->DistCid = 0;
                    CLista->pCelula[i][j]->pCidade->Cod_Cidade = i;
                    CLista->pCelula[i][j]->pCidade->Quant_Demanda = ((rand()%RAND_MAX_Demanda)+1)*1000;
                    CLista->Tot_Demanda = CLista->Tot_Demanda + CLista->pCelula[i][j]->pCidade->Quant_Demanda;
                }
            }
            else if(j>i){ //armazenar distâncias entre as cidades;
                CLista->pCelula[i][j]->DistCid = (rand()%RAND_MAX_Distancia)+1;
                CLista->pCelula[j][i]->DistCid = CLista->pCelula[i][j]->DistCid;
            }
        }
    }
    CLista->quantVeiculos = CLista->Tot_Demanda/CapacidadeVeiculo;

    aux1 = CLista->Tot_Demanda%CapacidadeVeiculo;// Atribui a variavel auxiliar o resto da demanda das cidades.
    aux1 = aux1 / n;
    for (i = 1; i < n; i++){
        CLista->pCelula[i][i]->pCidade->Quant_Demanda = CLista->pCelula[i][i]->pCidade->Quant_Demanda - aux1;
    }//Esse bloco diminui em cada cidade a demanda em excesso, tornando a demanda total multiplo da carga dos caminhoes.
};
    int GeraRotas(TListaCidade *CLista){ //gerar possíveis rotas;
    /*
     * [comb.c]
     * Programa que gera todas as combinações dos caracteres
     * de uma string de entrada.
     *
     * [Autor]
     * Marcos Paulo Ferreir (Daemonio)
     * undefinido gmail com
     * https://daemoniolabs.wordpress.com/
     *
     * Versão 1.0 by daemonio @ Thu Feb 17 08:17:31 BRST 2011
     *
    */

    /* Tamanho máximo da entrada */
    #define MAX_INPUT 31
        unsigned MAX, MASK, NUM ;
        int i, j ;
        /* Armazena a string de entrada. */
        char input[MAX_INPUT] ;
        /* Armazena cada combinação. */
        char str[MAX_INPUT] ;

        printf("Digite o grupo inicial: ") ;
        scanf("%s", input) ;

        /* Manda o bit 1 para a n-ésima posição.
         * Os bits são invertidos para que a posição n
         * esteja com o bit zero, a fim de marcar
         * o final do processo.
         */
        MAX = ~(1 << strlen(input)) ;

        /* Primeiro número é o 1. */
        NUM = 1;

        putchar('\n') ;

        /* Quando o número alcançar MAX, o loop
         * será encerrado.
         */
        while ( MAX & NUM ) {
            MASK = 1 ;
            i = j = 0 ;

            while ( MAX & MASK ) {
                /* Verdadeiro se NUM tem um bit 1
                 * na posição indicada por MASK. */
                if ( NUM & MASK ) {
                    /* Gera a combinação em str. */
                    str[i] = input[j] ;
                    i++ ;
                }
                j++ ;
                /* Desloca a máscara */
                MASK = MASK << 1 ;
            }

            str[i]=0 ;
            printf("%s\n", str) ;

            NUM++ ;
        }

        return 0;
    }
};
int VerificaMelhorRota(TListaCidade *CLista){ //Verificar a melhor rota possível;


};
