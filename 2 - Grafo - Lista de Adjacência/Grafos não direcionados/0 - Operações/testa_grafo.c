#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj_struct.h"
#include "grafo_listaadj_inicializa.c"
#include "grafo_listaadj_insere.c"

int main()
{
	Grafo grafo;
	int numVertices;
	
	//inicializaGrafo(&grafo, 5);
	
	do{
		printf("Insira o número de vértices para o grafo\n");
		scanf("%d", &numVertices);
	} while(!inicializaGrafo(&grafo, numVertices));
	
	insereAresta(&grafo, 1, 3);
		
	return 0;
}