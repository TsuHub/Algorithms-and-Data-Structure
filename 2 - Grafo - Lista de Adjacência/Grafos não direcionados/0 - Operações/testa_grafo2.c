#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj_struct.h"
#include "grafo_listaadj_inicializa.c"
#include "grafo_listaadj_insere.c"
#include "grafo_listaadj_proxListAdj.c"
#include "grafo_listaadj_existeAresta.c"
#include "grafo_listaadj_obtemPesoAresta.c"
#include "grafo_listaadj_removeArestaObtendoPeso.c"
#include "grafo_listaadj_liberaGrafo.c"
#include "grafo_listaadj_leGrafo.c"
#include "grafo_listaadj_imprime.c"

int main()
{
	Grafo grafo;
	
	printf("\n\nt_g:       A estrutura aresta ocupa %d bytes na memória\n\n\n", sizeof(Aresta*));
	
	int numVertices;
	
	do{
		printf("t_g:       Insira o número de vértices para o grafo\n");
		scanf("%d", &numVertices);
	} while(!inicializaGrafo(&grafo, numVertices));
	
	imprimeGrafo(&grafo);
	
	insereAresta(&grafo, 2, 1, 2);
	imprimeGrafo(&grafo);

	//removeArestaObtendoPeso(&grafo, 2, 1, 2);
	//removeArestaObtendoPeso(&grafo, 2, 2, 1);
	//imprimeGrafo(&grafo);
	
	listaAdjVazia(&grafo, 1);
	
	insereAresta(&grafo, 3, 1, 3);
	imprimeGrafo(&grafo);
	
	
	//insereAresta(&grafo, 3, 1, 3);
	//imprimeGrafo(&grafo);
	
	
	return 0;
}