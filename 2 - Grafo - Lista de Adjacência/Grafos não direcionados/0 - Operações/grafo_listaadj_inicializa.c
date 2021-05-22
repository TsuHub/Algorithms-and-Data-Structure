#include <stdio.h>		// Para fazer a impress�o da chamada de erros.
#include <stdlib.h>		// Para aloca��es din�micas.
#include <stdbool.h>	// Para usar os valores de retorno booleanos.

/*

  Lista de	
 adjac�ncia
(� um vetor*)
 listaAdj[v]	   Pr�x da
	 |			   lista de
   	 |		      adjac�ncia
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
		fprintf(stderr, "g_l_i:     ERRO: A quantidade de v�rtices deve ser maior que 0");
		return false;
	}
	
	grafo->numVertices = nv;
	grafo->numArestas  = 0;		// Esta linha na verdade � desnecess�ria, j�
								// que o callo c j� aloca os atributos de uma
								// estrutura como sendo zero.
	
	// Preciso perguntar a professora como esta compara��o funciona, j� que
	// o calloc tem tipo de retorno vazio pelo que eu li. E como o retorno �
	// void, como que eu usaria esta atribui��o no if?
	
	//if (!(grafo->listaAdj = (Aresta**) calloc(nv, sizeof(Aresta*)))){
    // Atualizado o ponteiro do tipo aresta como sendo Apontador.
	if (!(grafo->listaAdj = (Apontador*) calloc(nv, sizeof(Apontador)))){
		fprintf(stderr, "g_l_i:     ERRO: Falha na aloca��o de mem�ria na fun��o inicializaGrafo\n");
		return false;
	}
	printf("\ng_l_i:     Grafo inicializado com sucesso.\n");
	
	return true;
}