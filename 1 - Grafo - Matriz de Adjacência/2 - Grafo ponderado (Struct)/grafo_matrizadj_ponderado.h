#include <stdbool.h>

#define MAXNUMVERTICES 100
#define AN -1
#define VERTICE_INVALIDO -1

typedef int Peso;

typedef struct {
	Peso mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
	int numVertices;
	int numArestas;
} Grafo;

typedef int Apontador;