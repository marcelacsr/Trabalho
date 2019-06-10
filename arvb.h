#ifndef ARVB_H
#define ARVB_H

#include <stdio.h>
#include <stdlib.h>


typedef struct ArvB{
  int nchaves, folha, *chave, *tipo;
  void **elem; //vetor de ponteiro para void
  struct ArvB **filho;
}TAB;


TAB *Cria(int t);
TAB *Libera(TAB *a);
//void Libera(TAB *a);
void Imprime(TAB *a, int andar);
TAB *Busca(TAB* x, int ch);
TAB *Inicializa();
TAB *Divisao(TAB *x, int i, TAB* y, int t);
TAB *Insere_Nao_Completo(TAB *x, int k, int tipo, void* elem, int t);
TAB *Insere(TAB *x, int k, int tipo, void* elem, int t);
TAB *remover(TAB* arv, int ch, int t);
TAB *retira(TAB* arv, int k, int t);
#endif