#ifndef ARVB_H
#define ARVB_H

#include <stdio.h>
#include <stdlib.h>


typedef struct ArvB{
  int nchaves, folha;
  struct ArvBNo **chave;
  struct ArvB **filho;
}TAB;

typedef struct ArvBNo{
  int chave;
  int tipo;
  void *elem;
}TABNO;


TAB *Cria(int t);
TAB *Libera(TAB *a);
//void Libera(TAB *a);
void Imprime(TAB *a, int andar);
TAB *Busca(TAB* x, TABNO *ch);
TAB *Inicializa();
TAB *Divisao(TAB *x, int i, TAB* y, int t);
TAB *Insere_Nao_Completo(TAB *x, TABNO* k, int t);
TAB *Insere(TAB *x, TABNO* k, int t);
TAB *remover(TAB* arv, int ch, int t);
TAB *retira(TAB* arv, int k, int t);
#endif