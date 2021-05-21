#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj_struct.h"
#include "grafo_listaadj_inicializa.c"
#include "grafo_listaadj_insere.c"

int main()
{
	Grafo grafo;
	
	printf("\n\nA estrutura aresta ocupa %dB na mem�ria\n\n\n\n", sizeof(Aresta*));
	
	int numVertices;
	
	//inicializaGrafo(&grafo, 5);
	
	do{
		printf("Insira o n�mero de v�rtices para o grafo\n");
		scanf("%d", &numVertices);
	} while(!inicializaGrafo(&grafo, numVertices));
	
	insereAresta(&grafo, 10, 1, 3);
	
	printf("O n� de arestas do grafo � de: %d\n", grafo.numArestas);
	printf("Peso da aresta entre os n�s 1 e 3 � de: %d\n", grafo.listaAdj[1]->peso);
	printf("Endere�o do n� 1 �: %p\n", grafo.listaAdj[1]);
	
	return 0;
}