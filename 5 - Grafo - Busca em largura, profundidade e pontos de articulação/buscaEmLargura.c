/*
    A busca em largura é um algoritmo útil para descobrir o caminho
    mais curto de um vértice a outro em termo de número de arestas,
    i.e., não considerando os pesos das arestas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.c"

#define BRANCO 0
#define CINZA  1
#define PRETO  2
#define INFINITO 1000

Fila fila;
int* vIndicesBL;
int* ptr;
int* camBL;

int caminhosBL(int* ant, int ind)
{
    if (ind == -1){
        printf("\n");
        return 0;
    }

	if (ind != 0){
		caminhosBL(ant, ant[ind]);
		printf("%d ", ind);
		return 0;
	}
	printf("\n%d ", ind);
	return 0;
}

void visitaLargura(int s, Grafo* grafo, int* cor, int* antecessor, int* distancia)
{
    cor[s] = CINZA;
    distancia[s] = 0;

    //printf("%d : CINZA\n\n", s);

    if (fila.tamanho == 0)
        insereElementoFila(&fila, s);

    while (fila.tamanho != 0)
    {
        int w = retiraElementoFila(&fila);

        Apontador p = grafo->listaAdj[w];

        int u;
        while (p != NULL)
        {
            u = p->vdest;

            if (cor[u] == BRANCO)
            {
                cor[u] = CINZA;
                antecessor[u] = w;
                distancia[u] = distancia[w] + 1;
                insereElementoFila(&fila, u);
            }
            p = p->prox;
        }
        cor[w] = PRETO;

        //printf("%d : PRETO\n\n", w);

        vIndicesBL[*ptr] = w;
        *ptr = *ptr + 1;
    }
}

void buscaEmLargura(Grafo* grafo)
{
    int nV = grafo->numVertices;
	
    inicializaFila(&fila);

    vIndicesBL = calloc(nV, sizeof(int));
    int aux = 0;
    ptr = &aux;

	int* cor = (int*) malloc(nV * sizeof(int));
	int* antecessor = (int*) malloc(nV * sizeof(int));
	int* distancia = (int*) malloc(nV * sizeof(int));

    int v;
    for (v = 0; v < nV; v++)
    {
        cor[v] = BRANCO;
        antecessor[v] = -1;
        distancia[v] = INFINITO;
    }

    for (v = 0; v < nV; v++){
        if (cor[v] == BRANCO)
            visitaLargura(v, grafo, cor, antecessor, distancia);
    }

    liberaFila(&fila);

    //==========================================================================
    // Imprimindo o BL no terminal
    /*
    printf("BL:\n");
    int a;
    for (a = 0; a < nV; a++){
        printf("%d ", vIndicesBL[a]);
    }
    printf("\n\n\n");
    //*/
	//==========================================================================

    camBL = calloc(nV, sizeof(int));
    int i;
    for (i = 0; i < nV; i++)
        camBL[i] = antecessor[i];

	//==========================================================================
	// CAMINHOS BL
	/*
	printf("Caminhos BL:");

	int indice;
	for (indice = 0; indice < nV; indice++){
		caminhosBL(camBL, indice);
	}
	printf("\n\n\n");
	//*/

    free(cor);
    free(antecessor);
    free(distancia);
}