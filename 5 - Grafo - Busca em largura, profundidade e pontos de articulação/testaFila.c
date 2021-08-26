#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.c"

Fila fila2;

int main()
{
    Fila fila;

    inicializaFila(&fila);

    printf("Tamanho %d\n\n", tamanho(&fila));

    imprimeFila(&fila);

    insereElementoFila(&fila, 10);

    imprimeFila(&fila);

    printf("Tamanho %d\n\n", tamanho(&fila));

    printf("Registro retirado: %d\n\n", retiraElementoFila(&fila));

    imprimeFila(&fila);

    printf("Tamanho %d\n\n", tamanho(&fila));

    insereElementoFila(&fila, 5);
    insereElementoFila(&fila, 7);

    printf("TESTE NOVO\n\n fila.tamanho : %d\n\n", fila.tamanho);

    retiraElementoFila(&fila);

    printf("TESTE NOVO\n\n fila.tamanho : %d\n\n", fila.tamanho);

    //==========================================================================

    inicializaFila(&fila2);

    printf("Fila 2 - tamanho : %d", fila2.tamanho);
}