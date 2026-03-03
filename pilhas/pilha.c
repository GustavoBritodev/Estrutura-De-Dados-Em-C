#include "pilha.h"

void stack_init(pilha * p){
    p->topo = 0;
}
void push(pilha * p, stack_info item){
    p->itens[p->topo++] = item;
}
stack_info pop(pilha * p){
    return p->itens[--p->topo];
}
bool stack_isfull(pilha p){
    return (p.topo == MAX_PILHA);
}
bool stack_isempty(pilha p){
    return (p.topo == 0);
}
stack_info top(pilha p){
    return p.itens[p.topo-1];
}
pilha pilha_ordenar(pilha p){
    pilha ordenada;
    stack_init(&ordenada); 
    while(!stack_isempty(p)){
        stack_info item = pop(&p);
        while(!stack_isempty(ordenada) && top(ordenada) > item){
            push(&p, pop(&ordenada));
        }
    }
}

void pilha_remover_ocorrencias(pilha *p, stack_info info){
    
}