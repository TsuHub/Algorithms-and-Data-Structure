#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj_struct.h"
#include "grafo_listaadj_inicializa.c"
#include "grafo_listaadj_insere.c"
#include "grafo_listaadj_proxListAdj.c"
#include "grafo_listaadj_existeAresta.c"
#include "grafo_listaadj_obtemPesoAresta.c"
#include "grafo_listaadj_remove.c"

int main()
{
	Grafo grafo;
	
	printf("\n\nt_g:       A estrutura aresta ocupa %d bytes na mem�ria\n\n\n\n", sizeof(Aresta*));
	
	int numVertices;
	
	//inicializaGrafo(&grafo, 5);
	
	do{
		printf("t_g:       Insira o n�mero de v�rtices para o grafo\n");
		scanf("%d", &numVertices);
	} while(!inicializaGrafo(&grafo, numVertices));
	
	
	//==========================================================================	
	//==========================================================================
 	// CAMPO DE TESTES
 	
 	/*
 		Este campo � destinado para verificar se as fun��es implementadas
 		est�o funcionando corretamente.
 	*/
 	
 	listaAdjVazia(&grafo, 1);
	//if (listaAdjVazia(&grafo, 1)){
	//	printf("A lista de adjac�ncia do n� 1 est� vazia.\n");
	//}
	
	insereAresta(&grafo, 10, 1, 3);
	
	printf("t_g:       O n� de arestas do grafo � de: %d\n", grafo.numArestas);
	printf("t_g:       Peso da aresta entre os n�s 1 e 3 � de: %d\n", grafo.listaAdj[1]->peso);
	printf("t_g:       Endere�o do n� 1 na mem�ria �: %p\n", grafo.listaAdj[1]);
	
	listaAdjVazia(&grafo, 1);
	//if (!listaAdjVazia(&grafo, 1)){
	//	printf("A lista de adjac�ncia do n� 1 n�o est� vazia.\n");
	//}
	
	// Como criar uma aresta para colocar como argumento na fun��o
	// proxListaAdj()?
	
	
	printf("\n");
	Aresta* aresta;
	aresta = grafo.listaAdj[1];
	
	proxListaAdj(&grafo, 1, aresta);
	
	existeAresta(&grafo, 1, 2);
	existeAresta(&grafo, 1, 3);
	
	Peso peso = obtemPesoAresta(&grafo, 1, 3);
	printf("t_g:       O peso da aresta entre os n�s %d e %d � de: %d\n", 1, 3, peso);

	removeArestaObtendoPeso(&grafo, 10, 1, 3);
	
	
	//==========================================================================
	//==========================================================================
	
	printf("\n\n");
	
	return 0;
}