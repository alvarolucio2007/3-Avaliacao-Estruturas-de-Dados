#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct NoDuplo {
    int dado;
    struct NoDuplo *proximo;
    struct NoDuplo *anterior;
} NoDuplo;

typedef struct {
    NoDuplo *inicio;
    NoDuplo *fim;
} ListaDupla;

ListaDupla* criar_lista_dupla();
void inserir_fim_dupla(ListaDupla *l, int valor);
void destruir_lista_dupla(ListaDupla *l);

#endif