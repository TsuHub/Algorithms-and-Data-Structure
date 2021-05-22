#include <stdio.h>

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