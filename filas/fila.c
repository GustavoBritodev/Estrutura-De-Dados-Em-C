#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void fila_init(fila *f){
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
}

bool fila_vazia(const fila *f){
    return f->frente == NULL;
}

int fila_tamanho(const fila *f){
    return f->tamanho;
}

void enqueue(fila *f, queue_info info){
    fila_node *novo = (fila_node*) malloc(sizeof(fila_node));
    if(!novo){
        fprintf(stderr, "Erro de alocacao na fila\n");
        exit(EXIT_FAILURE);
    }
    novo->dado = info;
    novo->proximo = NULL;
    if(fila_vazia(f)){
        f->frente = novo;
        f->tras = novo;
    } else {
        f->tras->proximo = novo;
        f->tras = novo;
    }
    f->tamanho++;
}

queue_info dequeue(fila *f){
    if(fila_vazia(f)){
        fprintf(stderr, "Dequeue de fila vazia\n");
        exit(EXIT_FAILURE);
    }
    fila_node *rem = f->frente;
    queue_info valor = rem->dado;
    f->frente = rem->proximo;
    if(f->frente == NULL){
        f->tras = NULL;
    }
    free(rem);
    f->tamanho--;
    return valor;
}

queue_info fila_frente(const fila *f){
    if(fila_vazia(f)){
        fprintf(stderr, "Fila vazia (frente)\n");
        exit(EXIT_FAILURE);
    }
    return f->frente->dado;
}

void fila_destroi(fila *f){
    while(!fila_vazia(f)){
        dequeue(f);
    }
}

void inverter_fila(fila *f){
    if(fila_vazia(f) || f->tamanho < 2) return;

    fila aux;
    fila_init(&aux);
    int n = fila_tamanho(f);

    for(int i = n; i > 0; i--){
        for(int j = 0; j < i - 1; j++){
            enqueue(f, dequeue(f));
        }
        enqueue(&aux, dequeue(f));
    }

    while(!fila_vazia(&aux)){
        enqueue(f, dequeue(&aux));
    }

    fila_destroi(&aux);
}

void mover_para_final(fila *f, queue_info elemento){
    if(fila_vazia(f)) return;

    int n = fila_tamanho(f);
    bool achou = false;

    for(int i = 0; i < n; i++){
        queue_info x = dequeue(f);
        if(!achou && x == elemento){
            achou = true;
            continue;
        }
        enqueue(f, x);
    }

    if(achou){
        enqueue(f, elemento);
    }
}

void intercalar_filas(fila *f1, fila *f2, fila *resultado){
    while(!fila_vazia(f1) || !fila_vazia(f2)){
        if(!fila_vazia(f1)){
            enqueue(resultado, dequeue(f1));
        }
        if(!fila_vazia(f2)){
            enqueue(resultado, dequeue(f2));
        }
    }
}

void remover_duplicatas_consecutivas(fila *f){
    if(fila_vazia(f)) return;

    fila aux;
    fila_init(&aux);

    queue_info ultimo = dequeue(f);
    enqueue(&aux, ultimo);

    while(!fila_vazia(f)){
        queue_info atual = dequeue(f);
        if(atual != ultimo){
            enqueue(&aux, atual);
            ultimo = atual;
        }
    }

    while(!fila_vazia(&aux)){
        enqueue(f, dequeue(&aux));
    }

    fila_destroi(&aux);
}

void rotacionar_fila(fila *f, int k){
    int n = fila_tamanho(f);
    if(n == 0) return;

    int r = k % n;
    if(r < 0){
        r = (r + n) % n;
    }
    if(r == 0) return;

    int left = n - r;
    for(int i = 0; i < left; i++){
        enqueue(f, dequeue(f));
    }
}
