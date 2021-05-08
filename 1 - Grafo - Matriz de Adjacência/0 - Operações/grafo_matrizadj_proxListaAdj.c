/*
	Retorna o pr�ximo n� da lista de adjac�ncia.
*/

#include <stdlib.h>

int proxListaAdj(Grafo* grafo, int vertice)
{
	if (!(verificaValidadeVertice(grafo, vertice)))
		return -1;
	
	int i;
	for (i = 0; i < grafo->numVertices; i++)
	{
		if (grafo->mat[vertice][i] != AN){
			printf("O pr�ximo adjacente ao v�rtice %d � o %d.\n", vertice, i);
			return i;
		}
	}
	printf("O v�rtice %d n�o possui adjacentes.\n", vertice);
	return -1;
}

/*
	Implementa��o da professora:
	.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
	
int proxListaAdj(int v, Grafo* grafo, int atual){
	
	if (!verificaValidadeVertice(v, grafo))
		return VERTICE_INVALIDO;
	
	atual++;
	while ((atual <= grafo->numVertices) && (grafo->mat[v][atual] == AN))
		atual++;
		
    if (atual > grafo->numVertices)
    	return VERTICE_INVALIDO;
    	
 	return atual;
 	
 	.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
 	
 	OBS: N�o entendi o porqu� do 'atual' e faltaria verificar o 'atual'
	     tamb�m.
*/