#include <stdlib.h>
#include <stdio.h>
#include "auxiliar.h"
/**
Instancia um elemento recebendo um número inteiro.
 
 */
void* initIntElem(int elem) {
    int* r = (int*) malloc(sizeof (int));
    *r = elem;
    return (void*) r;
}

/**
Visita um elemento do tipo inteiro.
 
 */
void visitIntElem(int tipo, void *elem) {
    if (tipo == 2){
        imprime_triangulo(elem);
    }
    if (tipo == 3){
        imprime_retangulo(elem);
    }
    if (tipo == 4){
        imprime_trapezio(elem);
    }
    if (tipo == 0){
        imprime_circulo(elem);
    }
    if (tipo == 1){
        imprime_quadrado(elem);
    }
}

void imprime_avl( AVL_TreeNode * T) {
    if (!T) {
        printf(("<>"));
    } else {
        if ((!T->left)&&(!T->right)) {
            printf("<");
            visitIntElem(T->tipo, T->elem);
            printf(">");
        } else {
            printf("<");
            visitIntElem(T->tipo, T->elem);
            imprime_avl(T->left);
            imprime_avl(T->right);
            printf(">");
        }
    }
}