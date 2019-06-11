#include "menu.h"
#include "arvgen.h"
#include "figuras.h"
#include "avltree.h"

void menu(TAG *a){
    int opt = 1;
    AVL_Tree *arv;
    TAB *b;
    while(opt){
        printf("\n***Arvores Genericas***\n");
        printf("1 - Buscar figura geométrica\n");
        printf("2 - Imprimir a arvore\n");
        printf("3 - Inserir uma figura\n"); //ok
        printf("4 - Retirar uma figura\n"); //ok
        printf("5 - Alterar as dimensoes de uma figura\n");
        printf("6 - Converter para arvore AVL\n");
        printf("7 - Converter para arvore B\n");
        printf("8 - Destruir a arvore genérica\n");
        printf("0 - Sair do programa\n");
        scanf(" %d", &opt);

        switch (opt){
            case 0:
                libera_destroi(a);
                printf("\nSaindo...\n");
                return;
            break;
            case 1:
                menu_busca_figura(a);
            break;
            case 2:
                imprime(a);
            break;
            case 3:
                menu_nova_figura(a);
            break;
            case 4:
                menu_retira_figura(a);
            break;
            case 5:
                menu_altera_dimensoes(a);
            break;
            case 6:
                arv = cover(a);
                imprime_avl(arv->root);
                printf("\nArvore será destruída\n");
                libera_avl(arv->root);
            break;
            case 7:
                b = coverter_em_TAB(a);
                Imprime(b,0);
            break;
            case 8:
                libera_destroi(a);
                printf("Arvore destruída!");
            break;
        }
    }
    return;
}

void menu_nova_figura(TAG *a){
    int op = 1;
    void *elem = NULL;
    int cod_pai = 0;
    float base = 0;
    float altura = 0;
    while(1){
        printf("\n*** Figuras ***\n");
        printf("1 - Inserir um circulo\n");
        printf("2 - Inserir um quadrado\n");
        printf("3 - Inserir um triangulo\n");
        printf("4 - Inserir um retangulo\n");
        printf("5 - Inserir um trapezio\n");
        printf("0 - Voltar ao Menu Principal\n");
        scanf(" %d", &op);

        switch (op){
            case 0:
                return;
            break;
            case 1:
                printf("Insira as novas dimensões do circulo: para o raio\n");
                float raio = 0;
                cod_pai = 0;
                scanf(" %f", &raio);
                elem = cria_circulo(raio);
                dialogo_codigo_pai();
                scanf(" %d", &cod_pai);
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 0, elem);
            break;
            case 2:
                printf("Insira as novas dimensões do quadrado: para o lado\n");
                float lado = 0;
                cod_pai = 0;
                scanf(" %f", &lado);
                elem = cria_quadrado(lado);
                dialogo_codigo_pai();
                scanf(" %d", &cod_pai);
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 1, elem);
            break;
            case 3:
                printf("Insira as novas dimensões do triangulo: para a base e a altura\n");
                base = 0;
                altura = 0;
                int cod_pai = 0;
                scanf(" %f %f", &base, &altura);
                elem = cria_triangulo(base,altura);
                dialogo_codigo_pai();
                scanf(" %d", &cod_pai);
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 2, elem);
            break;
            case 4: 
                printf("Insira as novas dimensões do retangulo: para a base e a altura\n");
                base = 0;
                altura = 0;
                cod_pai = 0;
                scanf(" %f %f", &base, &altura);
                elem = cria_retangulo(base,altura);
                dialogo_codigo_pai();
                scanf(" %d", &cod_pai);
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 3, elem);
            break;
            case 5:
                printf("Insira as novas dimensões do trapézio: base menor, a base maior e a altura\n");
                float base_menor = 0;
                float base_maior = 0;
                float altura = 0;
                cod_pai = 0;
                scanf(" %f %f %f", &base_menor, &base_maior, &altura);
                elem = cria_trapezio(base_menor, base_maior, altura);
                dialogo_codigo_pai();
                scanf(" %d", &cod_pai);
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 4, elem);
            break;
        }
    }
}

void menu_retira_figura(TAG *a){
    int cod = 1;
    void *elem = NULL;
    int cod_pai = 0;        
    printf("\n*** Retirar Figuras ***\n");
    printf("Insira o código da figura que deseja retirar\n");        
    scanf(" %d", &cod);
    a = retira_figuras(a, cod);
}

void menu_altera_dimensoes(TAG *a){
    int cod = 0;    
    printf("\n*** Alterar Figuras ***\n");
    printf("Insira o cod do elemento que deseja alterar as dimensoes\n");
    scanf(" %d", &cod);
    altera_dimensoes(a, cod);
}

void menu_busca_figura(TAG *a){
    int cod = 0;
    printf("\n*** Buscar Figuras ***\n");
    printf("Insira o cod da figura que deseja buscar\n");
    scanf(" %d", &cod);
    TAG *p = NULL;
    p = busca(a, cod);
    if (p){
        visita_info(p->tipo, p->info);
    }
    else
    {
        printf("\nCódigo não encontrado!\n");
    }    
}

void dialogo_codigo_pai(){
    printf("Insira o código do pai\n");
}