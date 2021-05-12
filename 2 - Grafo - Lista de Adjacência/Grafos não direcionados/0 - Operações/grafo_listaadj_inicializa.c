///*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool inicializaGrafo(Grafo* grafo, int nv)
{
	if (nv <= 0){
		fprintf(stderr, "ERRO: A quantidade de vértices deve ser maior que 0");
		return false;
	}
	
	grafo->numVertices = nv;
	grafo->numArestas  = 0;		// Esta linha na verdade é desnecessária, já
								// que o callo c já aloca os atributos de uma
								// estrutura como sendo zero.
	
	if (!(grafo->listaAdj = (Aresta**) calloc(nv, sizeof(Aresta*)))){
		fprintf(stderr, "ERRO: Falha na alocação de memória na função inicializaGrafo\n");
		return false;
	}
	printf("\nGrafo inicializado com sucesso.\n");
	
	return true;
}