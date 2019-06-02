#include "arvgen.h"

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
    int cod_pai;
    int tipo;
    void *info;
    struct ag *filho; /* ponteiro para eventual primeiro filho */
    struct ag *irmao; /* ponteiro para eventual irmão */
}TAG;

TAG *inicializa(void)
{
    return NULL;
}

TAG *cria(int cod, int cod_pai, void* elem){
    TAG *a = (TAG *)malloc(sizeof(TAG));
    a->cod = cod;
    a->cod_pai = cod_pai;
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
void imprime(TAG *a){
    if(!a) return;
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

//TODO: testar
//TODO: permitir inserir apenas um nó com cod_pai = 0; pq só um é raiz;
TAG *insere_cria(TAG *a, int cod, int cod_pai, void *elem){
    if(!a){
        printf("Árvore n existe\n");
        if(cod_pai !=0) printf("A arvore está vazia e o nó que vc está tentando inserir não possui código de raiz, a inserção não está autorizada!!!!!!!\n");
        else a = cria(cod, cod_pai, elem);
        return a;
    }
    printf("*** Entrou no insere ***\n");
     //verifica se o cod existe
    if (busca2(a, cod) == 1){
        printf("Cod ja existe!\n");
        return a; // não insere
    }

    //verifica se cod_pai existe
    if (busca2(a, cod_pai) == 0){
        printf("Nao encontrou cod_pai\n");
        return a; //não insere
    }
    printf("*** Antes de criar o novo nó ***\n");
    TAG *novo_no_filho = cria(cod, cod_pai, elem);

    // é raiz!
    if (cod_pai == 0){
        novo_no_filho->cod_pai = cod_pai;

        //se for o primeiro elemento, a n existe??? pq a foi inicializado com NULL
        if (a){
            a->cod_pai = novo_no_filho->cod;
            novo_no_filho->filho = a;
        }
        return novo_no_filho;
    }
    TAG *pai = busca(a, cod_pai); //Busca o nó pai

    //se o nó pai tem filho
    if (pai->filho != NULL){
        a->irmao = pai->filho;
        a->filho = pai->filho->filho;
        pai->filho = novo_no_filho;
    } else {
        pai->filho = novo_no_filho;
    }
    return a;    
}

//Leitura de arquivo
/*
1/0/TRI 3 2
2/1/RET 3 3
3/1/TRA 2 3 4
4/1/CIR 4
5/4/QUA 3
6/2/RET 2 2
7/5/TRA 1 2 3
8/5/CIR 2
9/4/QUA 1
10/1/TRI 1 2
*/

//testar
// TAG *le_arquivo(TAG *a, char *caminho){
//     int n = 25;
//     char linha[n];

//     FILE *arquivo = fopen(caminho, "r");
//     if (arquivo)
//     {
//         while (fgets(linha, n, arquivo) != NULL)
//         {
//             int cod = atoi(strtok(linha, "/"));
//             int cod_pai = atoi(strtok(NULL, "/"));
//             char *figura = strtok(NULL, "");
//             printf("%d %d %s\n", cod, cod_pai, figura);

//             a = insere_cria(a, cod, cod_pai);
//         }
//         fclose(arquivo);
//     }
//     else
//     {
//         printf("Arquivo não encontrado\n");
//     }
//     // TODO arrumar este return
//     return a;
// }