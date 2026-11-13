#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

Heap* criar_heap(int capacidade) {
    Heap *h = (Heap*) malloc(sizeof(Heap));
    h->elementos = (ElementoHeap*) malloc(capacidade * sizeof(ElementoHeap));
    h->capacidade = capacidade;
    h->tamanho = 0;
    return h;
}

void inserir_heap(Heap *h, int prioridade, int id) {
    if (h->tamanho >= h->capacidade) return;
    int i = h->tamanho++;
    h->elementos[i].prioridade = prioridade;
    h->elementos[i].id = id;

    while (i > 0 && h->elementos[(i - 1) / 2].prioridade < h->elementos[i].prioridade) {
        ElementoHeap temp = h->elementos[i];
        h->elementos[i] = h->elementos[(i - 1) / 2];
        h->elementos[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

ElementoHeap remover_heap(Heap *h) {
    ElementoHeap vazio = {-1, -1};
    if (h->tamanho <= 0) return vazio;
    
    ElementoHeap raiz = h->elementos[0];
    h->elementos[0] = h->elementos[--h->tamanho];
    
    int i = 0;
    while (2 * i + 1 < h->tamanho) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        int maior = i;

        if (esq < h->tamanho && h->elementos[esq].prioridade > h->elementos[maior].prioridade)
            maior = esq;
        if (dir < h->tamanho && h->elementos[dir].prioridade > h->elementos[maior].prioridade)
            maior = dir;

        if (maior != i) {
            ElementoHeap temp = h->elementos[i];
            h->elementos[i] = h->elementos[maior];
            h->elementos[maior] = temp;
            i = maior;
        } else {
            break;
        }
    }
    return raiz;
}

void destruir_heap(Heap *h) {
    free(h->elementos);
    free(h);
}