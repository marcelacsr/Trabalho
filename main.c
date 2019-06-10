#include "arvgen.h"
#include "learquivo.h"
#include "menu.h"
#include "avltree.h"
#include "auxiliar.h"


int main(void){
    TAG *a = inicializa();    
    a = read_arquivo(a);    
    menu(a);
    return 0;
}