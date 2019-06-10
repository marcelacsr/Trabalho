#ifndef ARVGEN_H
#define ARVGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "figuras.h"
#include "avltree.h"
#include "auxiliar.h"
#include "arvb.h"


typedef struct ag {
    int cod;
    int cod_pai;
    int tipo;
    void *info;
    struct ag *filho; /* ponteiro para eventual primeiro filho */
    struct ag *irmao; /* ponteiro para eventual irmão */
}TAG;

/* deve ser permitido ao usuário do sistema: 
(a) buscar figuras geométricas, por meio de um código único;  ok
(b) imprimir informações relevantes, tanto da árvore, quanto das figuras, incluindo-se sua área; ok
(c) inserir novas figuras; 
(d) retirar figuras, passando seus descendentes para outro pai; ok
(e) destruir a árvore; e ok
(f) alterar as dimensões de figuras;  */

TAG *inicializa(void);
TAG *cria(int cod, int cod_pai, int tipo, void *elem);
void imprime(TAG *a);
void imprime_recursivo(TAG *a);
void imprime_pre(TAG *a);
void imprime_pos(TAG *a);
void imprime_bonito(TAG *a);
TAG *busca(TAG *a, int cod);
int busca2(TAG *a, int cod);
TAG *retira_figuras(TAG *a, int cod);
void troca_pai(TAG *pai, TAG *filho);
void libera_destroi(TAG *a);
void libera(TAG *a);
TAG *insere_cria(TAG *a, int cod, int cod_pai, int tipo, void *elem);
void visita_info(int tipo, void *elem);
void altera_dimensoes(TAG *a, int cod);
int busca_maior_cod(TAG *a);
int max(int a,int b);
AVL_Tree *cover(TAG *a);
void converte(TAG *a, AVL_Tree **arv);
TAB *coverter_em_TAB(TAG *a);
void converte_em_b(TAG *a, TAB** b);

//c
// TODO VERIFICA SE È USADO E REMOVER
// void insere(TAG *filho, TAG *pai);
#endif
