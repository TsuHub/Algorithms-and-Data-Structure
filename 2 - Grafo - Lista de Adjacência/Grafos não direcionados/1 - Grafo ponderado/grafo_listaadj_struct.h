#include <stdbool.h>

#define VERTICE_INVALIDO NULL
#define AN -1

typedef int Peso;

/*
	Uma estrutura do tipo "Aresta" � mais interessante para este
	projeto ao inv�s de uma estrutura do tipo "V�rtice" (que talvez
	fosse mais intuitivo), por duas raz�es:
	1. Podemos colocar um peso nas arestas;
	2. Podemos criar uma lista de adjac�ncia (como declarado na
		struct "Grafo"), e para que exista n�s adjacentes, �
		necess�rio que exista arestas entre os n�s, portanto
		usar uma estrutura aresta, � uma abordagem mais direta;
		
    A ideia � mais sofisticada, n�o intuitiva e resolve
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