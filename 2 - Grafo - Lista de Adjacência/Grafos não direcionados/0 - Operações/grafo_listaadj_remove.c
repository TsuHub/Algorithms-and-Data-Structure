#include <stdbool.h>

bool removeArestaObtendoPeso(Grafo* grafo, Peso peso, int v1, int v2)
{
	Apontador q, ant;

	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return AN;

	q = grafo->listaAdj[v1];

	while ((q != NULL) && (q->vdest != v2)){
		ant = q;
		q = q->prox;
	}

	//aresta existe
	if (q != NULL){
		if (grafo->listaAdj[v1] == q)
			grafo->listaAdj[v1] = q->prox;
		else ant->prox = q->prox;
		peso = q->peso;
		q->prox = NULL;
		free(q);
		q = NULL;
		printf("g_l_r:     O peso %d foi removido entre os n�s %d e %d.\n", peso, v1, v2);
		
		return true;
	}

	//aresta n�o existe
	return false;	
}