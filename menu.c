#include "menu.h"

void menu(TAG *a);
void menu_nova_figura(TAG *a);

void menu(TAG *a){
    int opt = 1;
    while(opt){
        printf("***Arvores Genericas***\n");
        printf("1 - Criar uma nova arvore\n");
        printf("2 - Imprimir a arvore\n");
        printf("3 - Inserir uma figura\n");
        printf("4 - Remover uma figura\n");
        printf("5 - Alterar as dimensoes de uma figura\n");
        printf("6 - *** vazio ***\n");
        printf("7 - *** vazio ***\n");
        printf("0 - Sair\n");
        scanf(" %d", &opt);
        
        switch (opt){
            case 1:
            break;
            case 2:
                imprime(a);
            break;
            case 3:
                menu_nova_figura(a);
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
        }
    }
    return;
}

void menu_nova_figura(TAG *a){
    int opt = 1;
    while(1){
        printf("*** Figuras ***\n");
        printf("1 - Inserir um circulo\n");
        printf("2 - Inserir um quadrado\n");
        printf("3 - Inserir um triangulo\n");
        printf("4 - Inserir um retangulo\n");
        printf("5 - Inserir um trapezio\n");
        printf("0 - Menu Principal\n");
        scanf(" %d", &opt);

        switch (opt){
            case 0:
                menu(a);
            break;
            case 1:
                printf("Insira as novas dimensões desejadas para o raio");
                float raio = 0;
                int cod_pai = 0;
                scanf(" %f", &raio);
                void *elem = cria_circulo(raio);
                printf("Insira o código do pai");
                scanf(" %d", &cod_pai);
                a = insere_cria(a, 91 , cod_pai,0 ,elem);
            break;
            case 2:
                imprime(a);
            break;
            case 3:
            //TODO fazer função para pegar o maior ID da árvore,
            // para então, ao criar uma figura adicionar esse id +1 como id do nó

            break;
            case 4:
            break;
            case 5:
            break;
        }
    }
}