#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vetor.h"
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "hash.h"
#include "abb.h"
#include "heap.h"
#include "grafo.h"

double medir_tempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

void executar_testes_desempenho() {
    printf("\n=== BATERIA DE TESTES E MEDICOES (n = 100, 1.000, 10.000) ===\n");
    int tamanhos[] = {100, 1000, 10000};
    
    for (int i = 0; i < 3; i++) {
        int n = tamanhos[i];
        printf("\n--- Testando com n = %d ---\n", n);
        
        clock_t t_ini = clock();
        Hash* h = criar_hash(n * 2);
        for(int j = 0; j < n; j++) {
            inserir_hash(h, j, "Registro Teste");
        }
        buscar_hash(h, n / 2);
        clock_t t_fim = clock();
        printf("D1 (Hash): Tempo total insercao/busca = %.6f s\n", medir_tempo(t_ini, t_fim));
        destruir_hash(h);

        t_ini = clock();
        Heap* heap = criar_heap(n);
        for(int j = 0; j < n; j++) {
            inserir_heap(heap, j % 10, j);
        }
        for(int j = 0; j < n; j++) {
            remover_heap(heap);
        }
        t_fim = clock();
        printf("D3 (Heap): Tempo total insercao/remocao = %.6f s\n", medir_tempo(t_ini, t_fim));
        destruir_heap(heap);
    }
}

int main() {
    srand(42);
    int opcao;

    do {
        printf("\n========================================\n");
        printf("   SISTEMA DE GESTAO - PROJETO ED\n");
        printf("========================================\n");
        printf("1. Executar Testes de Desempenho (D1-D5)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) break;

        switch (opcao) {
            case 1:
                executar_testes_desempenho();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}