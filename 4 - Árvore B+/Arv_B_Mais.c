/*
    t é o grau de uma árvore. O grau mínimo de
	uma árvore é o nº mínimo de filhos que cada
	nó pode ter. E com base em t, outros cálculos
	são feitos:
	
	1. nº min de chaves por nó = [t - 1]
	2. nº max de chaves por nó = [2*t - 1]
	3. nº min de filhos por nó = [t]
	4. nº max de filhos por nó = [2t]
*/
#include <stdbool.h>
#define t 3
typedef int TipoChave;

typedef struct str_no {
    TipoChave chave[2*t - 1];
    struct str_no* filhos[2*t];
    int numChaves;
    bool folha;
} NO;

typedef struct {
    NO* raiz;
} ArvBMais;
