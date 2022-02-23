#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arquivo.h"

///
/// \brief função para diferenciar o tipo da linha que esta sendo lida
/// \param linha linha lida do arquivo para determinar seu tipo
/// \return número que indica qual o tipo da linha
///
int tipo_linha(char linha[]){
    if(strncmp(linha,"orientado",9) == 0){
        return ORIENTADO;
    }
    else if (linha[0] == 'V'){
        return N_VERTICES;
    }
    else{
        return ARESTAS;
    }
}

///
/// \brief função que verifica qual o tipo de orientação que esta no arquivo e aloca a estrutura
/// \param linha linha do arquivo que sera lida
/// \return o grafo devidamente alocado e com seu tipo de orientação armazenado
///
Grafo* inicia_orientado(char linha[]){
    Grafo* novo;
    char orientado[4];

    novo = inicia_grafo(linha);

    return novo;
}

///
/// \brief função para alocar os campos da estrutura grafo
/// \param novo grafo que sera alocado
/// \return nenhum
///
void aloca_grafo(Grafo* novo){
    novo->pesos = aloca_inicial(novo->total_vertices);
    novo->adjacentes = aloca_inicial(novo->total_vertices);
}

///
/// \brief função responsavel para armazenar a quantidade total de vertices
/// \param linha linha do arquivo a ser lida
/// \param novo grafo aonde sera inserido os dados passados
/// \return nenhum
///
void inicia_n_vertices(int vertice, Grafo* novo){
    novo->total_vertices = vertice;
    
    aloca_grafo(novo);
}

///
/// \brief função responsavel para ler a linha de arestas do arquivo armazenando u, v e o peso no grafo
/// \param linha linha do arquivo a ser lida
/// \param novo grafo aonde sera inserido os dados passados
/// \return nenhum
///
void inicia_arestas(char linha[], Grafo* novo){
    char aux[300];
    int lin, col, peso, trace;

    sscanf(linha, "pode_ir(%*c%d, %*c%d, %d).%n", &lin, &col, &peso, &trace);

    lin--;
    col--;

    if((lin >= 0) && (col >= 0)){
        novo->adjacentes[lin][col] = 1;
        novo->pesos[lin][col] = peso;

        if(strcmp(novo->orientado, "nao") == 0){
            novo->adjacentes[col][lin] = 1;
            novo->pesos[col][lin] = peso;
        }
    }
}

int conta_vertice(FILE *entrada){
    char linha[500];
    int i=1, total;

    while(fgets(linha,500,entrada)){
        strtok(linha,"\n");
        int lin, col, peso, trace;
        sscanf(linha, "pode_ir(%*c%d, %*c%d", &lin,&col);

        if(i < col){
            i = col;
        }
    }

    return i;
}

///
/// \brief função que pega o arquivo aberto e lê as linhas dele armazenando em um grafo
/// \param entrada arquivo de onde sera lido o grafo
/// \return variavel do tipo Grafo contendo os dados passados pelo arquivo
///
Grafo* le_arq(FILE* entrada){
    Grafo* novo = NULL;
    FILE* teste = entrada;
    char linha[500];
    char orientado1[100] = {"nao"};
    char orientado2[100] = {"sim"};
    int i=1, total;

    total = conta_vertice(entrada);

    fseek(entrada, 0, SEEK_SET);

    while(fgets(linha,500,entrada)){
        strtok(linha,"\n");
        int lin, col, peso, trace;
        sscanf(linha, "pode_ir(%*c%d, %*c%d", &lin,&col);
        
        if(i == 1){
            novo = inicia_orientado(orientado1);
            inicia_n_vertices(total,novo);
        }else{
            inicia_arestas(linha, novo);
        }

        i++;
    }

    return novo;
}

///
/// \brief função que pega o arquivo aberto e lê as linhas dele armazenando em um grafo
/// \param entrada arquivo de onde sera lido o grafo
/// \return variavel do tipo Grafo contendo os dados passados pelo arquivo
///
Grafo* le_arq2(FILE* entrada){
    Grafo* novo = NULL;
    FILE* teste = entrada;
    char linha[500];
    char orientado[100] = {"sim"};
    int i=1, total;

    total = conta_vertice(entrada);

    fseek(entrada, 0, SEEK_SET);

    while(fgets(linha,500,entrada)){
        strtok(linha,"\n");
        int lin, col, peso, trace;
        sscanf(linha, "pode_ir(%*c%d, %*c%d", &lin,&col);
        
        if(i == 1){
            novo = inicia_orientado(orientado);
            inicia_n_vertices(total,novo);
        }else{
            inicia_arestas(linha, novo);
        }

        i++;
    }

    return novo;
}