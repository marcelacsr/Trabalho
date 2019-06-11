#include<stdio.h>
#include<stdlib.h>
#include "avltree.h"


/**
Insere um elemento na árvore binária.

Retorna 1, caso tenha inserido o elemento com sucesso, e 0 caso contrário.

 */
int insertAVL_Tree(AVL_Tree *tree, int id, int tipo, void *elem) {
    if (!tree)return 0;
    int *h = (int*) malloc(sizeof (int));
    *h = 1;
    AVL_TreeNode **ptp = &(tree->root);
    int x = insertAVL_TreeR(ptp,id, tipo, elem, h);
    return x;
}

/**
Função recursiva de inserção na árvore AVL.

 */
int insertAVL_TreeR(AVL_TreeNode **node, int id, int tipo, void *elem, int *h) {
    if (!*node) {//se o nó não existir, é criado um novo no
        AVL_TreeNode *novo = (AVL_TreeNode*) malloc(sizeof (AVL_TreeNode));
        novo->id = id;
        novo->tipo = tipo;
        novo->elem = elem;
        novo->fb = 0;
        novo->left = NULL;
        novo->right = NULL;
        *node = novo;
        *h = 1; //haverá mudança na altura
        return 1;
    } else {
        if ((*node)->id == id) {
            *h = 0;
            return 0;
        }
        if ( id < (*node)->id) {
            insertAVL_TreeR(&((*node)->left), id, tipo, elem, h);
            if (*h == 1) { //se h = 1 então houve mudança na altura da arvore então terã de recalcular o FB e talvez rebalancear. 
                //Se rebalancear então não haverá mais mudança na altura.
                if ((*node)->fb == 0) { //Se fb era 0 então estava balanceada, 
                    (*node)->fb--; //inserindo alguém a esquerda, diminui o fb de 1
                    *h = 1; //e haverá mudança na altura
                } else
                    if ((*node)->fb == 1) {//se o fb era 1 então a direita era mais pesada
                    (*node)->fb--; //Inserindo alguém na esquerda o fb diminuirá de 1
                    *h = 0; //e não haverá mudança na altura
                } else
                    if ((*node)->fb == -1) {//se o fb era -1 então a esquerda é mais pesada
                    (*node)->fb = 0; //insserindo alguém na esquerda o fb irá  a dois e deverá ser rebalanceada, voltando a 0
                    RR(&(*node), h); //caso1
                }
            }
        } else
            if ( id > (*node)->id) {
            insertAVL_TreeR(&((*node)->right), id, tipo, elem, h);
            if (*h == 1) {
                if ((*node)->fb == 1) {//Se fb era 1 então a direita ja tinha alguem, faz uma rotação para esquerda e a altura não muda
                    LR(&(*node), h);
                    *h = 0;
                } else
                    if ((*node)->fb == 0) {
                    (*node)->fb++;
                    *h = 1;
                } else
                    if ((*node)->fb == -1) { //Se fb era -1 então a esquerda era maior, como foi inserido na direita, a altura não muda. 
                    (*node)->fb++;
                    *h = 0;
                }
            }
        }
    }
}

/**
 Rotação a esquerda
 */
void LR(AVL_TreeNode **node, int *h) {
    AVL_TreeNode *ptu = (*node)->right; //pt é igual ao nó.
    if (ptu->fb == 1) {
        (*node)->right = ptu->left;
        ptu->left = *node;
        (*node)->fb = 0; //unica diferença
        *node = ptu;
    } else {
        AVL_TreeNode *ptv = ptu->left;
        ptu->left = ptv->right;
        ptv->right = ptu;
        (*node)->right = ptv->left;
        ptv->left = *node;
        if (ptv->fb == 1)(*node)->fb = -1;
        else (*node)->fb = 0;
        if (ptv->fb == -1) ptu->fb = 1;
        else ptu->fb = 0;
        *node = ptv;
    }
    (*node)->fb = 0;
    *h = 0;
}

/**
 Rotação a direita
 */
void RR(AVL_TreeNode **node, int *h) {//Caso 1
    AVL_TreeNode *p = (*node)->left;
    if (p->fb == -1) {
        (*node)->left = p->right;
        p->right = *node;
        p->fb = 0; //faltou isso aqui
        *node = p;
        // printf(*node->elem);
    } else {
        AVL_TreeNode *q = p->right;
        p->right = q->left;
        q->left = p;
        (*node)->left = q->right;
        q->right = *node;
        if (q->fb == -1)(*node)->fb = 1;
        else (*node)->fb = 0;
        if (q->fb == 1) p->fb = -1;
        else p->fb = 0;
        *node = q;
    }
    (*node)->fb = 0;
    *h = 0;
}

AVL_TreeNode* searchAVL_Tree(AVL_Tree *tree,int id) {
    if (!tree)return 0;
    AVL_TreeNode *x = tree->root;
    if (!tree->root)return 0;
    if (id == tree->root->id)
        return x; //Qual o sentido da busca retornar 1? Não deveria retornar o elemento ou índice?
    else {
        if (id <  x-> id) {
            AVL_Tree * p = (AVL_Tree*) malloc(sizeof (AVL_Tree));
            p->root = x->left;
            return searchAVL_Tree(p, id);
        } else if ( id > x-> id) {
            AVL_Tree *p = (AVL_Tree*) malloc(sizeof (AVL_Tree));
            p->root = x->right;
            return searchAVL_Tree(p, id);
        }
    }
    return 0;
}

void initAVL_Tree(AVL_Tree *tree) {
    if (!tree)return;
    tree->root = NULL;
}

void libera_avl(AVL_TreeNode *tree){
    if (tree){
        libera_avl(tree->left);
        libera_avl(tree->right);
        free(tree->elem);
        free(tree);
    }
}
