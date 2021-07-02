/*
    t é o grau de uma árvore. De acordo com o Cormen,
     o grau mínimo de uma árvore é a metade do nº máx
     de filhos que cada nó pode ter. Então caso um nó
     possa possuir um nº máx de 4 filhos, o nº mín (grau
     da árvore) é 2.
     Nesta estrutura trabalharemos com o grau sendo 2,
     i.e., o nº máx de filhos é de 4.
*/
#include <stdbool.h>
#define t 2
typedef int TipoChave;

typedef struct str_no {
    TipoChave chave[2*t - 1];
    struct str_no* filhos[2*t];
    int numChaves;
    bool folha;
} NO;

typedef struct {
    NO* raiz;
} ArvB;
