#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj_struct.h"
#include "grafo_listaadj_inicializa.c"
#include "grafo_listaadj_insere.c"

int main()
{
	Grafo grafo;
	
	printf("A estrutura aresta ocupa %dB na mem�ria\n", sizeof(Aresta*));
	
	int numVertices;
	
	//inicializaGrafo(&grafo, 5);
	
	do{
		printf("Insira o n�mero de v�rtices para o grafo\n");
		scanf("%d", &numVertices);
	} while(!inicializaGrafo(&grafo, numVertices));
	
	insereAresta(&grafo, 10, 1, 3);
		
	return 0;
}