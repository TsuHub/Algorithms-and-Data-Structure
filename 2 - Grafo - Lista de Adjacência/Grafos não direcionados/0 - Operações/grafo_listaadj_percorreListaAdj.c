#include <stdio.h>

/*
	Esta fun��o tem por objetivo percorrer a lista de um
	dado v�rtice v1 at� um v�rtice v2, caso exista conex�o
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