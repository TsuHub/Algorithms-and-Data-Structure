#include <stdlib.h>
#include <stdbool.h>
//#include "grafo_matrizadj_verifValidadeVert.c"
/*
	Aparentemente, em C, como o arquivo 'grafo_matrizadj_insereAresta.c'
	j� faz a chamada de grafo_matrizadj_verifValidadeVert.c, este arquivo
	(grafo_matrizadj_existeAresta.c) n�o precisa faz�-lo.
	(se for isso mesmo, n�o faz sentido algum, j� que o arquivo que vai
	utilizar um m�dulo, deveria ser capaz de incluir (include/importar)
	o arquivo que seria utilizado.
*/

bool existeAresta(Grafo* grafo, int v1, int v2)
{
	if (!(verificaValidadeVertice(grafo, v1) && verificaValidadeVertice(grafo, v2)))
		return false;
	
	if (grafo->mat[v1][v2] != AN){
		printf("Existe aresta entre os v�rtices %d e %d\n", v1, v2);
		return true;
	}
	
	printf("N�o existe aresta entre os v�rtices %d e %d\n", v1, v2);
	return false;
}