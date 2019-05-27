#include "arvgen.h"

/*Representação de árvore com número variável de filhos:
– utiliza uma “lista de filhos”:
• um nó aponta apenas para seu primeiro (prim) filho
• cada um de seus filhos aponta para o próximo (prox) irmão


• ponteiro para a primeira sub-árvore filha
– NULL se o nó for uma folha
• ponteiro para a próxima sub-árvore irmão
– NULL se for o último filho */

typedef struct ag
{
    int cod;
    //struct info *no;
    struct ag *filho; /* ponteiro para eventual primeiro filho */
    struct ag *irmao; /* ponteiro para eventual irmão */
} TAG;

typedef struct info
{
    int tipo;
    void *info;
} TNO;

TAG *inicializa(void)
{
    return NULL;
}

TAG *cria(int cod)
{
    TAG *a = (TAG *)malloc(sizeof(TAG));
    a->cod = cod;
    //a->info = ;
    a->filho = NULL;
    a->irmao = NULL;
    return a;
}

/* insere uma nova sub-árvore como filha de um dado,
sempre no início da lista, por simplicidade */
void insere(TAG *a, TAG *sa)
{
    sa->irmao = a->filho;
    a->filho = sa;
}

//imprime o conteúdo dos nós em pré-ordem
//primeiro a raiz dps as sub arvores
void imprime(TAG *a)
{
    TAG *p;
    printf("<%d\n", a->cod);
    for (p = a->filho; p != NULL; p = p->irmao)
    {
        //printf(".");
        imprime(p); /* imprime filhos */
    }
    printf(">");
}

void imprime_pre(TAG *a)
{
    if (a)
    {
        printf("%d\n", a->cod);
        imprime_pre(a->irmao);
        imprime_pre(a->filho);
    }
}

void imprime_pos(TAG *a)
{
    if (a)
    {
        imprime_pos(a->irmao);
        printf("%d\n", a->cod);
        imprime_pos(a->filho);
    }
}
