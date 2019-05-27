#include "arvgen.h"
#include "arvgen.c"


int main(void)
{
    TAG *a, *b, *d, *c, *e, *f, *g, *h = NULL;
    //cria nos como folhas
    a = cria(1);
    b = cria(2);
    c = cria(3);
    d = cria(4);    
    e = cria(5);
    f = cria(6);
    g = cria(7);
    h = cria(8);

    //monta a hierarquia
    insere(c, d);
    insere(b, e);
    insere(b, c);    
    insere(g, h);
    insere(a, g);
    insere(a, f);
    insere(a, b);

    printf("!!!\n !!!\n");
        imprime (a);

    return 0;
}