#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

//============================================================================
// INICIALIZA A FILA

void inicializaFila(Fila* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

//============================================================================
// RETORNA A QUANTIDADE DE ELEMENTOS DA FILA
/*
    Esta função percorre a fila para contabilizar o seu tamanho.
    (Depois eu posso melhorar isto incrementando ao inserir e
    decrementando ao excluir um elemento da fila).
*/

int tamanho(Fila* fila)
{
    Ponteiro pont = fila->inicio;
    int tamanho = 0;

    while (pont != NULL){
        tamanho++;
        pont = pont->prox;
    }
    return tamanho;
}

//============================================================================
// IMPRIME ELEMENTOS DA FILA

void imprimeFila(Fila* fila)
{
    Ponteiro pont = fila->inicio;
    printf("Fila: \n");

    while (pont != NULL){
        printf("%d ", pont->registro);
        pont = pont->prox;
    }
    printf("\n\n");
}

//============================================================================
// INSERE ELEMENTO NA FILA

void insereElementoFila(Fila* fila, int registro)
{
    Ponteiro novo = (Ponteiro) malloc(sizeof(Elemento));
    novo->registro = registro;
    novo->prox = NULL;

    if (fila->inicio == NULL)
        fila->inicio = novo;

    else
        fila->fim->prox = novo;
    
    fila->fim = novo;
    fila->tamanho++;

    //printf("%d inserido com sucesso.\n\n", registro);
}

//============================================================================
// EXCLUI ELEMENTO DA FILA (Sempre os elementos do início da fila)
// e retorna o elemento retirado.

int retiraElementoFila(Fila* fila)
{
    int backup;

    if (fila->inicio == NULL){
        fprintf(stderr, "ERRO: Não há elemento a ser excluído.\n");
        return false;
    }
    backup = fila->inicio->registro;

    Ponteiro aRetirar = fila->inicio;
    
    fila->inicio = fila->inicio->prox;

    free(aRetirar);

    if (fila->inicio == NULL)
        fila->fim = NULL;

    fila->tamanho--;

    return backup;
}
//============================================================================
// REINICIALIZA FILA

void reinicializaFila(Fila* fila)
{
    Ponteiro pont = fila->inicio;

    while (pont != NULL){
        Ponteiro apagar = pont;
        pont = pont->prox;
        free(apagar);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}

void liberaFila(Fila* fila)
{
    Ponteiro pont = fila->inicio;

    while(pont != NULL) {
        retiraElementoFila(fila);
        pont = pont->prox;
    }
    printf("g_l_f:     A fila foi liberada.\n");
}