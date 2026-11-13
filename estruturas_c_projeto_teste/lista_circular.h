#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct NoCircular {
    int dado;
    struct NoCircular *proximo;
} NoCircular;

typedef struct {
    NoCircular *fim;
} ListaCircular;

ListaCircular* criar_lista_circular();
void inserir_circular(ListaCircular *l, int valor);
void destruir_lista_circular(ListaCircular *l);

#endif