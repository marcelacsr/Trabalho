#include "arvgen.h"
#include "learquivo.h"
#include "menu.h"
#include "avltree.h"
#include "auxiliar.h"
#include "arvb.h"

int main(void)
{
    TAG *a = inicializa();
    printf("Lendo arquivo..\n");
    a = read_arquivo(a);
    TAB *b = Inicializa();
    b = coverter_em_TAB(a);
    Imprime(b,0);
    
}