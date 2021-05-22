#include <stdlib.h>
#include <stdbool.h>
//#include "grafo_listaadj_verifValidadeVert.c"
#include "grafo_listaadj_percorreListaAdj.c"

bool existeAresta(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return false;
	
	Apontador p = percorreListaAdj(grafo, v1, v2);
	
	if (p == NULL){
		printf("g_l_eA:    Não existe aresta entre os vértices %d e %d.\n", v1, v2);
		return false;
	}
	
	printf("g_l_eA:    Existe uma aresta de peso %d entre os nós %d e %d.\n", p->peso, v1, v2);
	return true;
}