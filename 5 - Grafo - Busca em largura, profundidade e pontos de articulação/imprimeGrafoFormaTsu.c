#include <stdio.h>

/*
 | 0 | 	---> 4 -> 3 -> 5
 | 1 |	---> 1
 | 2 | 	---> 4
 | 3 | 	---> 5 -> 1
*/

void imprimeGrafoFormaTsu(Grafo* grafo)
{
	printf("\n\n");
	
	Apontador p;
	
	int i;
	for (i = 0; i < grafo->numVertices; i++)
	{
		p = grafo->listaAdj[i];
		
		printf("| %d |   ", i);
		
		while (p != NULL){
			if (p->vdest < 10)
				printf("   (%.1f)->   %d", p->peso, p->vdest);

			else
				printf("  (%.1f)->   %d", p->peso, p->vdest);
			p = p->prox;
		}
		printf("\n");
	}
	printf("\n\n");
}