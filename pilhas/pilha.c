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

//Ex 6
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

//Ex 7
void pilha_remover_ocorrencias(pilha *p, stack_info info){
    pilha temp;
    stack_init(&temp);
    while(!stack_isempty(*p)){
        stack_info item = pop(p);
        if(item != info){
            push(&temp, item);
        }
    }    
}

//Ex 8
void pilha_rotacionar(pilha *p, int n){
    int i;
    pilha temp;
    stack_init(&temp);
    for(i = 0; i < n && !stack_isempty(*p); i++){
        push(&temp, pop(p));
    }
}

//EX 4
void pilha_fundir(pilha *p1, pilha *p2){
    pilha temp;
    stack_init(&temp);
    while(!stack_isempty(*p1)){
        push(&temp, pop(p1));
    }
    while(!stack_isempty(*p2)){
        push(&temp, pop(p2));
    }
}
