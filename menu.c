#include "menu.h"
#include "arvgen.h"
#include "figuras.h"
#include "avltree.h"
#include <stdio.h>
#include <stdlib.h> 
#include "leitura.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


void menu(TAG *a){
    int opt = 1;
    AVL_Tree *arv;
    TAB *b = NULL;
    while(opt){
        printf("\n   **************** Árvores Genéricas *****************\n");
        printf("\n   **************** Escolha uma opção *****************\n");
        printf("   || 1 ------------------- Buscar figura geométrica ||\n");
        printf("   || 2 -------------------------- Imprimir a árvore ||\n");
        printf("   || 3 ------------------------- Inserir uma figura ||\n");
        printf("   || 4 ------------------------- Retirar uma figura ||\n");
        printf("   || 5 ---------- Alterar as dimenões de uma figura ||\n");
        printf("   || 6 ------------------ Converter para árvore AVL ||\n");
        printf("   || 7 -------------------- Converter para árvore B ||\n");
        printf("   || 8 - Destruir e reinicializar a arvore genérica ||\n");
        printf("   || 0 --------------------------- "RED"Sair do programa"RESET" ||\n");
        printf("   ****************************************************\n");
        opt =read_int("");

        switch (opt){
            case 0:
                libera_destroi(a);
                printf("\n  Saindo...\n");
                return;
            break;
            case 1:
                menu_busca_figura(a);
            break;
            case 2:
                imprime(a);
            break;
            case 3:
                a = menu_nova_figura(a);
            break;
            case 4:
                menu_retira_figura(a);
            break;
            case 5:
                menu_altera_dimensoes(a);
            break;
            case 6:
                arv = cover(a);
                imprime_avl_normal(arv->root);
                printf("\n");
                imprime_avl_detalhado(arv->root);
                libera_avl(arv->root);
                arv = NULL;
            break;
            case 7:
                b = coverter_em_TAB(a);
                Imprime(b,0);
                Libera(b);
                b = NULL;
            break;
            case 8:
                libera_destroi(a);
                a = inicializa();
                printf("    Arvore genérica destruída!\n");
            break;
            default:
                printf("    Opção Inválida\n");     
            break;
        }
    }
    return;
}

TAG *menu_nova_figura(TAG *a){
    int op = 1;
    int cod_pai = 0;
    float base = 0;
    float altura = 0;
    float lado = 0;
    float raio = 0;
    float base_menor = 0;
    float base_maior = 0;
    void *elem = NULL;
    while(1){
        printf("\n   ************* Figuras ************\n");
        printf("   || "RED"1 ------- Inserir um circulo"RESET" ||\n");
        printf("   || "GRN"2 ------ Inserir um quadrado"RESET" ||\n");
        printf("   || "CYN"3 ----- Inserir um triangulo"RESET" ||\n");
        printf("   || "YEL"4 ----- Inserir um retangulo"RESET" ||\n");
        printf("   || "BLU"5 ------ Inserir um trapezio"RESET" ||\n");
        printf("   || 0 - Voltar ao Menu Principal ||\n");
        printf("   **********************************\n");
        op = read_int("");
        switch (op){
            case 0:
                return a;
            break;
            case 1:
                printf("    Insira a nova dimensão do circulo:\n");
                raio = read_float("    raio: ");
                elem = cria_circulo(raio);
                cod_pai = dialogo_codigo_pai();
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 0, elem);
            break;
            case 2:
                printf("    Insira as novas dimensões do quadrado:\n");
                lado = read_float("    lado: ");
                elem = cria_quadrado(lado);
                cod_pai = dialogo_codigo_pai();
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 1, elem);
            break;
            case 3:
                printf("    Insira as novas dimensões do triangulo:\n");
                base = read_float("    base: ");
                altura = read_float("    altura: ");
                elem = cria_triangulo(base,altura);
                cod_pai = dialogo_codigo_pai();
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 2, elem);
            break;
            case 4: 
                printf("    Insira as novas dimensões do retangulo:\n");
                base = read_float("    base: ");
                altura = read_float("    altura: ");
                elem = cria_retangulo(base,altura);
                cod_pai = dialogo_codigo_pai();
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 3, elem);
            break;
            case 5:
                printf("    Insira as novas dimensões do trapézio:\n");
                base_menor = read_float("    base menor: ");
                base_maior = read_float("    base maior: ");
                altura = read_float("    altura: ");
                elem = cria_trapezio(base_menor, base_maior, altura);
                cod_pai = dialogo_codigo_pai();
                a = insere_cria(a, busca_maior_cod(a)+1, cod_pai, 4, elem);
            break;
            default:
                printf("\nOpção Inválida!\n");     
            break;
        }
    }
}

void menu_retira_figura(TAG *a){
    void *elem = NULL;
    int cod_pai = 0;        
    printf("\n    ************* Retirar Figuras **************\n");
    int cod = read_int("    Insira o código da figura que deseja retirar\n");        
    a = retira_figuras(a, cod);
}

void menu_altera_dimensoes(TAG *a){
    printf("\n    ******************** Alterar Figuras *******************\n");
    int cod = read_int("    Insira o cod do elemento que deseja alterar as dimensoes\n");
    altera_dimensoes(a, cod);
}

void menu_busca_figura(TAG *a){
    printf("\n    ************ Buscar Figuras ************\n");
    int cod = read_int("    Insira o cod da figura que deseja buscar\n");
    TAG *p = NULL;
    p = busca(a, cod);
    if (p){
        visita_info(p->tipo, p->info);
    }
    else
    {
        printf("\n    Código não encontrado!\n");
    }    
}

int dialogo_codigo_pai(){
    return read_int("    Insira o código do pai: ");
}