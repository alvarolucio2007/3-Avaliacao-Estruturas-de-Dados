#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criar_lista() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void inserir_inicio(Lista *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = l->inicio;
    l->inicio = novo;
}

void destruir_lista(Lista *l) {
    No *atual = l->inicio;
    while (atual != NULL) {
        No *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(l);
}