#include <stdio.h>
//#include "grafo_listaadj_verifValidadeVert.c"
//#include "grafo_listaadj_verifListaAdjVazia.c"

/*
	Esta função tem como objetivo passar o próximo vértice
	adjacente ao vértice passado como argumento.
	Retorna null caso não haja.
	
	Imagine o grafo abaixo
	
	
  Lista de	
 adjacência
(é um vetor*)	   Próx da
	 |			   lista de
   	 |		      adjacência	
	 |				  |
	 v	 	 	 	  v
	 	 	 	 	  
	 1   -> 4 -> 3 -> 5
	 2   -> 1
	 3   -> 4
	 4   -> 5 -> 1
	
	 
    O 'atual' é o elemento antecessor do 5, no caso o 3.
	Caso queiramos o próximo adjacente do 3, da posição 1
	da lista de adjacência, que é o 5, entramos com o
	endereço de memória do 3.
	
	
	grafo	: Estrutura que é o objeto que sofre a ação.
	v		: Índice da lista de adjacência a ser trabalhada.
	atual	: Endereço de memória cujo o próximo deste será retornado.
	
	
	*Um vetor alocado dinâmicamente.
*/


//Apontador proxListaAdj(Grafo* grafo, int v)
Aresta* proxListaAdj(Grafo* grafo, int v, Aresta* atual)
{
	if (listaAdjVazia(grafo, v)){
		return NULL;
	}
	
	if (atual == NULL){
		fprintf(stderr, "g_l_pLA:   atual == NULL\n");
		return VERTICE_INVALIDO;
	}
	
	printf("g_l_pLA:   O próximo adjacente ao vértice %d é o vértice %d, de aresta com peso %.1f.\n", v, grafo->listaAdj[v]->vdest, grafo->listaAdj[v]->peso);
	return(atual->prox);
}




