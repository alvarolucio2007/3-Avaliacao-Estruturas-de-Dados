#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criar_pilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilhar(Pilha *p, int valor) {
    NoPilha *novo = (NoPilha*) malloc(sizeof(NoPilha));
    novo->dado = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

int desempilhar(Pilha *p) {
    if (p->topo == NULL) return -1;
    NoPilha *temp = p->topo;
    int val = temp->dado;
    p->topo = temp->proximo;
    free(temp);
    return val;
}

void destruir_pilha(Pilha *p) {
    while (p->topo != NULL) {
        desempilhar(p);
    }
    free(p);
}