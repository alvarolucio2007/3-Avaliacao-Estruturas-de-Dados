#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo* criar_grafo(int vertices) {
    Grafo *g = (Grafo*) malloc(sizeof(Grafo));
    g->num_vertices = vertices;
    g->lista_adj = (NoAdjacencia**) calloc(vertices, sizeof(NoAdjacencia*));
    return g;
}

void adicionar_aresta(Grafo *g, int origem, int destino) {
    NoAdjacencia *novo = (NoAdjacencia*) malloc(sizeof(NoAdjacencia));
    novo->destino = destino;
    novo->proximo = g->lista_adj[origem];
    g->lista_adj[origem] = novo;
}

void destruir_grafo(Grafo *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        NoAdjacencia *atual = g->lista_adj[i];
        while (atual != NULL) {
            NoAdjacencia *prox = atual->proximo;
            free(atual);
            atual = prox;
        }
    }
    free(g->lista_adj);
    free(g);
}