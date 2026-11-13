#ifndef ABB_H
#define ABB_H

typedef struct NoABB {
    int chave;
    struct NoABB *esquerda;
    struct NoABB *direita;
} NoABB;

NoABB* inserir_abb(NoABB *raiz, int chave);
void destruir_abb(NoABB *raiz);

#endif