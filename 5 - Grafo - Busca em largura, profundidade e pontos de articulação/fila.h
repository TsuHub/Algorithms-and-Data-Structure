typedef int TIPO;

typedef struct elem {
    TIPO registro;
    struct elem* prox;
} Elemento;

typedef Elemento* Ponteiro;

typedef struct {
    int tamanho;
    Ponteiro inicio;
    Ponteiro fim;
} Fila;