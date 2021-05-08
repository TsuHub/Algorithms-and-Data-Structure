#include <stdlib.h>
#include <stdbool.h>

bool listaAdjVazia(Grafo* grafo, int vertice)
{
	if (!verificaValidadeVertice(grafo, vertice))
		return false;
	
	int i;
	for (i = 0; i < grafo->numVertices; i++)
	{
		if (grafo->mat[vertice][i] != AN){
			printf("O vértice %d possui adjacente(s).\n");
			return false;
		}
	}
	return true;
}