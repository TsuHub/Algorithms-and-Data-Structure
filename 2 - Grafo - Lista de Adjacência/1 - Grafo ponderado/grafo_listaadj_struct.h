typedef int Peso;

typedef struct str_aresta {
	int vdest;
	Peso peso;
	struct str_aresta * prox;
} Aresta;

typedef struct {
	Aresta *listaAdj;
	int numVertices;
	int numArestas;
} Grafo;