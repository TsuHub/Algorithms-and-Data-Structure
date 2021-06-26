#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Arvore_B.h"
#include "OperacoesDisco.c"

bool criaArvoreB(ArvB* T)
{
    NO* x;
    if (!(x = (NO*) malloc(sizeof(NO)))) {
        fprintf(stderr, "ERRO: Não foi possível alocar um novo bloco.");
        return false;
    }

    x->folha = true;
    x->numChaves = 0;
    escreveNoDisco(x);
    T->raiz = x;

    return true;
}

NO* buscaArvoreB(NO* node, TipoChave k)
{
    int i = 0;
    while (i <= node->numChaves && node->chave[i] < k) i++;

    if (i <= node->numChaves && node->chave[i] == k) return (node);

    else if (node->folha) return NULL;
    
    else leDoDisco(node);

    return buscaArvoreB(node->filhos[i], k);
}