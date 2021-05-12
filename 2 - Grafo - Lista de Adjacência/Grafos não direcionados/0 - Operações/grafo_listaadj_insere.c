#include <stdlib.h>
#include <stdbool.h>
#include "grafo_listaadj_verifValidadeVert.c"
#include "grafo_listaadj_verifListaAdjVazia.c"

bool insereAresta(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2))){
		return false;
	}
	
	if (listaAdjVazia(grafo, v1)){
		grafo->listaAdj[v1].vdest = v2;
		grafo->listaAdj[v1].prox = grafo->listaAdj[v2];
	}
}