#ifndef HASH_H
#define HASH_H

#include <stddef.h>

typedef struct HashNo {
    int chave;
    char valor[50]; 
    struct HashNo *prox;
} HashNo;

typedef struct {
    HashNo **baldes;
    size_t capacidade;
} Hash;

Hash* criar_hash(int capacidade);
void inserir_hash(Hash *h, int chave, const char *valor);
char* buscar_hash(Hash *h, int chave);
void destruir_hash(Hash *h);

#endif