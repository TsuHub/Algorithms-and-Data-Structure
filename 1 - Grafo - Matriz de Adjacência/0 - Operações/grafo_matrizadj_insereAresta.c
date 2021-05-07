#include <stdlib.h>
#include "grafo_matrizadj_verifValidadeVert.c"

void insereAresta(Grafo* grafo, int v1, int v2, Peso peso)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return;
	
	grafo->numArestas++;
	
	grafo->mat[v1][v2] = peso;
	
	printf("\nInserção feita com sucesso.\n");
}