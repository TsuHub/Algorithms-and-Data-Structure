#include <stdlib.h>
#include <stdbool.h>
#include "grafo_listaadj_verifValidadeVert.c"
#include "grafo_listaadj_verifListaAdjVazia.c"

/*
	Existe a versão 1 (V1) do insere "grafo_listaadj_insere_V1.c"
	que é a versão da professora.
	
	Tenho a versão "grafo_listaadj_insere.c" que é a minha
	versão que faz mais sentido para mim, pode ser que exista
	algum bug, preciso testar mais vezes para saber. 
*/

/*
	vAlvo é o vértice alvo que receberá o adjacente.
	vDest é o vértice de destino.
	
		
	  Lista de	
	 adjacência
	(é um vetor*)
grafo->listaAdj[vAlvo]
		  |
		  |
		  |			  Próx da
		  |	    lista de adjacência
		  |(grafo->listaAdj[vAlvo]->prox)
		  |		  		 | 
		  v				 v	 	  
	 	 	 	 	  
		  1   	--->	 4 -> 3 -> 5
		  2   	--->	 1
		  3   	--->	 4
		  4   	--->	 5 -> 1
	 
  	 	  ^   
	      |
       Aresta*
	 (Apontador)
	 
	 
	 
	( grafo->listaAdj[v]->prox )  ==  ( grafo->listaAdj[v1] ) 
	 
*/

void atribuiAresta(Grafo* grafo, Peso peso, int vAlvo, int vDest)
{
	Apontador p;
	
	if(!(p = (Apontador) calloc(1, sizeof(Aresta)))){		
	   	fprintf(stderr, "g_l_i:     ERRO: Falha na alocação de memória na função insere Aresta\n");
   	}

	p->vdest = vDest;
   	p->peso  = peso;
   	p->prox  = grafo->listaAdj[vAlvo];	//	 p	 ---> | 0 |
	grafo->listaAdj[vAlvo] = p;			// | 0 | ---> | 0 |
	pAux->vdest = grafo->listaAdj[vAlvo];	   
}

/*
	p	---> 4

	1   ---> 3 -> 5
	
	1   ---> 3 -> 5
*/

bool insereAresta(Grafo* grafo, Peso peso, int vAlvo, int vDest)
{
	if (!(verificaValidadeVertice(grafo, vAlvo) && verificaValidadeVertice(grafo, vDest))){
		return false;
	}
		
	//if(!(grafo->listaAdj = (Aresta**)   calloc(1, sizeof(Aresta*)))){	// forma 1
	//if(!(grafo->listaAdj = (Apontador*) calloc(1, sizeof(Aresta)))){	// forma 1
	
	/*
	if(!(p = (Apontador) calloc(1, sizeof(Aresta)))){		
	   	fprintf(stderr, "ERRO: Falha na alocação de memória na função insere Aresta\n");
	   	return false;
   	}
   	*/
   	
   	/*
	   Como estamos tratando de um grafo não direcionado
	   precisamos conectar a aresta de vAlvo para vDest
	   e fazer o inverso também, de vDest para vAlvo.
   	*/
   	
    atribuiAresta(grafo, peso, vAlvo, vDest);
    atribuiAresta(grafo, peso, vDest, vAlvo);
    
    //printf("\n\nAAAAAAAAA %d\n\n",peso);
	printf("g_l_i:     A aresta de peso %d foi inserida entre os nós %d e %d.\n", peso, vAlvo, vDest);
   	
   	grafo->numArestas++;
	
	
	return true;
}