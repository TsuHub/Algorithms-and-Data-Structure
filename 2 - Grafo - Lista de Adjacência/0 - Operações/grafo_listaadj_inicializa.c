/*
#include <stdlib.h>
#include <stdbool.h>

bool inicializaGrafo(Grafo* grafo, int nv)
{
	if (nv <= 0){
		fprintf(stderr, "ERRO: A quantidade de v�rtices deve ser maior que 0");
		return false;
	}
	
	grafo->numVertices = nv;
	grafo->numArestas  = 0;
	
	return true;
}
//*/

///*
// Vers�o da professora

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool inicializaGrafo(Grafo* grafo, int nv){

	//int i;

	if (nv <= 0) {
		fprintf(stderr, "ERRO na chamada de inicializaGrafo: N�mero de v�rtices deve ser positivo.\n");
		return false;
	}

	grafo->numVertices = nv;
	if (!(grafo->listaAdj = (Aresta**) calloc(nv + 1, sizeof(Aresta*)))){
		fprintf(stderr, "ERRO: Falha na aloca��o de mem�ria na fun��o inicializaGrafo\n");
		return false;
	}

	grafo->numArestas = 0;
	return true;
}
//*/