#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

ListaCircular* criar_lista_circular() {
    ListaCircular *l = (ListaCircular*) malloc(sizeof(ListaCircular));
    l->fim = NULL;
    return l;
}

void inserir_circular(ListaCircular *l, int valor) {
    NoCircular *novo = (NoCircular*) malloc(sizeof(NoCircular));
    novo->dado = valor;
    if (l->fim == NULL) {
        l->fim = novo;
        novo->proximo = novo;
    } else {
        novo->proximo = l->fim->proximo;
        l->fim->proximo = novo;
        l->fim = novo;
    }
}

void destruir_lista_circular(ListaCircular *l) {
    if (l->fim == NULL) {
        free(l);
        return;
    }
    NoCircular *atual = l->fim->proximo;
    l->fim->proximo = NULL;
    while (atual != NULL) {
        NoCircular *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(l);
}