#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj_struct.h"
#include "grafo_listaadj_inicializa.c"
#include "grafo_listaadj_insere.c"

int main()
{
	Grafo grafo;
	
	printf("\n\nA estrutura aresta ocupa %dB na memória\n\n\n\n", sizeof(Aresta*));
	
	int numVertices;
	
	//inicializaGrafo(&grafo, 5);
	
	do{
		printf("Insira o número de vértices para o grafo\n");
		scanf("%d", &numVertices);
	} while(!inicializaGrafo(&grafo, numVertices));
	
	insereAresta(&grafo, 10, 1, 3);
	
	printf("O nº de arestas do grafo é de: %d\n", grafo.numArestas);
	printf("Peso da aresta entre os nós 1 e 3 é de: %d\n", grafo.listaAdj[1]->peso);
	printf("Endereço do nó 1 é: %p\n", grafo.listaAdj[1]);
	
	return 0;
}