#ifndef DEQUE_H
#define DEQUE_H

typedef struct NoDeque {
    int dado;
    struct NoDeque *proximo;
    struct NoDeque *anterior;
} NoDeque;

typedef struct {
    NoDeque *inicio;
    NoDeque *fim;
} Deque;

Deque* criar_deque();
void inserir_inicio_deque(Deque *d, int valor);
void inserir_fim_deque(Deque *d, int valor);
int remover_inicio_deque(Deque *d, int *valor);
int remover_fim_deque(Deque *d, int *valor);
void destruir_deque(Deque *d);

#endif