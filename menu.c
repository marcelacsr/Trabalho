#include "arvgen.h"
void menu(TAG *a){
    int opt = 1;
    while(opt){
        printf("***Arvores Genericas***\n");
        printf("1 - Criar uma nova arvore\n");
        printf("2 - Imprimir a arvore\n");
        printf("3 - Inserir um circulo\n");
        printf("4 - Inserir um quadrado\n");
        printf("5 - Inserir um triangulo\n");
        printf("6 - Inserir um retangulo\n");
        printf("7 - Inserir um trapezio\n");
        printf("0 - Sair\n");
        scanf(" %d", &opt);
        
        switch (opt){
            case 1:
            break;
            case 2:
                imprime(a);
            break;
            case 3:
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