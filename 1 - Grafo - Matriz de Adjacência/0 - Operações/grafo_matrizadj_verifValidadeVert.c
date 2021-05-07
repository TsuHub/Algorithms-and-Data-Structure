#include <stdlib.h>
#include <stdbool.h>

bool verificaValidadeVertice(Grafo* grafo, int vertice)
{
	if (vertice <= 0 || vertice > grafo->numVertices){
		fprintf(stderr, "ERRO: O índice do vértice deve estar no intervalo de 1 a %d", grafo->numVertices);
        return false;
	}
	return true;
}