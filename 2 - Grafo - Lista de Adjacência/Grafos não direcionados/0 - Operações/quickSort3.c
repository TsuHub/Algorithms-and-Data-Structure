#include <stdio.h>

//==============================================================================
// Quick Sort de 3 argumentos

/*
	O que eu fiz aqui foi ordenar o vetor em questão (o vetor com os 1ºs vértices,
	chamado de vetor) e repassar os outros vértices (v2: os vértices onde as
	arestas incidem | v3: os pesos destas arestas).
*/

// Atualiza o menor elemento e o pivô.
void troca3(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

// Função responsável por definir o pivô. No caso, foi escolhido o primeiro
// elemento do vetor para ser o pivô, ordenando os elementos do menor para o maior.
int particiona3(int vetor[], int v2[], int v3[], int esquerda, int direita)
{
    int pivo = vetor[direita];					// incialização do pivô
    int i = (esquerda - 1);						// Indexação do menor elemento

	int j;
    for (j = esquerda; j <= direita - 1; j++)
    {
        // Se o elemento atual for menor que o pivô, a troca3 é efetuada.
        if (vetor[j] < pivo)
        {
            i++;								// incremento do índice do menor elemento.
            troca3(&vetor[i], &vetor[j]);
            troca3(&v2[i], &v2[j]);
            troca3(&v3[i], &v3[j]);
        }
    }
    troca3(&vetor[i + 1], &vetor[direita]);
    troca3(&v2[i + 1], &v2[direita]);
    troca3(&v3[i + 1], &v3[direita]);
    return (i + 1);
}

// Função recursiva responsável pela ordenação do algoritmo.
// Caso os elementos estejam ordenados (de forma crescente)
// o quicksort terá o pior desempenho, i.e., O(n^2).
// esquerda e direita são atualizados a cada chamada recursiva.
void quickSort3(int vetor[], int v2[], int v3[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        // ip é o índice da partição
        int ip = particiona3(vetor, v2, v3, esquerda, direita);

        // A ordenação é feita em metades,
        // onde a primeira chamada é para ordenar a primeira metade
        // e a segunda chamada recursiva é para a ordenação da segunda metade.
        // Esta função efetua isso recursivamente em todo vetor,
        // dividindo-a em várias "metades" (metade da metade),
        // até que o vetor esteja totalmente ordenado.
        quickSort3(vetor, v2, v3, esquerda, ip - 1);
        quickSort3(vetor, v2, v3, ip + 1, direita);
    }
}