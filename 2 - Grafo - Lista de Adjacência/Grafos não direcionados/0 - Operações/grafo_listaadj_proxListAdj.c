#include <stdio.h>
//#include "grafo_listaadj_verifValidadeVert.c"
//#include "grafo_listaadj_verifListaAdjVazia.c"

/*
	Esta fun��o tem como objetivo passar o pr�ximo v�rtice
	adjacente ao v�rtice passado como argumento.
	Retorna null caso n�o haja.
	
	Imagine o grafo abaixo
	
	
  Lista de	
 adjac�ncia
(� um vetor*)	   Pr�x da
	 |			   lista de
   	 |		      adjac�ncia	
	 |				  |
	 v	 	 	 	  v
	 	 	 	 	  
	 1   -> 4 -> 3 -> 5
	 2   -> 1
	 3   -> 4
	 4   -> 5 -> 1
	
	 
    O 'atual' � o elemento antecessor do 5, no caso o 3.
	Caso queiramos o pr�ximo adjacente do 3, da posi��o 1
	da lista de adjac�ncia, que � o 5, entramos com o
	endere�o de mem�ria do 3.
	
	
	grafo	: Estrutura que � o objeto que sofre a a��o.
	v		: �ndice da lista de adjac�ncia a ser trabalhada.
	atual	: Endere�o de mem�ria cujo o pr�ximo deste ser� retornado.
	
	
	*Um vetor alocado din�micamente.
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
	
	printf("g_l_pLA:   O pr�ximo adjacente ao v�rtice %d � o v�rtice %d, de aresta com peso %.1f.\n", v, grafo->listaAdj[v]->vdest, grafo->listaAdj[v]->peso);
	return(atual->prox);
}




