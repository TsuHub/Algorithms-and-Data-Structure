#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj_struct.h"
#include "grafo_listaadj_inicializa.c"

int main()
{
	Grafo grafo;
	inicializaGrafo(&grafo, 5);
	return 0;
}