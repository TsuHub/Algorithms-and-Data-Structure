/*
LeGrafo(nomearq, Grafo)
Le o arquivo nomearq e armazena na estrutura Grafo
Layout do arquivo:
	A 1a linha deve conter o n�mero de v�rtices e o n�mero de arestas do grafo,
	separados por espa�o.
	A 2a linha em diante deve conter a informa��o de cada aresta, que consiste
	no �ndice do v�rtice de origem, �ndice do v�rtice de destino e o peso da
	aresta, tamb�m separados por espa�os.

	Observa��es:
		Os v�rtices devem ser indexados de 0 a |V| - 1
		Os pesos das arestas s�o n�meros racionais n�o negativos.

Exemplo: O arquivo abaixo cont�m um grafo com 4 v�rtices (0, 1, 2, 3) e
7 arestas.

4 7
0 3 6.3
2 1 5.0
2 0 9
1 3 1.7
0 1 9
3 1 5.6
0 2 7.2

C�digo de sa�da:
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