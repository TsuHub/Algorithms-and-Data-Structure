#include <stdlib.h>
#include <stdbool.h>

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
		printf("A lista de adjacência do vértice %d está vazia.\n", v);
		return true;
	}
	printf("A lista de adjacência do vértice %d não está vazia.\n\n", v);
	return false;
	//*/
}