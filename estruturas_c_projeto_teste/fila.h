#ifndef FILA_H
#define FILA_H

typedef struct NoFila {
    int dado;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

Fila* criar_fila();
void enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f);
void destruir_fila(Fila *f);

#endif