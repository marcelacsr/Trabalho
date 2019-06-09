#ifndef AUXILIAR_H
#define AUXILIAR_H

#include "avltree.h"
#include "avltree.c"

/*
Instancia um elemento recebendo um número inteiro.
 
 */
void *initIntElem(int elem);


/*
Visita um elemento do tipo inteiro.
 
 */
void visitIntElem(int tipo, void *elem);

void imprime_avl(AVL_TreeNode *T);


#endif