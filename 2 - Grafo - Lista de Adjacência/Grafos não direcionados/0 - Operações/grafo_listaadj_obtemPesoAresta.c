#include <stdio.h>
//#include "grafo_listaadj_existeAresta.c"

Peso obtemPesoAresta(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return 0;
			
	if (!existeAresta(grafo, v1, v2))
		return 0;
	
	Apontador p;
	
	p = percorreListaAdj(grafo, v1, v2);
	
	return p->peso;	
}