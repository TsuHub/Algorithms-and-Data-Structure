#include <stdio.h>		// Para fazer a impressão da chamada de erros.
#include <stdlib.h>		// Para alocações dinâmicas.
#include <stdbool.h>	// Para usar os valores de retorno booleanos.

/*

  Lista de	
 adjacência
(é um vetor*)
 listaAdj[v]	   Próx da
	 |			   lista de
   	 |		      adjacência
   	 |	     (grafo->listaAdj[va])
     |				  |
	 |		    ------
	 |		   |		  
	 v	 	   v	 	  
	 
	 0	 ---> NULL
     1   ---> NULL
	 2   ---> NULL
	 3   ---> NULL
	 4   ---> NULL
	...
  nv - 1 
  	 	  ^
  	 	  |
	      |
       Aresta*
	 (Apontador)
	 
*/

bool inicializaGrafo(Grafo* grafo, int nv)
{
	if (nv <= 0){
		fprintf(stderr, "g_l_i:     ERRO: A quantidade de vértices deve ser maior que 0");
		return false;
	}
	
	grafo->numVertices = nv;
	grafo->numArestas  = 0;		// Esta linha na verdade é desnecessária, já
								// que o callo c já aloca os atributos de uma
								// estrutura como sendo zero.
	
	// Preciso perguntar a professora como esta comparação funciona, já que
	// o calloc tem tipo de retorno vazio pelo que eu li. E como o retorno é
	// void, como que eu usaria esta atribuição no if?
	
	//if (!(grafo->listaAdj = (Aresta**) calloc(nv, sizeof(Aresta*)))){
    // Atualizado o ponteiro do tipo aresta como sendo Apontador.
	if (!(grafo->listaAdj = (Apontador*) calloc(nv, sizeof(Apontador)))){
		fprintf(stderr, "g_l_i:     ERRO: Falha na alocação de memória na função inicializaGrafo\n");
		return false;
	}
	printf("\ng_l_i:     Grafo inicializado com sucesso.\n");
	
	return true;
}