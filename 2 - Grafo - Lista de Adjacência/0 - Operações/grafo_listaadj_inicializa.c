/*
#include <stdlib.h>
#include <stdbool.h>

bool inicializaGrafo(Grafo* grafo, int nv)
{
	if (nv <= 0){
		fprintf(stderr, "ERRO: A quantidade de vértices deve ser maior que 0");
		return false;
	}
	
	grafo->numVertices = nv;
	grafo->numArestas  = 0;
	
	return true;
}
//*/

///*
// Versão da professora

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool inicializaGrafo(Grafo* grafo, int nv){

	//int i;

	if (nv <= 0) {
		fprintf(stderr, "ERRO na chamada de inicializaGrafo: Número de vértices deve ser positivo.\n");
		return false;
	}

	grafo->numVertices = nv;
	if (!(grafo->listaAdj = (Aresta**) calloc(nv + 1, sizeof(Aresta*)))){
		fprintf(stderr, "ERRO: Falha na alocação de memória na função inicializaGrafo\n");
		return false;
	}

	grafo->numArestas = 0;
	return true;
}
//*/