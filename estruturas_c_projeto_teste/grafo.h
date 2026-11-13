#ifndef GRAFO_H
#define GRAFO_H

typedef struct NoAdjacencia {
    int destino;
    struct NoAdjacencia *proximo;
} NoAdjacencia;

typedef struct {
    int num_vertices;
    NoAdjacencia **lista_adj;
} Grafo;

Grafo* criar_grafo(int vertices);
void adicionar_aresta(Grafo *g, int origem, int destino);
void destruir_grafo(Grafo *g);

#endif