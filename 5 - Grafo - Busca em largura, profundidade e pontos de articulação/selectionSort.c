//===================================================================
// Selection Sort

void selectionSort(int vetor[], int tam) {
    int i, j, indMenor, aux;

    for (i = 0; i < tam - 1; i++)
    {
        // indMenor é o número ainda não ordenado
        indMenor = i;

        // Este laço efetua a troca do menor número com o indMenor ainda não
        // ordenado, caso este seja menor.
        for (j = i + 1; j < tam; j++) {
            if (vetor[j] < vetor[indMenor])
                indMenor = j;
        }
        // Ordena o indMenor se ele ainda não tenha sido.
        if (i != indMenor)
        {
            aux = vetor[i];
            vetor[i] = vetor[indMenor];
            vetor[indMenor] = aux;
        }
    }
}

// Selection sort para 2 vetores onde apenas o v1 será ordenado,
// o v2 apenas acompanha os respectivos valores de v1.
void selectionSort2(int v1[], int v2[], int tam) {
    int i, j, indMenor, aux1, aux2;

    for (i = 0; i < tam - 1; i++)
    {
        // indMenor é o número ainda não ordenado
        indMenor = i;

        // Este laço efetua a troca do menor número com o indMenor ainda não
        // ordenado, caso este seja menor.
        for (j = i + 1; j < tam; j++){
            if (v1[j] < v1[indMenor])
                indMenor = j;
        }
        // Ordena o indMenor se ele ainda não tenha sido.
        if (i != indMenor)
        {
            aux1 = v1[i];
            v1[i] = v1[indMenor];
            v1[indMenor] = aux1;
            
            aux2 = v2[i];
            v2[i] = v2[indMenor];
            v2[indMenor] = aux2;
        }
    }
}

// Selection Sort para 3 argumentos. Este selection sort ordena
// o v1, e como critério de desempate, o vetor 2.
void selectionSort3(int v1[], int v2[], int v3[], int tam) {
    int i, j, indMenor, aux1, aux2, aux3;

    for (i = 0; i < tam - 1; i++)
    {
        // indMenor é o número ainda não ordenado
        indMenor = i;

        // Este laço efetua a troca do menor número com o indMenor ainda não
        // ordenado, caso este seja menor.
        for (j = i + 1; j < tam; j++) {
            if (v1[j] < v1[indMenor])
                indMenor = j;
        }
        // Ordena o indMenor se ele ainda não tenha sido.
        if (i != indMenor)
        {
            aux1 = v1[i];
            v1[i] = v1[indMenor];
            v1[indMenor] = aux1;
            
            aux2 = v2[i];
            v2[i] = v2[indMenor];
            v2[indMenor] = aux2;

            aux3 = v3[i];
            v3[i] = v3[indMenor];
            v3[indMenor] = aux3;
        }
    }
    
    for (i = 0; i < tam - 1; i++)
    {
        for (j = 0; j < tam - 1; j++)
        {
            if (v1[j] == v1[j + 1])
            {
                if (v2[j] > v2[j + 1])
                {
                    aux1 = v1[j];
                    v1[j] = v1[j + 1];
                    v1[j + 1] = aux1;
                    
                    aux2 = v2[j];
                    v2[j] = v2[j + 1];
                    v2[j + 1] = aux2;

                    aux3 = v3[j];
                    v3[j] = v3[j + 1];
                    v3[j + 1] = aux3;
                }
            }
        }
    }
}