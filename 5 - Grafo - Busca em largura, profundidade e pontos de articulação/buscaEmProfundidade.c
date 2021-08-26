#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "selectionSort.c"
#include "funcionalidadesExtras.c"

/*
	Para a busca em profundidade:
	
	Seleciona-se um nó ponto de partida, no caso será o de arestaRet índice,
	que chamarei de v0.
	
	O próximo passo é percorrer todos os vértices adjacentes a v0 até que
	se chegue ao último vértice da lista de adjacência. E cada vértice
	visitado é marcado segundo os critérios:
	- Cinza : Para a 1ª visita;
	- Preto : Se todos os seus adjacentes já foram visitados;
	(Tendo que todos os vértices serão inicializados com a cor branca,
	indicando que ainda não foram visitados.)
	
	Assim, teremos um vetor para as cores:
	
	cor[v] : Vetor que conterá três tipos, 0, 1 e 2 para cada elemento,
		     cor[0] para o elemento de índice 0 na listaAdj.
	
	Se caso um dos vértices for visitado e já estiver com a cor cinza,
	isto indica que há um ciclo no grafo.
	
	Para isto, o algoritmo possui dois vetores que auxiliarão a
	definir as cores:
	
	d[v] : vetor que conterá o tempo de descoberta de cada nó.
	t[v] : vetor que conterá o tempo de término de descoberta
		   de todos os adjacentes ao nó vAtual.
		   
    Cada um dos vetores possuirá o tempo referente a cada nó de
	acordo com o índice do nó, então para o nó de índice 0, seu
	tempo de descoberta estará em d[0] e tempo de término em t[0].
	
	(O tempo é contabilizado por passos, para cada vértice visitado,
	o tempo é incrementado em 1.)

	O while da função visitaBP é responsável por percorrer os adjacentes de 'v'.
	Dentro do laço existe uma chamada recursiva. A chamada recursiva serve para
	percorrer os adjacentes do adjacente de v. Antes de efetuar a chamada
	recursiva, o nó anterior é armazenado para poder retornar quando as visitas
	aos adjacentes dos adjacentes houver terminado.

	O vetor verticesArticulacao[] armazenará todos os vértices de articulação
	do grafo. Uma função jaExisteElemento() é utilizada para armazenar apenas
	os novos vértices de articulação, eliminando a possibilidade de existir
	alguma duplicação de valores no vetor. 
*/

#define BRANCO 0
#define CINZA  1
#define PRETO  2

int tempo = 0;
int* vIndicesBP;
int* camBP;

int* arestaRet;
int* verticesArticulacao;
int* iPA;					// Índice do vetor verticesArticulacao.

int caminhosBP(int* ant, int ind)
{
    if (ind == -1){
        printf("\n");
        return 0;
    }

	if (ind != 0){
		caminhosBP(ant, ant[ind]);
		printf("%d ", ind);
		return 0;
	}
	printf("\n%d ", ind);
	return 0;
}

void visitaBP(int vAtual, Grafo* grafo, int* tempo, int* cor, int* tdesc, int* tterm, int* antecessor)
{		
	Apontador p = grafo->listaAdj[vAtual];

	cor[vAtual]   = CINZA;
	tdesc[vAtual] = ++(*tempo);
	arestaRet[vAtual] = tdesc[vAtual];

	//printf("%d : CINZA\n", vAtual);
	int descendentes = 0;
	int vProx;
	while (p != NULL)
	{
		vProx = p->vdest;

		if (vProx == antecessor[vAtual]){
			p = p->prox;
			continue;
		}

		if (cor[vProx] == BRANCO){
			antecessor[vProx] = vAtual;
			visitaBP(vProx, grafo, tempo, cor, tdesc, tterm, antecessor);

			arestaRet[vAtual] = vertAnterior(arestaRet[vAtual], arestaRet[vProx]);

			// Caso em que o nó não é a raiz.
			if (antecessor[vAtual] != -1){
				if (arestaRet[vProx] >= tdesc[vAtual] && !(jaExisteElemento(verticesArticulacao, vAtual, grafo->numVertices))){
					verticesArticulacao[*iPA] = vAtual;
					*iPA = *iPA + 1;
				}
			}
			descendentes++;
		}

		else
			arestaRet[vAtual] = vertAnterior(arestaRet[vAtual], tdesc[vProx]);

		tterm[vAtual] = ++(*tempo);
		cor[vAtual]   = PRETO;
		p = p->prox;
	}
	//printf("%d : PRETO\n", vAtual);

	// Caso em que o nó é raiz.
	if (antecessor[vAtual] == -1){
		if (descendentes > 1 && !(jaExisteElemento(verticesArticulacao, vAtual, grafo->numVertices))){
			verticesArticulacao[*iPA] = vAtual;
			*iPA = *iPA + 1;
		}
	}
}

void buscaProfundidade(Grafo* grafo)
{
	int nV = grafo->numVertices;
	
	int* cor = (int*) malloc(nV * sizeof(int));
	int* tdesc = (int*) malloc(nV * sizeof(int));
	int* tterm = (int*) malloc(nV * sizeof(int));
	int* antecessor = (int*) malloc(nV * sizeof(int));

	int aux1 = 0;
	iPA = &aux1;
	arestaRet = calloc(nV, sizeof(int));
	verticesArticulacao = calloc(nV, sizeof(int));
	
	// Inicializando os vetores;
	int v;
	for (v = 0; v < nV; v++){
		cor[v] = BRANCO;
		tdesc[v] = 0;
		tterm[v] = 0;
		antecessor[v] = -1;
		arestaRet[v] = -1;
		verticesArticulacao[v] = -1;
	}

	//==========================================================================
	// BUSCA EM PROFUNDIDADE

	for (v = 0; v < nV; v++){
		if (cor[v] == BRANCO)
			visitaBP(v, grafo, &tempo, cor, tdesc, tterm, antecessor);
	}
	
	//==========================================================================
	// Ordenação dos vértices em ordem de descoberta
	
	vIndicesBP = calloc(nV, sizeof(int));
	int* vDescob = (int*) malloc(nV * sizeof(int));
	
	int i;
	for (i = 0; i < nV; i++)
		vIndicesBP[i] = i;
	
	for (i = 0; i < nV; i++)
		vDescob[i] = tdesc[i];
	
	selectionSort2(vDescob, vIndicesBP, nV);

	free(vDescob);
	
	//==========================================================================
	//BP:
	/*
	printf("BP:\n");
	for (i = 0; i < nV; i++){
		printf("%d ", vIndicesBP[i]);
	}
	printf("\n\n\n");
	//*/
	//==========================================================================
	//
	camBP = calloc(nV, sizeof(int));
	
	for (i = 0; i < nV; i++)
		camBP[i] = antecessor[i];

	//==========================================================================
	// CAMINHOS BP
	/*
	printf("Caminhos BP:");

	int indice;
	for (indice = 0; indice < nV; indice++){
		caminhosBP(antecessor, indice);
	}
	printf("\n\n\n");
	//*/
	//==========================================================================
	/*
	printf("Componentes Conectados:");
	int contComponentes = 0;
	for (i = 0; i < nV; i++){
		if (antecessor[i] == -1){
			contComponentes++;
			printf("\nC%d: ", contComponentes);
		}
		printf("%d ", i);
	}
	printf("\n\n\n");
	//*/

	selectionSort(verticesArticulacao, nV);
	
	/*
	printf("Vertices de articulacao:\n");
	for (i = 0; i < nV; i++){
		if (verticesArticulacao[i] != -1)
			printf("%d ", verticesArticulacao[i]);
	}
	printf("\n\n");
	//*/

	free(cor);
	free(tdesc);
	free(tterm);
	free(antecessor);
	free(arestaRet);
}