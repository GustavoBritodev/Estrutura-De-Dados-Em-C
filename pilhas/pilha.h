#ifndef _PILHA_H
#define _PILHA_H
#include <stdbool.h>

#define MAX_PILHA 10

typedef char stack_info;
typedef struct {
    stack_info itens[MAX_PILHA];
    int topo;
} pilha;

void stack_init(pilha * );
void push(pilha *, stack_info);
stack_info pop(pilha *);
bool stack_isfull(pilha p);
bool stack_isempty(pilha p);
stack_info top(pilha p);
pilha pilha_ordenar(pilha p);
void pilha_remover_ocorrencias(pilha *, stack_info);
void pilha_rotacionar(pilha *p, int n);
#endif // _PILHA_H