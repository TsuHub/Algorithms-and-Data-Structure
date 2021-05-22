#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj_struct.h"
#include "grafo_listaadj_inicializa.c"
#include "grafo_listaadj_insere.c"
#include "grafo_listaadj_proxListAdj.c"
#include "grafo_listaadj_existeAresta.c"

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
	
	
	//==========================================================================	
	//==========================================================================
 	// CAMPO DE TESTES
 	
 	/*
 		Este campo é destinado para verificar se as funções implementadas
 		estão funcionando corretamente.
 	*/
 	
 	listaAdjVazia(&grafo, 1);
	//if (listaAdjVazia(&grafo, 1)){
	//	printf("A lista de adjacência do nó 1 está vazia.\n");
	//}
	
	insereAresta(&grafo, 10, 1, 3);
	
	printf("O nº de arestas do grafo é de: %d\n", grafo.numArestas);
	printf("Peso da aresta entre os nós 1 e 3 é de: %d\n", grafo.listaAdj[1]->peso);
	printf("Endereço do nó 1 é: %p\n", grafo.listaAdj[1]);
	
	listaAdjVazia(&grafo, 1);
	//if (!listaAdjVazia(&grafo, 1)){
	//	printf("A lista de adjacência do nó 1 não está vazia.\n");
	//}
	
	// Como criar uma aresta para colocar como argumento na função
	// proxListaAdj()?
	
	
	printf("\n\n");
	Aresta* aresta;
	aresta = grafo.listaAdj[1];
	
	proxListaAdj(&grafo, 1, aresta);
	
	existeAresta(&grafo, 1, 2);
	existeAresta(&grafo, 1, 3);

	//==========================================================================
	//==========================================================================
	
	printf("\n\n");
	
	return 0;
}