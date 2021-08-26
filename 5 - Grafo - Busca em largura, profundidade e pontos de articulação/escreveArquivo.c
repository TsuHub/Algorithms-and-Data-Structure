#include <stdio.h>
//#include "quickSort3.c"

FILE *pArq;

int escreveCaminhos(int* ant, int ind)
{
	if (ind == -1){
		fprintf(pArq, "\n");
		return 0;
	}

	if (ind != 0){
		escreveCaminhos(ant, ant[ind]);
		fprintf(pArq, "%d ", ind);
		return 0;
	}
	fprintf(pArq, "\n%d ", ind);
	return 0;
}

void componentesConectados(int* ant, int nV)
{
	fprintf(pArq, "Componentes Conectados:");

	int i;
	int contComponentes = 0;
	for (i = 0; i < nV; i++){
		if (ant[i] == -1){
			contComponentes++;
			fprintf(pArq, "\nC%d: ", contComponentes);
		}
		fprintf(pArq, "%d ", i);
	}
	fprintf(pArq, "\n");
}

void escreveArquivo(Grafo* grafo, int* conexaoV1, int* conexaoV2, float* pesoArestas)
{
	int nA = grafo->numArestas;
	int nV = grafo->numVertices;
	int i;

    int* aux1  = (int*) malloc (nA * sizeof(int));
    int* aux2 = (int*) malloc (nA * sizeof(int));
    int* aux3 = (int*) malloc (nA * sizeof(int));
	
	for (i = 0; i < nA; i++){
		aux1[i]  = conexaoV1[i];
		aux2[i] = conexaoV2[i];
		aux3[i] = pesoArestas[i];
	}
	
	//==========================================================================
	// CAMPO DE TESTES 1
	
	/*
	for (i = 0; i < nA; i++)
		printf("%d ", aux1[i]);
	printf("\n\n");
	//*/
	//==========================================================================
	// Ordenação do vetor aux1 (mais detalhes em "grafo_listaadj_quickSort3.c"
	
	// CASO O QUICK CONTINUE RETORNANDO LIXO DE MEMÓRIA,
	// CRIAR UM PONTEIRO PARA ALOCAR O VETOR aux1, aux2 E aux3
	// Ou mudar os parâmetros do quick de "int vet[]" para "int* vet" 

	//quickSort3(aux1, aux2, aux3, 0, nA);
	selectionSort3(aux1, aux2, aux3, nA);
	
	/*
	for (i = 0; i < nA; i++){
		printf("%d %d %d\n", aux1[i], aux2[i], aux3[i]);
	}
	printf("\n");
	//*/
	
	//==========================================================================
	// Criação do arquivo saida.txt
	
	//FILE *pArq;
	
	pArq = fopen("saida.txt", "w");
	if (pArq == NULL)
		fprintf(stderr, "ERRO: O arquivo não pôde ser aberto.");
	
	//..........................................................................
	// PARTE 1
	
	fprintf(pArq, "%d %d\n", grafo->numVertices, grafo->numArestas);	// Armazenamento da primeira linha
	
	for (i = 0; i < nA; i++)											// Armazenamento das linhas referentes as arestas (triplas)
		fprintf(pArq, "%d %d %d\n", aux1[i], aux2[i], aux3[i]);
	
	fprintf(pArq, "\n");

	//..........................................................................
	// PARTE 2 - BL
	
	fprintf(pArq, "BL:\n");
	for (i = 0; i < nV; i++)
		fprintf(pArq, "%d ", vIndicesBL[i]);
	fprintf(pArq, "\n\n");

	free(vIndicesBL);
	//..........................................................................
	// PARTE 3 - Caminhos BL
	
	fprintf(pArq, "Caminhos BL:");

	int indiceBL;
	for (indiceBL = 0; indiceBL < nV; indiceBL++){
		escreveCaminhos(camBL, indiceBL);
	}
	fprintf(pArq, "\n\n");

	free(camBL);
	//..........................................................................
	// PARTE 4 - BP
	
	/*
		É passado um vetor que receberá os nós (por índices) já em ordem
		de descoberta.
	*/
	fprintf(pArq, "BP:\n");
		
	for (i = 0; i < nV; i++)
		fprintf(pArq, "%d ", vIndicesBP[i]);
	
	fprintf(pArq, "\n\n");

	free(vIndicesBP);
	
	//..........................................................................
	// PARTE 5 - Caminhos BP

	fprintf(pArq, "Caminhos BP:");
	//printf("\nCaminhos BP:");

	int indiceBP;
	for (indiceBP = 0; indiceBP < nV; indiceBP++){
		escreveCaminhos(camBP, indiceBP);
	}
	fprintf(pArq, "\n\n");

	//..........................................................................
	// PARTE 6 - Componentes Conectados

	componentesConectados(camBP, nV);

	free(camBP);

	//..........................................................................
	// PARTE 7 - Vertices de articulacao

	fprintf(pArq, "\n");
	fprintf(pArq, "Vertices de articulacao:\n");
	for (i = 0; i < nV; i++){
		if (verticesArticulacao[i] != -1)
			fprintf(pArq, "%d ", verticesArticulacao[i]);
	}
	
	free(verticesArticulacao);

	fclose(pArq);
	
	//==========================================================================
}