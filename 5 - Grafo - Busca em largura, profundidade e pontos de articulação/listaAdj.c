#include <stdio.h>		// Para fazer a impressão da chamada de erros.
#include <stdlib.h>		// Para alocações dinâmicas.
#include <stdbool.h>	// Para usar os valores de retorno booleanos.
#include "listaAdj.h"

/*

  Lista de	
 adjacência
(é um vetor*)
 listaAdj[v]	   Próx da
	 |			   lista de
   	 |		      adjacência
   	 |	     (grafo->listaAdj[va])
     |				  |
	 |		    ------
	 |		   |		  
	 v	 	   v	 	  
	 
	 0	 ---> NULL
     1   ---> NULL
	 2   ---> NULL
	 3   ---> NULL
	 4   ---> NULL
	...
  nv - 1 
  	 	  ^
  	 	  |
	      |
       Aresta*
	 (Apontador)
	 
*/

//=====================================================================================================
// INICIALIZA GRAFO

bool inicializaGrafo(Grafo* grafo, int nv)
{
	if (nv <= 0){
		fprintf(stderr, "g_l_i:     ERRO: A quantidade de vértices deve ser maior que 0");
		return false;
	}
	
	grafo->numVertices = nv;
	grafo->numArestas  = 0;		// Esta linha na verdade é desnecessária, já
								// que o calloc já aloca os atributos de uma
								// estrutura como sendo zero.
	
	//if (!(grafo->listaAdj = (Aresta**) calloc(nv, sizeof(Aresta*)))){
    // Atualizado o ponteiro do tipo aresta como sendo Apontador.
	if (!(grafo->listaAdj = (Apontador*) calloc(nv, sizeof(Apontador)))){
		fprintf(stderr, "g_l_i:     ERRO: Falha na alocação de memória na função inicializaGrafo\n");
		return false;
	}
	printf("\ng_l_i:     Grafo inicializado com sucesso.\n");
	
	return true;
}

//=====================================================================================================
// VERIFICA VALIDADE VÉRTICE

bool verificaValidadeVertice(Grafo* grafo, int v)
{
	if (v < 0 || v >= grafo->numVertices){
		fprintf(stderr, "g_l_vVV:   ERRO: O índice do vértice deve estar no intervalo de 0 a %d.\n", grafo->numVertices);
		return false;
	}
	return true;
}

//=====================================================================================================
// LISTA DE ADJACÊNCIA VAZIA
/*
	bool listaAdjVazia(Grafo* grafo, int v)
	retorna true se a lista de adjacência (de vértices adjacentes)
	do vértice v é vazia, e false caso contrário.
*/

bool listaAdjVazia(Grafo* grafo, int v)
{
	if (!(verificaValidadeVertice(grafo, v)))
		return false;
	//return (grafo->listaAdj[v] == NULL);
	
	///*
	if (grafo->listaAdj[v] == NULL){
		//printf("g_l_vLAV:  A lista de adjacência do vértice %d está vazia.\n", v);
		return true;
	}
	//printf("g_l_vLAV:  A lista de adjacência do vértice %d não está vazia.\n\n", v);
	return false;
	//*/
}

//=====================================================================================================
// INSERE ARESTA

// Função para grafos não dirigidos
void atribuiAresta(Grafo* grafo, Peso peso, int vAlvo, int vDest)
{
	// Criando a aresta que será inserida entre
	// os vértices vAlvo e vDest
	Apontador p;
	Apontador pAux;
	
	if(!(p = (Apontador) calloc(1, sizeof(Aresta))))
	   	fprintf(stderr, "g_l_i:     ERRO: Falha na alocação de memória na função insere Aresta\n");

	// Inicizalizando a aresta que será inserida entre os vértices
	p->vdest = vDest;
   	p->peso  = peso;
   	
   	// Se a lista for vazia, não há uma próxima aresta
   	if (!listaAdjVazia(grafo, vAlvo)){
		pAux = grafo->listaAdj[vAlvo];
		p->prox = pAux;
	}
	
	else p->prox = NULL;					//	 p	 ---> NULL
	grafo->listaAdj[vAlvo] = p;				// | 0 | ---> NULL
}

bool insereAresta(Grafo* grafo, Peso peso, int vAlvo, int vDest)
{
	if (!(verificaValidadeVertice(grafo, vAlvo) && verificaValidadeVertice(grafo, vDest))){
		return false;
	}
   	
   	/*
	   Como estamos tratando de um grafo não direcionado
	   precisamos conectar a aresta de vAlvo para vDest
	   e fazer o inverso também, de vDest para vAlvo.
   	*/
   	
    atribuiAresta(grafo, peso, vAlvo, vDest);
    atribuiAresta(grafo, peso, vDest, vAlvo);
    
	printf("g_l_i:     A aresta de peso %.1f foi inserida entre os nós %d e %d.\n", peso, vAlvo, vDest);
   	
   	grafo->numArestas++;
	
	return true;
}

//=====================================================================================================
// PERCORRE LISTA DE ADJACÊNCIA
/*
	Esta função tem por objetivo percorrer a lista de um
	dado vértice v1 até um vértice v2, caso exista conexão
	entre eles.
*/

Apontador percorreListaAdj(Grafo* grafo, int v1, int v2)
{
	Apontador p;
	
	p = grafo->listaAdj[v1];
	
	while (p != NULL && p->vdest != v2)
		p = p->prox;
	
	if (p == NULL)
		return NULL;
	
	return p;
}

//=====================================================================================================
// VERIFICA EXISTÊNCIA DE ARESTA

bool existeAresta(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return false;
	
	Apontador p = percorreListaAdj(grafo, v1, v2);
	
	if (p == NULL){
		printf("g_l_eA:    Não existe aresta entre os vértices %d e %d.\n", v1, v2);
		return false;
	}
	
	printf("g_l_eA:    Existe uma aresta de peso %.1f entre os nós %d e %d.\n", p->peso, v1, v2);
	return true;
}

//=====================================================================================================
// LIBERA GRAFO

void liberaGrafo(Grafo* grafo)
{
	int v;
	Apontador p;

	// Libera a lista de adjacência de cada vértice
	for (v = 0; v <= grafo->numVertices; v++)
	{
		while ((p = grafo->listaAdj[v]) != NULL)
		{
			grafo->listaAdj[v] = p->prox;
			p->prox = NULL;
			free(p);
		}
	}
	grafo->numVertices = 0;

	//Libera o vetor de ponteiros para as listas de adjacência
	free(grafo->listaAdj);
	grafo->listaAdj = NULL;
	
	printf("g_l_lG:    O grafo foi liberado.\n\n");
}