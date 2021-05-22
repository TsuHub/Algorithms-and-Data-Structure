void liberaGrafo(Grafo* grafo)
{
	int v;
	Apontador p;

	// Libera a lista de adjac�ncia de cada v�rtice
	for (v = 0; v <= grafo->numVertices; v++)
	{
		while ((p = grafo->listaAdj[v]) != NULL)
		{
			grafo->listaAdj[v] = p->prox;
			p->prox = NULL;
			free(p);
		}
	}
	grafo->numVertices = 0;

	//Libera o vetor de ponteiros para as listas de adjac�ncia
	free(grafo->listaAdj);
	grafo->listaAdj = NULL;
	
	printf("g_l_lG:    O grafo foi liberado.\n");
}