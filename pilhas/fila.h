#ifndef _FILA_H
#define _FILA_H

#include <stdbool.h>

typedef char queue_info;

typedef struct fila_node {
    queue_info dado;
    struct fila_node *proximo;
} fila_node;

typedef struct {
    fila_node *frente;
    fila_node *tras;
    int tamanho;
} fila;

void fila_init(fila *f);
bool fila_vazia(const fila *f);
int fila_tamanho(const fila *f);
void enqueue(fila *f, queue_info info);
queue_info dequeue(fila *f);
queue_info fila_frente(const fila *f);

// Funções solicitadas
void inverter_fila(fila *f);
void mover_para_final(fila *f, queue_info elemento);
void intercalar_filas(fila *f1, fila *f2, fila *resultado);
void remover_duplicatas_consecutivas(fila *f);
void rotacionar_fila(fila *f, int k);

void fila_destroi(fila *f);

#endif // _FILA_H
