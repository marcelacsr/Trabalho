#ifndef AVLTREE_H
#define AVLTREE_H

#include<stdio.h>
#include<stdlib.h>


typedef struct AVL_TreeNode  AVL_TreeNode;
typedef struct AVL_Tree AVL_Tree;

/*
Insere um elemento na árvore binária.

Retorna 1, caso tenha inserido o elemento com sucesso, e 0 caso contrário.

 */
int insertAVL_Tree(AVL_Tree *tree,int tipo, void *elem);


/*
Função recursiva de inserção na árvore AVL.

 */
int insertAVL_TreeR(AVL_TreeNode **node,int tipo, void *elem, int *h);


/*
Busca um elemento em uma árvore AVL.

Retorna 1, caso tenha encontrado o elemento, e 0 caso contrário.

 */
int searchAVL_Tree(AVL_Tree *tree, void *elem);


void RR(AVL_TreeNode **node, int *h);


void LR(AVL_TreeNode **node, int *h);


void initAVL_Tree(AVL_Tree *tree);


#endif
