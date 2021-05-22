#include <stdlib.h>
#include <stdbool.h>
//#include "grafo_listaadj_verifValidadeVert.c"

bool existeAresta(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return false;
	
	Apontador p;
	
	p = grafo->listaAdj[v1];
		
	while ( (p != NULL) && (p->vdest != v2)){
		p = p->prox;
	}
	
	if (p == NULL){
		printf("N�o existe aresta entre os v�rtices %d e %d.\n", v1, v2);
		return false;
	}
	
	printf("Existe uma aresta de peso %d entre os n�s %d e %d.", p->peso, v1, v2);
	return true;
}