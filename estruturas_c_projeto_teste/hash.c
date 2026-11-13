#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

static size_t indice(int x, size_t capacidade) {
    return (size_t)(x < 0 ? -x : x) % capacidade;
}

Hash* criar_hash(int capacidade) {
    if (capacidade <= 0) return NULL;
    Hash *h = (Hash*) malloc(sizeof(Hash));
    h->capacidade = capacidade;
    h->baldes = (HashNo**) calloc(capacidade, sizeof(HashNo*));
    return h;
}

void inserir_hash(Hash *h, int chave, const char *valor) {
    if (!h || !h->capacidade) return;
    size_t i = indice(chave, h->capacidade);
    HashNo *p = h->baldes[i];
    while (p) {
        if (p->chave == chave) {
            strncpy(p->valor, valor, sizeof(p->valor) - 1);
            return;
        }
        p = p->prox;
    }
    HashNo *novo = (HashNo*) malloc(sizeof(HashNo));
    novo->chave = chave;
    strncpy(novo->valor, valor, sizeof(novo->valor) - 1);
    novo->prox = h->baldes[i];
    h->baldes[i] = novo;
}

char* buscar_hash(Hash *h, int chave) {
    if (!h || !h->capacidade) return NULL;
    size_t i = indice(chave, h->capacidade);
    HashNo *p = h->baldes[i];
    while (p) {
        if (p->chave == chave) return p->valor;
        p = p->prox;
    }
    return NULL;
}

void destruir_hash(Hash *h) {
    if (!h) return;
    if (h->baldes) {
        for (size_t i = 0; i < h->capacidade; i++) {
            HashNo *p = h->baldes[i];
            while (p) {
                HashNo *prox = p->prox;
                free(p);
                p = prox;
            }
        }
        free(h->baldes);
    }
    free(h);
}