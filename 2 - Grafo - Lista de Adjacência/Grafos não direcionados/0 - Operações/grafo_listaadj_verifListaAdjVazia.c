#include <stdlib.h>
#include <stdbool.h>

/*
	bool listaAdjVazia(Grafo* grafo, int v)
	retorna true se a lista de adjac�ncia (de v�rtices adjacentes)
	do v�rtice v � vazia, e false caso contr�rio.
*/

bool listaAdjVazia(Grafo* grafo, int v)
{
	if (!(verificaValidadeVertice(grafo, v)))
		return false;
	//return (grafo->listaAdj[v] == NULL);
	
	///*
	if (grafo->listaAdj[v] == NULL){
		printf("A lista de adjac�ncia do v�rtice %d est� vazia.\n", v);
		return true;
	}
	printf("A lista de adjac�ncia do v�rtice %d n�o est� vazia.\n\n", v);
	return false;
	//*/
}