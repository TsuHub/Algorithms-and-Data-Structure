#include <stdio.h>
#include <stdbool.h>

bool inicializaGrafoMatrizAdj(Grafo* grafo, int nv)
{
	int i, j;
	
	if (nv > MAXNUMVERTICES)
	{
		fprintf(stderr, "ERRO na chamada de inicializaGrafo: N�mero de\
						v�rtices maior que o m�ximo permitido de %d.\n", MAXNUMVERTICES);
        return false;
	}
	
	if (nv < 0)
	{
		fprintf(stderr, "ERRO na chamada de inicializaGrfo: N�mero de v�rtices\
						deve ser positivo.\n");
        return false;
	}
	
	grafo->numVertices = nv;
	grafo->numArestas = 0;
	
	for (i = 0; i <= grafo->numVertices; i++)
	{
		for (j = 0; j < grafo->numVertices; j++)
		{
			grafo->mat[i][j] = AN;
		}
	}
	return true;
}