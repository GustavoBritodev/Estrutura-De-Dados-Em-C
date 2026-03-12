#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>

/* Estruturas da lista encadeada simples que armazena inteiros. */
typedef struct Node {
int valor;
struct Node *prox;
} Node;

typedef struct Lista {
Node *head;
int tamanho;
} Lista;

/* Cria e inicializa uma nova lista vazia. Retorna ponteiro para Lista ou NULL. /
Lista criar_lista(void);

/* Libera todos os nós e a própria estrutura da lista. */
void destruir_lista(Lista *l);

/* Retorna 1 se a lista estiver vazia, 0 caso contrário. */
int esta_vazia(const Lista *l);

/* Retorna o número de elementos na lista. */
int tamanho_lista(const Lista *l);

/* Insere valor no início. Retorna 1 em sucesso, 0 em falha de alocação. */
int inserir_inicio(Lista *l, int valor);

/* Insere valor no fim. Retorna 1 em sucesso, 0 em falha de alocação. */
int inserir_fim(Lista *l, int valor);

/* Insere valor na posição pos (0-based). Retorna 1 em sucesso, 0 se pos inválida ou falha. */
int inserir_pos(Lista *l, int valor, int pos);

/* Remove o primeiro nó; se out_valor != NULL armazena o valor removido.
Retorna 1 em sucesso, 0 se a lista estiver vazia. */
int remover_inicio(Lista *l, int *out_valor);

/* Remove o último nó; se out_valor != NULL armazena o valor removido.
Retorna 1 em sucesso, 0 se a lista estiver vazia. */
int remover_fim(Lista *l, int *out_valor);

/* Remove o nó na posição pos (0-based); se out_valor != NULL armazena o valor removido.
Retorna 1 em sucesso, 0 se pos inválida. */
int remover_pos(Lista *l, int pos, int *out_valor);

/* Retorna a posição (0-based) da primeira ocorrência de valor, ou -1 se não encontrado. */
int buscar_valor(const Lista *l, int valor);

/* Lê o valor na posição pos sem removê-lo; armazena em out_valor se não NULL.
Retorna 1 em sucesso, 0 se pos inválida. */
int obter_pos(const Lista *l, int pos, int *out_valor);

/* Imprime os elementos da lista no formato: [v0 -> v1 -> v2] ou [] se vazia. */
void imprimir_lista(const Lista *l);

#endif /* LISTA_H */