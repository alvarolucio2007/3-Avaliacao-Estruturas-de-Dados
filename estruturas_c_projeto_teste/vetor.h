#ifndef VETOR_H
#define VETOR_H

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Vetor;

Vetor* criar_vetor(int capacidade);
void inserir_vetor(Vetor *v, int elemento);
int buscar_vetor(Vetor *v, int elemento);
void destruir_vetor(Vetor *v);

#endif