#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

ListaDupla* criar_lista_dupla() {
    ListaDupla *l = (ListaDupla*) malloc(sizeof(ListaDupla));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

void inserir_fim_dupla(ListaDupla *l, int valor) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->dado = valor;
    novo->proximo = NULL;
    novo->anterior = l->fim;
    if (l->fim != NULL) {
        l->fim->proximo = novo;
    } else {
        l->inicio = novo;
    }
    l->fim = novo;
}

void destruir_lista_dupla(ListaDupla *l) {
    NoDuplo *atual = l->inicio;
    while (atual != NULL) {
        NoDuplo *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(l);
}