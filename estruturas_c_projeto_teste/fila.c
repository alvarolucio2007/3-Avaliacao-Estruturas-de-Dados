#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criar_fila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enfileirar(Fila *f, int valor) {
    NoFila *novo = (NoFila*) malloc(sizeof(NoFila));
    novo->dado = valor;
    novo->proximo = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
}

int desenfileirar(Fila *f) {
    if (f->inicio == NULL) return -1;
    NoFila *temp = f->inicio;
    int val = temp->dado;
    f->inicio = temp->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return val;
}

void destruir_fila(Fila *f) {
    while (f->inicio != NULL) {
        desenfileirar(f);
    }
    free(f);
}