#include <stdlib.h>
#include <stdbool.h>
//#include "grafo_matrizadj_verifValidadeVert.c"
//#include "grafo_matrizadj_existeAresta.c"

bool removeAresta(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return false;
	
	if (existeAresta(grafo, v1, v2)){
		grafo->mat[v1][v2] = AN;
		printf("A aresta entre os vértices %d e %d foi removido com sucesso.\n", v1, v2);
		return true;
	}
	return false;
}