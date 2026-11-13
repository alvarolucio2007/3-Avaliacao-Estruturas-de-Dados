#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

Lista* criar_lista();
void inserir_inicio(Lista *l, int valor);
void destruir_lista(Lista *l);

#endif