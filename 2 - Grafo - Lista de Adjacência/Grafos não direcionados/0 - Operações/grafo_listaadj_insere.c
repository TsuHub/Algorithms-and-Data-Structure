#include <stdlib.h>
#include <stdbool.h>
#include "grafo_listaadj_verifValidadeVert.c"
#include "grafo_listaadj_verifListaAdjVazia.c"

/*
	va � o n� alvo que receber� o adjacente.
	vd � o n� de destino.
	
		
  Lista de	
 adjac�ncia
(� um vetor*)
 listaAdj[v]	   Pr�x da
	 |			   lista de
   	 |		      adjac�ncia
   	 |	     (grafo->listaAdj[va])
     |				  |
	 |		   -------
	 |		  |		  
	 v	 	  v	 	  
	 	 	 	 	  
(v)  1   ---> 4 -> 3 -> 5
	 2   ---> 1
	 3   ---> 4
	 4   ---> 5 -> 1
	 
  	 	  ^   
	      |
       Aresta*
	 (Apontador)
	 
	 
	 
	( grafo->listaAdj[v]->prox )  ==  ( grafo->listaAdj[v1] ) 
	 
*/

bool insereAresta(Grafo* grafo, Peso peso, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2))){
		return false;
	}

	Apontador p;						// forma 2
	
	//if(!(grafo->listaAdj = (Aresta**) calloc(1, sizeof(Aresta*)))){	// forma 1
	//if(!(grafo->listaAdj = (Apontador*) calloc(1, sizeof(Aresta)))){	// forma 1
	
	// forma 2
	if(!(p = (Apontador) calloc(1, sizeof(Aresta)))){		
	   	fprintf(stderr, "ERRO: Falha na aloca��o de mem�ria na fun��o insere Aresta\n");
        return false;
   	}
   	
   	p->vdest = v2;						// forma 2
   	p->peso = peso;						// forma 2
   	p->prox = grafo->listaAdj[v1];		// forma 2
   	
   	grafo->listaAdj[v1] = p;			// forma 2
   	grafo->numArestas++;				// forma 2
	
	printf("A aresta de peso %d foi inserida entre os n�s %d e %d.\n", peso, v1, v2);
	
	   
    /*
	   Este � o uso da forma 1, onde fa�o uso direto da estruturas de
       Grafo, mas esta maneira n�o funciona. Aparentemente tenho que
	   fazer um ponteiro 'p' do tipo Apontador e depois passar 'p'
	   para grafo->listaAdj[v1]. 
	*/
	//grafo->listaAdj[v1]->vdest = v2;						// forma 1
	//grafo->listaAdj[v1]->peso = peso;						// forma 1
	//grafo->listaAdj[v1]->prox = grafo->listaAdj[v1];		// forma 1
	//grafo->numArestas++;									// forma 1

	
	return true;
}