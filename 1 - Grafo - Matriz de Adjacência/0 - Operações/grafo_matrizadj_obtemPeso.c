#include <stdlib.h>
//#include "grafo_matrizadj_ponderado.h"
//#include "grafo_matrizadj_existeAresta.c"

Peso obtemPesoAresta(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return -1;

	if (existeAresta(grafo, v1, v2)){
		printf("O peso da aresta entre %d e %d é de %d\n", v1, v2, grafo->mat[v1][v2]);
		return grafo->mat[v1][v2];
	}
	printf("Não existe aresta entre os vértices %d e %d\n", v1, v2);
	return -1;
}
