#include <stdlib.h>
#include <stdbool.h>

bool verificaValidadeVertice(Grafo* grafo, int v)
{
	if (v < 0 || v >= grafo->numVertices){
		fprintf(stderr, "ERRO: O �ndice do v�rtice deve estar no intervalo de 0 a %d.\n", grafo->numVertices);
		return false;
	}
	return true;
}