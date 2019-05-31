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
    int cod;
    int tipo;
    void *info;
    struct ag *filho; /* ponteiro para eventual primeiro filho */
    struct ag *irmao; /* ponteiro para eventual irmão */
}TAG;

TAG *inicializa(void)
{
    return NULL;
}

TAG *cria(int cod)
{
    TAG *a = (TAG *)malloc(sizeof(TAG));
    a->cod = cod;
    a->info = NULL;
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

void imprime_bonito(TAG *a)
{
    TAG *p;
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
TAG *busca(TAG *a, int cod)
{
    if (!a)
        return NULL;
    if (a->cod == cod)
        return a;
    TAG *irmao = busca(a->irmao, cod);
    if (irmao)
        return irmao;
    return busca(a->filho, cod);
}

int busca2(TAG *a, int cod)
{
    TAG *p;
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

void libera_destroi(TAG *a)
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
void imprime_no(TAG* elem){
	printf("Cód: %d\n", elem->cod);
	if(elem->tipo == 1){
		imprime_circulo(elem->info);
	}
    if(elem->tipo == 2){
		imprime_quadrado(elem->info);
	}
    if(elem->tipo == 3){
		imprime_retangulo(elem->info);
	}
    if(elem->tipo == 4){
		imprime_trapezio(elem->info);
	}
    if(elem->tipo == 5){
		imprime_triangulo(elem->info);
	}
}