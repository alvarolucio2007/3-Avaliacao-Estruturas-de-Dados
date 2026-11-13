#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int prioridade;
    int id;
} ElementoHeap;

typedef struct {
    ElementoHeap *elementos;
    int capacidade;
    int tamanho;
} Heap;

Heap* criar_heap(int capacidade);
void inserir_heap(Heap *h, int prioridade, int id);
ElementoHeap remover_heap(Heap *h);
void destruir_heap(Heap *h);

#endif