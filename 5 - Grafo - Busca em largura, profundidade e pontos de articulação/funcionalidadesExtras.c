int vertAnterior(int e1, int e2){
    int minimo = 0;

    if (e1 < e2) minimo = e1;
    else minimo = e2;

    return minimo;
}

bool jaExisteElemento(int* vetor, int v, int tam){
    int i;
    for (i = 0; i < tam; i++){
        if (v == vetor[i])
            return true; 
    }
    return false;
}