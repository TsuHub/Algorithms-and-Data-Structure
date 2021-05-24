#include <stdlib.h>
#include <stdbool.h>
#include "grafo_listaadj_verifValidadeVert.c"
#include "grafo_listaadj_verifListaAdjVazia.c"

/*
	Esta vers�o 1 do insere "grafo_listaadj_insere_V1.c" � a
	vers�o da professora.
	
	Tenho a vers�o "grafo_listaadj_insere.c" que � a minha
	vers�o que faz mais sentido para mim, pode ser que exista
	algum bug, preciso testar mais vezes para saber. 
*/

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
	
	//if(!(grafo->listaAdj = (Aresta**)   calloc(1, sizeof(Aresta*)))){	// forma 1
	//if(!(grafo->listaAdj = (Apontador*) calloc(1, sizeof(Aresta)))){	// forma 1
	
	// forma 2
	if(!(p = (Apontador) calloc(1, sizeof(Aresta)))){		
	   	fprintf(stderr, "ERRO: Falha na aloca��o de mem�ria na fun��o insere Aresta\n");
        return false;
   	}
   	
   	// forma 2
   	p->vdest = v2;
   	p->peso = peso;
   	p->prox = grafo->listaAdj[v1];	//   p   ---> | 0 |
   	grafo->listaAdj[v1] = p;		// | 0 | ---> | 0 |
   	grafo->numArestas++;
	
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