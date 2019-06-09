#include <stdlib.h>
#include <stdio.h>
#include "auxiliar.h"
#include "arvgen.h"
#include "avltree.h"

void imprime_avl( AVL_TreeNode * T) {
    if (!T) {
        printf(("<>"));
    } else {
        if ((!T->left)&&(!T->right)) {
            printf("<");
            printf("id: %d", T->id);
            //visita_info(T->tipo, T->elem);
            printf(">");
        } else {
            printf("<");
            printf("id: %d", T->id);
            //visita_info(T->tipo, T->elem);
            imprime_avl(T->left);
            imprime_avl(T->right);
            printf(">");
        }
    }
}