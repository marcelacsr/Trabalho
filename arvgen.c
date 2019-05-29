#include "arvgen.h"
#include "figuras.c"

/*Representação de árvore com número variável de filhos:
– utiliza uma “lista de filhos”:
• um nó aponta apenas para seu primeiro (prim) filho
• cada um de seus filhos aponta para o próximo (prox) irmão

• ponteiro para a primeira sub-árvore filha
– NULL se o nó for uma folha
• ponteiro para a próxima sub-árvore irmão
– NULL se for o último filho */

typedef struct ag{
    struct ini *no;
} TAG;

typedef struct no{
    int cod;
    int tipo;
    void *info;
    struct ag *filho; /* ponteiro para eventual primeiro filho */
    struct ag *irmao; /* ponteiro para eventual irmão */
}TNO;

TNO *inicializa(void)
{
    return NULL;
}

TNO *cria(int cod)
{
    TNO *a = (TNO *)malloc(sizeof(TNO));
    a->cod = cod;
    //a->info = ;
    a->filho = NULL;
    a->irmao = NULL;
    return a;
}

/* insere uma nova sub-árvore como filha de um dado,
sempre no início da lista, por simplicidade */
void insere(TNO *a, TNO *sa)
{
    sa->irmao = a->filho;
    a->filho = sa;
}

//imprime o conteúdo dos nós em pré-ordem
//primeiro a raiz dps as sub arvores
void imprime(TNO *a)
{
    TNO *p;
    printf("<%d\n", a->cod);
    for (p = a->filho; p != NULL; p = p->irmao)
    {
        //printf(".");
        imprime(p); /* imprime filhos */
    }
    printf(">");
}

void imprime_pre(TNO *a)
{
    if (a)
    {
        printf("%d\n", a->cod);
        imprime_pre(a->irmao);
        imprime_pre(a->filho);
    }
}

void imprime_pos(TNO *a)
{
    if (a)
    {
        imprime_pos(a->irmao);
        printf("%d\n", a->cod);
        imprime_pos(a->filho);
    }
}

void imprime_bonito(TNO *a)
{
    TNO *p;
    if (a)
    {
        for (p = a->filho; p != NULL; p = p->irmao)
            printf("---");
        printf("%d\n", a->cod);
        imprime_bonito(a->filho);
        imprime_bonito(a->irmao);
    }
}

//todo dando segment fault quando n existe
TNO *busca(TNO *a, int cod)
{
    if (!a)
        return NULL;
    if (a->cod == cod)
        return a;
    TNO *irmao = busca(a->irmao, cod);
    if (irmao)
        return irmao;
    return busca(a->filho, cod);
}

int busca2(TNO *a, int cod)
{
    TNO *p;
    if (a->cod == cod)
        return 1;
    else
    {
        for (p = a->filho; p != NULL; p = p->irmao)
        {
            if (busca2(p, cod))
                return 1;
        }
    }
    return 0;
}

void libera_destroi(TNO *a)
{
    if (a)
    {
        libera_destroi(a->irmao);
        libera_destroi(a->filho);
        free(a);
    }
}


/*
CIRCULO
QUADRADO 
RETANGULO
TRAPEZIO 
TRIANGULO
*/
void imprime_no(TNO* elem){
	printf("Cód: %d\n", elem->cod);
	if(elem->tipo == 1){
		imprime_quadrado(elem->info);
	}
}