#include <stdlib.h>
#include <stdio.h>
#include "auxiliar.h"
#include "arvgen.h"
#include "avltree.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void imprime_avl( AVL_TreeNode * T) {
    if (!T) {
        printf(("<>"));
    } else {
        if ((!T->left)&&(!T->right)) {
            printf("<");
            printf(RED"%d"RESET, T->id);
            //visita_info(T->tipo, T->elem);
            printf(">");
        } else {
            printf("<");
            printf(BLU"%d"RESET, T->id);
            //visita_info(T->tipo, T->elem);
            imprime_avl(T->left);
            imprime_avl(T->right);
            printf(">");
        }
    }
}