#include <stdlib.h>
#include <stdbool.h>
#include "grafo_listaadj_verifValidadeVert.c"
#include "grafo_listaadj_verifListaAdjVazia.c"

/*
	Esta versão 1 do insere "grafo_listaadj_insere_V1.c" é a
	versão da professora.
	
	Tenho a versão "grafo_listaadj_insere.c" que é a minha
	versão que faz mais sentido para mim, pode ser que exista
	algum bug, preciso testar mais vezes para saber. 
*/

/*
	va é o nó alvo que receberá o adjacente.
	vd é o nó de destino.
	
		
  Lista de	
 adjacência
(é um vetor*)
 listaAdj[v]	   Próx da
	 |			   lista de
   	 |		      adjacência
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
	   	fprintf(stderr, "ERRO: Falha na alocação de memória na função insere Aresta\n");
        return false;
   	}
   	
   	// forma 2
   	p->vdest = v2;
   	p->peso = peso;
   	p->prox = grafo->listaAdj[v1];	//   p   ---> | 0 |
   	grafo->listaAdj[v1] = p;		// | 0 | ---> | 0 |
   	grafo->numArestas++;
	
	printf("A aresta de peso %d foi inserida entre os nós %d e %d.\n", peso, v1, v2);
	
	   
    /*
	   Este é o uso da forma 1, onde faço uso direto da estruturas de
       Grafo, mas esta maneira não funciona. Aparentemente tenho que
	   fazer um ponteiro 'p' do tipo Apontador e depois passar 'p'
	   para grafo->listaAdj[v1]. 
	*/
	//grafo->listaAdj[v1]->vdest = v2;						// forma 1
	//grafo->listaAdj[v1]->peso = peso;						// forma 1
	//grafo->listaAdj[v1]->prox = grafo->listaAdj[v1];		// forma 1
	//grafo->numArestas++;									// forma 1

	
	return true;
}