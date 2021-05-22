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

int leGrafo(char* nomearq, Grafo* grafo)
{
	FILE *fp;
	int nvertices, narestas;
	int v1, v2;
	Peso peso;
	int idar;

	fp = fopen(nomearq, "r");
	if (fp == NULL)
		return 0;

	if (fscanf(fp, "%d %d", &vertices, &narestas) != 2)
		return 0;

	inicializaGrafo(grafo, nvertices);
}