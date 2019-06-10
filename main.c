#include "arvgen.h"
#include "learquivo.h"
#include "menu.h"
#include "avltree.h"
#include "auxiliar.h"
#include "arvb.h"

int main(void)
{
    //TAG *a = inicializa();
    //printf("Lendo arquivo..\n");
    //a = read_arquivo(a);
    //printf("arquivo lido\npreparando impressão\n");
    //imprime(a);
    //int maior = busca_maior_cod(a);
    //printf("\n\n\n *** %d *** \n\n\n", maior);
    //menu(a);
    //altera_dimensoes(a,2);
    //printf("\n\n\n");
    //AVL_Tree *arv = cover(a);
    //imprime_avl(arv->root);
    //printf("\n\n\n");
    //TAB *arvore = Inicializa();
    TAB *arvore = Cria(2);
    Imprime(arvore, 2);

    int num = 0, from, t;
    while(num != -1){
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf(" %d", &num);
    if (num == -9)
    {
        scanf(" %d", &from);
        arvore = retira(arvore, from, t);
        Imprime(arvore, 0);
    }
    else if (num == -1)
    {
        printf("\n");
        Imprime(arvore, 0);
        Libera(arvore);
        return 0;
    }
    else if (!num)
    {
        printf("\n");
        Imprime(arvore, 0);
    }
    else
        arvore = Insere(arvore, num, t);
    printf("\n\n");
    }
    //imprime(a);
    printf("\n");
    //return 0;
}