#include <stdio.h>
#include <stdlib.h>
#include "listaAdj.c"
#include "leGrafo.c"
#include "imprimeGrafoFormaTsu.c"
#include "buscaEmLargura.c"
#include "buscaEmProfundidade.c"
#include "escreveArquivo.c"

int main()
{
	int nV, nA;

	FILE *p;
	p = fopen("entrada.txt", "r");

	if (p == NULL)
		fprintf(stderr, "\nERRO: Arquivo não encontrado.\n");

	if (fscanf(p, "%d %d", &nV, &nA) != 2)
		return 0;

	fclose(p);
	
	//..........................................................................
	// Declarando os vetores de vértices conectados e do peso de suas arestas.

    int* conexaoV1 = (int*) malloc (nA * sizeof(int));
	int* conexaoV2 = (int*) malloc (nA * sizeof(int));
    float* pesoArestas = (float*) malloc (nA * sizeof(float));
	
	Grafo grafo;
	
	// Passando como argumento os vetores (seus endereÃ§os mais precisamente).
	// para inicializÃ¡-los (em relação a conexaoV1, conexaoV2, pesoArestas).
	leGrafo("entrada.txt", &grafo, conexaoV1, conexaoV2, pesoArestas);
	
	//imprimeGrafoFormaTsu(&grafo);
	
	//Teste
	//printf("%d %d %.1f\n", conexaoV1[0], conexaoV2[0], pesoArestas[0]);

	//..........................................................................		
	// Inicializando o grafo com os valores obtidos do leGrafo
	int i;
	for (i = 0; i < nA; i++)
		insereAresta(&grafo, pesoArestas[i], conexaoV1[i], conexaoV2[i]);
	
	imprimeGrafoFormaTsu(&grafo);
	
	//==========================================================================

	buscaEmLargura(&grafo);

	buscaProfundidade(&grafo);
	
	//==========================================================================

	escreveArquivo(&grafo, conexaoV1, conexaoV2, pesoArestas);
	
	free(conexaoV1);
	free(conexaoV2);
	free(pesoArestas);

	liberaGrafo(&grafo);

	system("pause");
    
	return 0;
}