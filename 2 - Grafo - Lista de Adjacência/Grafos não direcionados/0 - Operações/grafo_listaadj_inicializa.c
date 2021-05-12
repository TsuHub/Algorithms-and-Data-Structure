#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool inicializaGrafo(Grafo* grafo, int nv)
{
	if (nv <= 0){
		fprintf(stderr, "ERRO: A quantidade de v�rtices deve ser maior que 0");
		return false;
	}
	
	grafo->numVertices = nv;
	grafo->numArestas  = 0;		// Esta linha na verdade � desnecess�ria, j�
								// que o callo c j� aloca os atributos de uma
								// estrutura como sendo zero.
	
	// Preciso perguntar a professora como esta compara��o funciona, j� que
	// o calloc tem tipo de retorno vazio pelo que eu li. E como o retorno �
	// void, como que eu usaria esta atribui��o no if?
	if (!(grafo->listaAdj = (Aresta**) calloc(nv, sizeof(Aresta*)))){
		fprintf(stderr, "ERRO: Falha na aloca��o de mem�ria na fun��o inicializaGrafo\n");
		return false;
	}
	printf("\nGrafo inicializado com sucesso.\n");
	
	return true;
}