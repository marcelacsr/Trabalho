#include "arvgen.h"
#include "learquivo.h"
#include "menu.h"
#include "avltree.h"
#include "auxiliar.h"


int main(void){
    TAG *a = inicializa();    
    printf("Lendo arquivo..\n");
    a = read_arquivo(a);
    printf("arquivo lido\n preparando impressão\n");
    imprime(a);
    int maior = busca_maior_cod(a);
    printf("\n\n\n *** %d *** \n\n\n", maior);
    //menu(a);
    altera_dimensoes(a,2);
    AVL_Tree *arv = cover(a);
    imprime_avl(arv->root);
    printf("\n");
    imprime(a);
    printf("\n");
    return 0;
}