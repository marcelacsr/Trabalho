#include "arvgen.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/*Representação de árvore com número variável de filhos:
– utiliza uma “lista de filhos”:
• um nó aponta apenas para seu primeiro (prim) filho
• cada um de seus filhos aponta para o próximo (prox) irmão

• ponteiro para a primeira sub-árvore filha
– NULL se o nó for uma folha
• ponteiro para a próxima sub-árvore irmão
– NULL se for o último filho */

TAG *inicializa(void){
    return NULL;
}

TAG *cria(int cod, int cod_pai, int tipo, void *elem){
    TAG *a = (TAG *)malloc(sizeof(TAG));
    a->cod = cod;
    a->cod_pai = cod_pai;
    a->tipo = tipo;
    a->info = elem;
    a->filho = NULL;
    a->irmao = NULL;
    return a;
}


//imprime o conteúdo dos nós em pré-ordem
//primeiro a raiz dps as sub arvores
void imprime(TAG *a){
    if (!a){
        return;
    }
    if (a){
        TAG *p;
        printf("<"MAG"%d (%d) "RESET, a->cod, a->cod_pai);
        visita_info(a->tipo, a->info);
        for (p = a->filho; p != NULL; p = p->irmao)
        {
            imprime(p); /* imprime filhos */
        }
        printf(">");
    }
}

void imprime_recursivo(TAG *a){
    if (!a){
        printf(("<>"));
    }
    else{
        if ((!a->filho) && (!a->irmao)){
            printf("<");
            printf("%d ", a->cod);
            printf(">");
        }
        else{
            printf("<");
            printf("%d ", a->cod);
            imprime(a->irmao);
            imprime(a->filho);
            printf(">");
        }
    }
}

void imprime_pre(TAG *a){
    if (a){
        printf("%d\n", a->cod);
        imprime_pre(a->irmao);
        imprime_pre(a->filho);
    }
}

void imprime_pos(TAG *a){
    if (a){
        imprime_pos(a->irmao);
        printf("%d\n", a->cod);
        imprime_pos(a->filho);
    }
}

void imprime_bonito(TAG *a){
    TAG *p;
    if (a){
        for (p = a->filho; p != NULL; p = p->irmao)
            printf("---");
        printf("%d\n", a->cod);
        imprime_bonito(a->filho);
        imprime_bonito(a->irmao);
    }
}

TAG *busca(TAG *a, int cod){
    if (!a)
        return NULL;
    if (a->cod == cod)
        return a;
    TAG *irmao = busca(a->irmao, cod);
    if (irmao)
        return irmao;
    return busca(a->filho, cod);
}

int busca2(TAG *a, int cod){
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

// Remove uma figura da arvore, através do seu codigo
TAG *retira_figuras(TAG *a, int cod){
    if (!a)
        return NULL;
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
        //printf("...buscando nó na lista de irmaos...\n");
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
void troca_pai(TAG *pai, TAG *filho){
    if (!filho)
        return;
    if (pai->filho){
        TAG *ult = pai->filho;
        while (ult->irmao){
            //percorre até encontrar o ultimo filho do pai
            ult = ult->irmao;
        }
        ult->irmao = filho;
    }
    TAG *atual = filho;
    while (atual){
        //percorrendo e alterando os cod_pai
        atual->cod_pai = pai->cod;
        atual = atual->irmao;
    }
}

void libera_destroi(TAG *a){
    if (a){
        libera_destroi(a->irmao);
        libera_destroi(a->filho);
        free(a->info);
        free(a);
    }    
}

void libera(TAG *a){
    TAG *p = a->filho;
    while (p != NULL){
        TAG *t = p->irmao;
        free(p->info);
        libera(p);
        p = t;
    }
    free(a);
}

/*
CIRCULO
QUADRADO 
RETANGULO
TRAPEZIO 
TRIANGULO
*/

TAG *insere_cria(TAG *a, int cod, int cod_pai, int tipo, void *elem){
    if (!a){
        if (cod_pai != 0)            
            printf("A arvore está vazia e o nó que vc está tentando inserir não possui código de raiz, a inserção não está autorizada!!!!!!!\n");
        else{
            a = cria(cod, cod_pai, tipo, elem);
        }
        return a;
    }
    //verifica se quer inserir um cod = o cod_pai
    if (cod == cod_pai){
        printf("Código do pai é igual ao código do filho!\n");
        return a; //não insere
    }
    //verifica se o cod existe
    if (busca2(a, cod) == 1){
        printf("Cod ja existe!\n");
        return a; // não insere
    }
    //verifica se cod_pai existe
    if (busca2(a, cod_pai) == 0){
        printf("Nao encontrou cod_pai!\n");
        return a; //não insere
    }
    TAG *novo_no_filho = cria(cod, cod_pai, tipo, elem);
    // é raiz! Caso tentem inserir mais de uma raiz
    if (cod_pai == 0){
        novo_no_filho->cod_pai = cod_pai;
        if (a){
            a->cod_pai = novo_no_filho->cod;
            novo_no_filho->filho = a;
        }
        return novo_no_filho;
    }
    TAG *pai = busca(a, cod_pai); //Busca o nó pai
    //se o nó pai tem filho
    if (pai->filho != NULL){
        novo_no_filho->irmao = pai->filho;
        pai->filho = novo_no_filho;
    }
    else{
        //faz pai->filho apontar para novo_filho
        pai->filho = novo_no_filho;
    }
    return a;
}

void visita_info(int tipo, void *elem){
    if (tipo == 2){
        imprime_triangulo(elem);
    }
    if (tipo == 3){
        imprime_retangulo(elem);
    }
    if (tipo == 4){
        imprime_trapezio(elem);
    }
    if (tipo == 0){
        imprime_circulo(elem);
    }
    if (tipo == 1){
        imprime_quadrado(elem);
    }
}

void altera_dimensoes(TAG* a, int id){
    TAG* p = busca(a,id);
    void *elem = NULL;
    if(p){
        printf("Figura a ser alterada: \n");
        visita_info(p->tipo, p->info);
        printf("Insira as novas dimensões desejadas para");
        if(p-> tipo == 2){
            printf(" a base e altura\n");
            float base = 0, altura = 0;
            scanf(" %f %f", &base, &altura);
            elem = cria_triangulo(base, altura);
        }
        if(p-> tipo == 3){
            printf(" a base e altura\n");
            float base = 0, altura = 0;
            scanf(" %f %f", &base, &altura);
            elem = cria_retangulo(base, altura);
        }
        if(p-> tipo == 4){
            printf(" a base maior, base menor e altura\n");
            float base_maior = 0, base_menor = 0, altura = 0;
            scanf(" %f %f %f", &base_maior, &base_menor, &altura);
            elem = cria_trapezio(base_maior, base_menor, altura);
        }
        if(p-> tipo == 0){
            printf(" o raio");
            float raio = 0;
            scanf(" %f", &raio);
            elem = cria_circulo(raio);
        }
        if(p-> tipo == 1){
            printf(" o lado");
            float lado = 0;
            scanf(" %f", &lado);
            elem = cria_quadrado(lado);
        }
        void *tmp = p->info;
        free(tmp);
        p->info = elem;
        printf("Figura alterada: ");
        visita_info(p->tipo, p->info);
    }
}

int busca_maior_cod(TAG *a){
    if (!a)
        return -1;
    int maior = max(a->cod, busca_maior_cod(a->irmao));
    maior = max(maior, busca_maior_cod(a->filho));
    return maior;
}

int max(int a,int b){
   return a > b ? a : b ;
}

AVL_Tree* cover(TAG *a){
    AVL_Tree *arv = (AVL_Tree*) malloc(sizeof (AVL_Tree));
    initAVL_Tree(arv);
    converte(a,&(arv));
    return arv;
}

void converte(TAG *a, AVL_Tree **arv){
    if(!a){
        return;
    }
    TAG *p;
    
    insertAVL_Tree(*arv, a->cod, a->tipo, a->info);
    for (p = a->filho; p != NULL; p = p->irmao){
        converte(p,&(*arv));
    }
}