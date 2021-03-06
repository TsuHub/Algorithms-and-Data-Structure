#include <stdlib.h>
#include <stdbool.h>
//#include "grafo_matrizadj_verifValidadeVert.c"
//#include "grafo_matrizadj_existeAresta.c"

/*
	A professora guarda o valor do peso em um ponteiro *peso
	antes de atualizar o peso para AN. 
*/
bool removeAresta(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return false;
	
	if (existeAresta(grafo, v1, v2)){
		grafo->numArestas--;
		grafo->mat[v1][v2] = AN;
		printf("A aresta entre os v?rtices %d e %d foi removido com sucesso.\n", v1, v2);
		return true;
	}
	return false;
}