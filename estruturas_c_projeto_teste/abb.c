#include <stdlib.h>
#include "abb.h"

NoABB* inserir_abb(NoABB *raiz, int chave) {
    if (raiz == NULL) {
        NoABB *novo = (NoABB*) malloc(sizeof(NoABB));
        novo->chave = chave;
        novo->esquerda = novo->direita = NULL;
        return novo;
    }
    if (chave < raiz->chave) {
        raiz->esquerda = inserir_abb(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir_abb(raiz->direita, chave);
    }
    return raiz;
}

void destruir_abb(NoABB *raiz) {
    if (raiz != NULL) {
        destruir_abb(raiz->esquerda);
        destruir_abb(raiz->direita);
        free(raiz);
    }
}
