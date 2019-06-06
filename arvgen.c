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
    int cod_pai;
    int tipo;
    void *info;
    struct ag *filho; /* ponteiro para eventual primeiro filho */
    struct ag *irmao; /* ponteiro para eventual irmão */
} TAG;

TAG *inicializa(void)
{
    return NULL;
}

TAG *cria(int cod, int cod_pai, int tipo, void *elem)
{
    printf("Criando estrutura do cod: %d\n", cod);
    TAG *a = (TAG *)malloc(sizeof(TAG));
    a->cod = cod;
    a->cod_pai = cod_pai;
    a->tipo = tipo;
    a->info = elem;
    a->filho = NULL;
    a->irmao = NULL;
    return a;
}

/* insere uma nova sub-árvore como filha de um dado,
sempre no início da lista, por simplicidade */

void insere(TAG *a, TAG *sa)
//TODO verificar se o elemento(cod) já existe primeiro
{
    sa->irmao = a->filho;
    a->filho = sa;
}

//imprime o conteúdo dos nós em pré-ordem
//primeiro a raiz dps as sub arvores
void imprime(TAG *a)
{
    if (!a)
        return;
    TAG *p;
    printf("<%d\n", a->cod);
    visita_info(a->tipo,a->info);
    for (p = a->filho; p != NULL; p = p->irmao)
    {
        //printf(".");
        imprime(p); /* imprime filhos */
    }
    printf(">");
}

void imprime_recursivo(TAG *a)
{
    if (!a)
    {
        printf(("<>"));
    }
    else
    {
        if ((!a->filho) && (!a->irmao))
        {
            printf("<");
            printf("%d ", a->cod);
            printf(">");
        }
        else
        {
            printf("<");
            printf("%d ", a->cod);
            imprime(a->irmao);
            imprime(a->filho);
            printf(">");
        }
    }
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
    printf("buscando codigo... \n");
    TAG *p;
    if (a->cod == cod) //encontrou, retorna 1
        return 1;
    else
    {
        for (p = a->filho; p != NULL; p = p->irmao)
        {
            if (busca2(p, cod))
                return 1;
        }
    }
    return 0; //retorna 0, nao encontrou
}
// Separar em um metodo que associa um filho a um pai
// E troca o cod do pai
// Remove uma figura da arvore, através do seu codigo
TAG *retira_figuras(TAG *a, int cod){
    if(!a) return NULL;
    TAG *r = busca(a, cod); //encontrou o elemento
    if (!r){
        printf("Elemento não encontrado!\n");
        return r; //NULL
    }
    if (r->cod_pai == 0){
        printf("Elemento é RAIZ, não pode ser removido!\n");
        return a;
    }
    printf("\nRemovendo o elemento de código: %d\n", cod);
    TAG *pai = busca(a, r->cod_pai); //encontrar o pai do elemento que quer remover
    TAG *atual = pai->filho;
    TAG *ant = NULL;
    while ((atual->irmao) && (atual->cod != cod)){        
        ant = atual;
        atual = atual->irmao;
        printf("...buscando nó na lista de irmaos...\n");
    }
    printf("\n");
    // Não é o primeiro filho da lista de filhos && r não tem filhos
    if ((ant != NULL) && (r->filho == NULL)){
        ant->irmao = atual->irmao;
        free(r);
        return a;
    }
    // É o primeiro filho da lista de filhos && r não tem filhos
    if ((ant == NULL) && (r->filho == NULL)){
        pai->filho = r->irmao;
        free(r);
        return a;
    }
    // É o primeiro filho da lista de filhos && r tem filhos
    if ((ant == NULL) && (r->filho != NULL)){
        pai->filho = r->irmao;
        troca_pai(pai, r->filho);
        free(r); 
        return a;
    }
    // esta no meio da lista de filhos e irmao esquerda não tem filhos
    if (ant->filho == NULL){
        ant->irmao = atual->irmao;
        troca_pai(pai, atual->filho);        
        free(r);
        return a;
    }
    // esta no meio da lista de filhos e irmao esquerda tem filhos
    if (ant->filho != NULL){
        ant->irmao = atual->irmao;
        troca_pai(pai, r->filho);
        free(r);
        return a;
    }
    return a;
}

//Muda os codigos do pai e associa a um novo pai(avó)!
void troca_pai(TAG *pai, TAG *filho) {
    if(!filho) return;    
    printf("\n****Entrou no troca pai***\n");    
    if(pai->filho) { 
        TAG *ult = pai->filho; 
		while(ult->irmao) {
            //percorre até encontrar o ultimo filho do pai
            ult = ult->irmao;
        }        
		ult->irmao = filho;
	}
	TAG *atual = filho;
	while(atual) { 
        //percorrendo e alterando os cod_pai
		atual->cod_pai = pai->cod;
		atual = atual->irmao;
	}
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
void imprime_no(TAG *elem)
{
    printf("Cód: %d\n", elem->cod);
    if (elem->tipo == 1)
    {
        imprime_circulo(elem->info);
    }
    if (elem->tipo == 2)
    {
        imprime_quadrado(elem->info);
    }
    if (elem->tipo == 3)
    {
        imprime_retangulo(elem->info);
    }
    if (elem->tipo == 4)
    {
        imprime_trapezio(elem->info);
    }
    if (elem->tipo == 5)
    {
        imprime_triangulo(elem->info);
    }
}

//TODO: testar
//TODO: permitir inserir apenas um nó com cod_pai = 0; pq só um é raiz;
TAG *insere_cria(TAG *a, int cod, int cod_pai, int tipo, void *elem)
{
    if (!a)
    {
        printf("Árvore não existe\n");
        if (cod_pai != 0)
            printf("A arvore está vazia e o nó que vc está tentando inserir não possui código de raiz, a inserção não está autorizada!!!!!!!\n");
        else
        {
            a = cria(cod, cod_pai, tipo, elem);
            printf("Nó raiz criado!");
        }
        return a;
    }
    printf("*** Entrou no insere ***\n");
    //verifica se quer inserir um cod = o cod_pai
    if (cod == cod_pai)
    {
        printf("Código do pai é igual ao código do filho\n");
        return a; //não insere
    }
    //verifica se o cod existe
    if (busca2(a, cod) == 1)
    {
        printf("Cod ja existe!\n");
        return a; // não insere
    }

    //verifica se cod_pai existe
    if (busca2(a, cod_pai) == 0)
    {
        printf("Nao encontrou cod_pai\n");
        return a; //não insere
    }

    printf("*** Antes de criar o novo nó ***\n");
    TAG *novo_no_filho = cria(cod, cod_pai, tipo, elem);

    // é raiz! Caso tentem inserir mais de uma raiz
    if (cod_pai == 0)
    {
        novo_no_filho->cod_pai = cod_pai;
        //se for o primeiro elemento, a nao existe??? pq a foi inicializado com NULL
        if (a)
        {
            printf("a existe");
            a->cod_pai = novo_no_filho->cod;
            novo_no_filho->filho = a;
        }
        return novo_no_filho;
    }
    TAG *pai = busca(a, cod_pai); //Busca o nó pai

    //se o nó pai tem filho
    if (pai->filho != NULL)
    {
        novo_no_filho->irmao = pai->filho;
        pai->filho = novo_no_filho;
    }
    else
    {
        printf("\nfaz pai->filho apontar para novo_filho\n");
        pai->filho = novo_no_filho;
    }
    printf("\nimprime arvore parcial\n");
    imprime(a);
    printf("\n");
    return a;    
} 

void visita_info(int tipo,void *elem){
        if(tipo == 2){
            imprime_triangulo(elem);
        }
        if(tipo == 3){
            imprime_retangulo(elem);
        }
        if(tipo == 4){
            imprime_trapezio(elem);
        }
        if(tipo == 0){
            imprime_circulo(elem);
        }
        if(tipo == 1){
            imprime_quadrado(elem);
        }
}

void altera_dimensoes(TAG* a, int id){
    TAG* p = busca(a,id);
    void *elem = NULL;
    if(p){
        visita_info(a->tipo,a->info);
        printf("Insira as novas dimensões desejadas para");
        if(a-> tipo == 2){
            printf(" a base e altura\n");
            float base = 99, altura = 99;
            scanf(" %d %d", &base, &altura);
            elem = cria_triangulo(base, altura) ;
        }
        if(a-> tipo == 3){
            printf(" a base e altura\n");
            float base = 0, altura = 0;
            scanf(" %d %d", &base, &altura);
            elem = cria_retangulo(base, altura);
        }
        if(a-> tipo == 4){
            printf(" a base maior, base menor e altura\n");
            float base_maior = 0, base_menor = 0, altura = 0;
            scanf(" %d %d %d", &base_maior, &base_menor, &altura);
            elem = cria_trapezio(base_maior, base_menor, altura);
        }
        if(a-> tipo == 0){
            printf(" o raio");
            float raio = 0;
            scanf(" %d", &raio);
            elem = cria_circulo(raio);
        }
        if(a-> tipo == 1){
            printf(" o lado");
            float lado = 0;
            scanf(" %d", &lado);
            elem = cria_quadrado(lado);
        }
        void *tmp = a->info;
        free(tmp);
        a->info = elem;
    }
}