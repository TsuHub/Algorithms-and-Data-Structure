#include <stdlib.h>

void imprimeGrafoMatrizAdj(Grafo* grafo)
{
	int i, j;
	
	printf("\n\nO Grafo: \n");
	
	for ( i = 0; i < grafo->numVertices; i++ )
	{
		printf("\n");
		
		for ( j = 0; j < grafo->numVertices; j++ )
		{
			if (grafo->mat[i][j] < 0 || grafo->mat[i][j] > 9)
			{
				printf("%d  ", grafo->mat[i][j]);
			}
			else
			{
				printf(" %d  ", grafo->mat[i][j]);
			}
		}
	}
	printf("\n\n\n");
}