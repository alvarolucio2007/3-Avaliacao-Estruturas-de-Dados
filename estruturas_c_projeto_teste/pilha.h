#ifndef PILHA_H
#define PILHA_H

typedef struct NoPilha {
    int dado;
    struct NoPilha *proximo;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

Pilha* criar_pilha();
void empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p);
void destruir_pilha(Pilha *p);

#endif