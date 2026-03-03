#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

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

    

    return 0;
}