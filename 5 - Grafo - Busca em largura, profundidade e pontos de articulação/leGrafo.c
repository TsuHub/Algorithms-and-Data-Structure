#include <stdio.h>
//#include "listaAdj.h"

/*
LeGrafo(nomearq, Grafo)
Le o arquivo nomearq e armazena na estrutura Grafo
Layout do arquivo:
	A 1a linha deve conter o número de vértices e o número de arestas do grafo,
	separados por espaço.
	A 2a linha em diante deve conter a informação de cada aresta, que consiste
	no índice do vértice de origem, índice do vértice de destino e o peso da
	aresta, também separados por espaços.

	Observações:
		Os vértices devem ser indexados de 0 a |V| - 1
		Os pesos das arestas são números racionais não negativos.

Exemplo: O arquivo abaixo contém um grafo com 4 vértices (0, 1, 2, 3) e
7 arestas.

4 7
0 3 6.3
2 1 5.0
2 0 9
1 3 1.7
0 1 9
3 1 5.6
0 2 7.2

Código de saída:
	1: leitura bem sucedida
	2: erro na leitura do arquivo
*/

int leGrafo(char* nomearq, Grafo* grafo, int* cV1, int* cV2, float* pA)
{
	FILE *fp;
	int nvertices, narestas;
	//int v1, v2;
	//Peso peso;
	//int idar;

	//==========================================================================
	// Abre o arquivo
	fp = fopen(nomearq, "r");
	
	//==========================================================================
	// Verificação
	if (fp == NULL){
		fprintf(stderr, "\nERRO: Arquivo não encontrado.\n");
		return 0;
	}

	//==========================================================================
	// Leitura da primeira linha do arquivo
	/*
		fp é um ponteiro que aponta para a 1ª linha do arquivo txt,
		após qualquer operação sobre essa linha, fp passa para a segunda linha.
	*/
	
	if (fscanf(fp, "%d %d", &nvertices, &narestas) != 2)
		return 0;
	
	printf("\n\nTeste: \nNº Vértices: %d\nNº Arestas:  %d\n\n", nvertices, narestas);
	
	// Com os argumentos já definidos, inicializa-se o grafo.
	inicializaGrafo(grafo, nvertices);
	
	//==========================================================================
	// Armazenando os pesos das arestas e seus vértices
	///*	
	int auxV1, auxV2;
	float auxPeso;

    int* vertices1 = (int*) malloc(narestas * sizeof(int));
    int* vertices2 = (int*) malloc(narestas * sizeof(int));
    float* pesoArestas = (float*) malloc(narestas * sizeof(float));
	
	// Enquanto o ponteiro fp for diferente de EOF (End of File)
	// o laço continuará percorrendo o arquivo.
	// Teria o mesmo efeito que:
	// for (i = 0; i < narestas; i++)
	
	int i = 0;
	while (fgetc(fp) != EOF)
	{
		if (fscanf(fp, "%d %d %f", &auxV1, &auxV2, &auxPeso) == 3)
		{
			//printf("Teste: %d %d %.1f\n", auxV1, auxV2, auxPeso);
			vertices1[i] = auxV1;
			vertices2[i] = auxV2;
			pesoArestas[i] = auxPeso;
			
			i++;
		}
	}
	
	//printf("\nTESTE: %d %d %f", (vertices1[0]), (vertices2[0]), (pesoArestas[0]));
	
	fclose(fp);
	//*/
	
	/*
	printf("\n\n");
	for (i = 0; i < narestas; i++){
		printf("%d %d %.1f\n", vertices1[i], vertices2[i], pesoArestas[i]);
	}
	//*/
	
	for (i = 0; i < narestas; i++)
	{
		cV1[i] = vertices1[i];
		cV2[i] = vertices2[i];
		pA[i]  = pesoArestas[i];	
	}
	
	//printf("Teste: %d %d %d", vertices1, vertices2, pesoArestas);
	
	return 0;
}