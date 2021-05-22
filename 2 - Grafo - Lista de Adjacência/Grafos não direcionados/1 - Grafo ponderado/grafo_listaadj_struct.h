#include <stdbool.h>

#define VERTICE_INVALIDO NULL
#define AN -1

typedef int Peso;

/*
	Uma estrutura do tipo "Aresta" é mais interessante para este
	projeto ao invés de uma estrutura do tipo "Vértice" (que talvez
	fosse mais intuitivo), por duas razões:
	1. Podemos colocar um peso nas arestas;
	2. Podemos criar uma lista de adjacência (como declarado na
		struct "Grafo"), e para que exista nós adjacentes, é
		necessário que exista arestas entre os nós, portanto
		usar uma estrutura aresta, é uma abordagem mais direta;
		
    A ideia é mais sofisticada, não intuitiva e resolve
    problemas pontuais, descrita acima.
*/
typedef struct str_aresta {
	int vdest;
	Peso peso;
	struct str_aresta* prox;
} Aresta;

typedef Aresta* Apontador;

typedef struct {
	//Aresta** listaAdj;
	Apontador* listaAdj;
	int numVertices;
	int numArestas;
} Grafo;