#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

bool delimitadores_casam(char c1, char c2){
    return
        (c1 == '(' && c2 == ')') ||
        (c1 == '[' && c2 == ']') ||
        (c1 == '{' && c2 == '}');
}

#define DELIMITADOR_ABRE 1
#define DELIMITADOR_FECHA 2
#define NAO_DELIMITADOR 0

int eh_delimitador(char c){

    if(c == '(' || c == '[' || c == '{')
        return DELIMITADOR_ABRE;
    if(c == ')' || c == ']' || c == '}')
        return DELIMITADOR_FECHA;
    return NAO_DELIMITADOR;
}

int main(){

    const char *exp = "(a[x(+]]b){a+b}";
    pilha p;
    stack_init(&p);

    int i;
    for(i = 0; exp[i] != '\0'; i++){
        switch(eh_delimitador(exp[i])){
            case DELIMITADOR_ABRE:
                push(&p, exp[i]);
                break;
            case DELIMITADOR_FECHA:
                if(delimitadores_casam(top(p), exp[i])){
                    pop(&p);
                } else {
                    printf("Erro de exp!!\n");
                    exit(1);
                }
        }
    }

    if(!stack_isempty(p)){
        printf("Erro de exp!!\n");
    } else {
        printf("Contra a Maquina melhor canal do youtube!!!!\n");
    }

    fila f1, f2, res;
    fila_init(&f1); fila_init(&f2); fila_init(&res);

    enqueue(&f1, 'A'); enqueue(&f1, 'B'); enqueue(&f1, 'C'); enqueue(&f1, 'D');
    printf("Antes inverter: ");
    while(!fila_vazia(&f1)) printf("%c", dequeue(&f1));
    printf("\n");

    enqueue(&f1, 'A'); enqueue(&f1, 'B'); enqueue(&f1, 'C'); enqueue(&f1, 'D');
    inverter_fila(&f1);
    printf("Depois inverter: ");
    while(!fila_vazia(&f1)) printf("%c", dequeue(&f1));
    printf("\n");

    enqueue(&f1, 'A'); enqueue(&f1, 'B'); enqueue(&f1, 'C'); enqueue(&f1, 'B'); enqueue(&f1, 'E');
    mover_para_final(&f1, 'B');
    printf("Depois mover_para_final(B): ");
    while(!fila_vazia(&f1)) printf("%c", dequeue(&f1));
    printf("\n");

    enqueue(&f1, '1'); enqueue(&f1, '3'); enqueue(&f1, '5');
    enqueue(&f2, '2'); enqueue(&f2, '4');
    intercalar_filas(&f1, &f2, &res);
    printf("Intercalada: ");
    while(!fila_vazia(&res)) printf("%c", dequeue(&res));
    printf("\n");

    enqueue(&f1, 'A'); enqueue(&f1, 'A'); enqueue(&f1, 'B'); enqueue(&f1, 'B'); enqueue(&f1, 'C');
    remover_duplicatas_consecutivas(&f1);
    printf("Depois remover_duplicatas_consecutivas: ");
    while(!fila_vazia(&f1)) printf("%c", dequeue(&f1));
    printf("\n");

    enqueue(&f1, 'X'); enqueue(&f1, 'Y'); enqueue(&f1, 'Z'); enqueue(&f1, 'W');
    rotacionar_fila(&f1, 1);
    printf("Depois rotacionar +1: ");
    while(!fila_vazia(&f1)) printf("%c", dequeue(&f1));
    printf("\n");

    fila_destroi(&f1);
    fila_destroi(&f2);
    fila_destroi(&res);

    return 0;
}