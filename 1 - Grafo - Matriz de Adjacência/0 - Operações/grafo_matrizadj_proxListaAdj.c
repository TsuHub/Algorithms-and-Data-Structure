/*
	Retorna o próximo nó da lista de adjacência.
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
			printf("O próximo adjacente ao vértice %d é o %d.\n", vertice, i);
			return i;
		}
	}
	printf("O vértice %d não possui adjacentes.\n", vertice);
	return -1;
}

/*
	Implementação da professora:
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
 	
 	OBS: Não entendi o porquê do 'atual' e faltaria verificar o 'atual'
	     também.
*/