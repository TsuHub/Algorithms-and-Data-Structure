/*
	Existe a vers?o 1 (V1) do insere "grafo_listaadj_insere_V1.c"
	que ? a vers?o da professora.
	
	Tenho a vers?o "grafo_listaadj_insere.c" que ? a minha
	vers?o que faz mais sentido para mim, pode ser que exista
	algum bug, preciso testar mais vezes para saber. 
*/

#include <stdlib.h>
#include <stdbool.h>
#include "grafo_listaadj_verifValidadeVert.c"
#include "grafo_listaadj_verifListaAdjVazia.c"

/*
	vAlvo ? o v?rtice alvo que receber? o adjacente.
	vDest ? o v?rtice de destino.
	
		
	  Lista de	
	 adjac?ncia
	 (um vetor)
grafo->listaAdj[vAlvo]
		  |
		  |
		  |			  Pr?x da
		  |	    lista de adjac?ncia
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

// Fun??o para grafos n?o dirigidos
void atribuiAresta(Grafo* grafo, Peso peso, int vAlvo, int vDest)
{
	// Criando a aresta que ser? inserida entre
	// os v?rtices vAlvo e vDest
	Apontador p;
	Apontador pAux;
	
	if(!(p = (Apontador) calloc(1, sizeof(Aresta))))
	   	fprintf(stderr, "g_l_i:     ERRO: Falha na aloca??o de mem?ria na fun??o insere Aresta\n");

	// Inicizalizando a aresta que ser? inserida entre os v?rtices
	p->vdest = vDest;
   	p->peso  = peso;
   	
   	///*
   	// Se a lista for vazia, n?o h? uma pr?xima aresta
   	if (!listaAdjVazia(grafo, vAlvo)){
		pAux = grafo->listaAdj[vAlvo];
		p->prox = pAux;
	}
	
	else p->prox = NULL;					//	 p	 ---> NULL
	//*/

	grafo->listaAdj[vAlvo] = p;				// | 0 | ---> NULL
}

bool insereAresta(Grafo* grafo, Peso peso, int vAlvo, int vDest)
{
	if (!(verificaValidadeVertice(grafo, vAlvo) && verificaValidadeVertice(grafo, vDest))){
		return false;
	}
   	
   	/*
	   Como estamos tratando de um grafo n?o direcionado
	   precisamos conectar a aresta de vAlvo para vDest
	   e fazer o inverso tamb?m, de vDest para vAlvo.
   	*/
   	
    atribuiAresta(grafo, peso, vAlvo, vDest);
    atribuiAresta(grafo, peso, vDest, vAlvo);
    
    //printf("\n\nAAAAAAAAA %d\n\n",peso);
	printf("g_l_i:     A aresta de peso %.1f foi inserida entre os n?s %d e %d.\n", peso, vAlvo, vDest);
   	
   	grafo->numArestas++;
	
	return true;
}