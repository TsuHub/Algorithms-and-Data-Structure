#include <stdio.h>
#include "grafo_matrizadj_ponderado.h"
#include "grafo_matrizadj_inicializa.c"
#include "grafo_matrizadj_imprime.c"
#include "grafo_matrizadj_insereAresta.c"
#include "grafo_matrizadj_existeAresta.c"
#include "grafo_matrizadj_obtemPeso.c"
#include "grafo_matrizadj_removeAresta.c"
#include "grafo_matrizadj_listaAdjVazia.c"
#include "grafo_matrizadj_proxListaAdj.c"

int main()
{
	Grafo grafo;
	//int numVertices = 10;
	int numVertices;
	
	//inicializaGrafoAdj(&grafo, numVertices);
	
	do {
		printf("Digite o número de vértices do grafo\n");
		scanf("%d", &numVertices);
	} while (!inicializaGrafoMatrizAdj(&grafo, numVertices));

	//imprimeGrafoMatrizAdj(&grafo);
			
	//grafo.mat[0][1] = 1;
	//grafo.mat[2][1] = 10;
	
	insereAresta(&grafo, 1, 1, 2);
	insereAresta(&grafo, 2, 1, 10);
	
	imprimeGrafoMatrizAdj(&grafo);
	
	existeAresta(&grafo, 2, 1);
	
	obtemPesoAresta(&grafo, 1, 1);
	
	removeAresta(&grafo, 1, 1);
	
	imprimeGrafoMatrizAdj(&grafo);
	
	listaAdjVazia(&grafo, 2);
	
	proxListaAdj(&grafo, 2);
	
	return 0;
}