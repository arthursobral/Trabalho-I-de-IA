#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include "arquivo.h"
#include "grafo.h"
#include "fila.h"
#include <string.h>

// estrutura para o algoritmo de profundidade
typedef struct profundidade{
    // cor do vertice
    char cor;
    // vertice pai desse vertice
    int pred;
    // tempo de descoberta e de final de exploração
    int d, f;
    // vertices adjacentes a esse vertice
    int *adj;

} Profundidade;

// estrutura para o algoritmo de largura
typedef struct largura{

    // cor do vertice
    char cor;
    // vertice que precede esse vertice
    int pred;
    // distancia do nó origem
    int d;
    // vertices adjacentes
    int *adj;
} Largura;

// estrutura para o algoritmo de Bellman-Ford
typedef struct bellmanford {
    // peso para chegar nesse vertice
    int d;
    // vertice que precede esse
    int pred;
} BellmanFord;

typedef struct aresta {
    // vertice de origem da aresta, vertice de destino da aresta
    int u, v;
    // peso da aresta
    int peso;
} Aresta;

// variavel para guardar o tempo de descoberta para o algoritmo de profundidade
int timestamp;

///
/// \brief menu para a escolha dos algoritmos
/// \param g grafo onde sera realizado os algoritmos
/// \return nenhum
///
void menu_algoritmos(Grafo *g, Grafo *bellman);

///
/// \brief funcao que visita e atualiza os campos e comeca uma nova busca a partir dele
/// \param vertice vertice que esta sendo visitado
/// \param busca estrutura responsavel por guardar a instacia do algortimo
/// \param n total de vertices
/// \return nenhum 
///
void visita_profundidade(int vertice, Profundidade* busca, int n, int buscando);

///
/// \brief  algoritmo de busca em profundidade
/// \param  g: grafo a ser feito a busca
/// \param  inicial: vertice origem
/// \return nenhum
///
void buscaProfundidade(Grafo *g, int inicial, int buscando);

///
/// \brief  algoritmo de busca em largura
/// \param  g: grafo a ser feito a busca
/// \param  origem: vertice origem
/// \return 
///
int buscaLargura(Grafo *g, int origem, int buscando);

///
/// \brief funcao auxiliar do algoritmo de Kruskal, para percorrer as arestas e verificar se ja existe
/// \param  i vertice de origem da aresta a ser verificada
/// \param  j vertice de destino da aresta
/// \param  peso peso da aresta i indo para j
/// \param  e vetor de Aresta guardadas
/// \param  n tamanho do vetor de Aresta
/// \return 1 se existe ou 0 se nao existe 
///
int jaExiste(int i, int j, int peso, Aresta* e, int n);

///
/// \brief funcao que cria as arestas
/// \param g grafo a ter suas arestas verificadas
/// \param n variavel que guarda a quantidade de arestas existentes
/// \return retorna um vetor de arestas com todas as arestas do grafo
///
Aresta* fazAresta(Grafo *g, int *n);

///
/// \brief funcao auxiliar do metodod Bellman-Ford para realizar a verificao do menor caminho
/// \param bf estrutura para armazenar a instacia do algoritmo
/// \param pesos matriz de pesos de cada aresta
/// \param u vertice de origem da aresta
/// \param v vertice de destino da aresta
/// \return nenhum
///
void relax(BellmanFord* bf, int** pesos, int u, int v);

///
/// \brief funcao inicial para o algoritmo de Bellman-Ford
/// \param n quantidade de vertices total
/// \param origem vertice origem do algoritmo
/// \return variavel inicializada
///
BellmanFord* inicializaorigem(int n, int origem);

///
/// \brief funcao para realizar o algoritmo de Bellman-Ford
/// \param g grafo onde vai ser buscado o menor caminho
/// \param origem vertice origem da busca
/// \return 1 caso o algoritmo foi realizado com sucesso e 0 caso contrario 
///
int Bellman(Grafo *g, int origem, int buscando);

#endif // ALGORITMOS_H