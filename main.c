#include "arvgen.h"
#include "arvgen.c"
#include "learquivo.h"
#include "learquivo.c"
#include "menu.h"
#include "menu.c"

int main(void){
    TAG *a = inicializa();    
    printf("Lendo arquivo..\n");
    a = read_arquivo(a);
    printf("arquivo lido\n preparando impressão\n");
    imprime(a);
    int maior = busca_maior_cod(a);
    printf("\n\n\n *** %d *** \n\n\n", maior);

    // menu(a);
    // altera_dimensoes(a,2);
    printf("\n");
    imprime(a);
    printf("\n");
    return 0;
}