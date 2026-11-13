#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

Vetor* criar_vetor(int capacidade) {
    Vetor *v = (Vetor*) malloc(sizeof(Vetor));
    v->dados = (int*) malloc(capacidade * sizeof(int));
    v->tamanho = 0;
    v->capacidade = capacidade;
    return v;
}

void inserir_vetor(Vetor *v, int elemento) {
    if (v->tamanho < v->capacidade) {
        v->dados[v->tamanho++] = elemento;
    }
}

int buscar_vetor(Vetor *v, int elemento) {
    for (int i = 0; i < v->tamanho; i++) {
        if (v->dados[i] == elemento) return i;
    }
    return -1;
}

void destruir_vetor(Vetor *v) {
    free(v->dados);
    free(v);
}