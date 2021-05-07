#include <stdlib.h>
#include <stdbool.h>
//#include "grafo_matrizadj_verifValidadeVert.c"
//#include "grafo_matrizadj_ponderado.c"

bool existeArestaAdj(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVert(grafo, v1) && verificaValidadeVert(grafo, v2))){
		fprintf(stderr, "ERRO: O �ndice do v�rtice deve estar no intervalo de 1 a %d", grafo->numVertices);
        return false;
	}
	
	if (grafo->mat[v1][v2] != AN){
		printf("Existe aresta entre os v�rtices %d e %d");
		return true;
	}
	
	else{
		printf("N�o existe aresta entre os v�rtices %d e %d");
		return false;
	}
}