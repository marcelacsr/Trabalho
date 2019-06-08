#include "arvgen.h"
#include "arvgen.c"
#include "learquivo.h"
#include "learquivo.c"
#include "avltree.h"
#include "avltree.c"
#include "auxiliar.h"
#include "auxiliar.c"

int main(void){
    TAG *a = inicializa();
    
    printf("Lendo arquivo..\n");
    a = read_arquivo(a);
    printf("arquivo lido\n preparando impressão\n");
    imprime(a);
    int maior = busca_maior_cod(a);
    printf("\n\n\n *** %d *** \n\n\n", maior);

    AVL_Tree *arv = cover(a);
    imprime_avl(arv->root);
    // menu(a);
    // altera_dimensoes(a,2);
    printf("\n");
    imprime(a);
    printf("\n");
    return 0;
}