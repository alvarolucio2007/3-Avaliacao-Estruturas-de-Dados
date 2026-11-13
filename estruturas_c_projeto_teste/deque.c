#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

Deque* criar_deque() {
    Deque *d = (Deque*) malloc(sizeof(Deque));
    d->inicio = NULL;
    d->fim = NULL;
    return d;
}

void inserir_inicio_deque(Deque *d, int valor) {
    NoDeque *novo = (NoDeque*) malloc(sizeof(NoDeque));
    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = d->inicio;
    if (d->inicio != NULL) {
        d->inicio->anterior = novo;
    } else {
        d->fim = novo;
    }
    d->inicio = novo;
}

void inserir_fim_deque(Deque *d, int valor) {
    NoDeque *novo = (NoDeque*) malloc(sizeof(NoDeque));
    novo->dado = valor;
    novo->proximo = NULL;
    novo->anterior = d->fim;
    if (d->fim != NULL) {
        d->fim->proximo = novo;
    } else {
        d->inicio = novo;
    }
    d->fim = novo;
}

int remover_inicio_deque(Deque *d, int *valor) {
    if (d->inicio == NULL) return 0;
    NoDeque *temp = d->inicio;
    *valor = temp->dado;
    d->inicio = temp->proximo;
    if (d->inicio != NULL) {
        d->inicio->anterior = NULL;
    } else {
        d->fim = NULL;
    }
    free(temp);
    return 1;
}

int remover_fim_deque(Deque *d, int *valor) {
    if (d->fim == NULL) return 0;
    NoDeque *temp = d->fim;
    *valor = temp->dado;
    d->fim = temp->anterior;
    if (d->fim != NULL) {
        d->fim->proximo = NULL;
    } else {
        d->inicio = NULL;
    }
    free(temp);
    return 1;
}

void destruir_deque(Deque *d) {
    NoDeque *atual = d->inicio;
    while (atual != NULL) {
        NoDeque *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(d);
}