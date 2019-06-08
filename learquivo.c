


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "figuras.h"
#include "arvgen.h"


TAG* read_arquivo(TAG* arv){   
    while(1){ //while true msm? 
              //Medicina. Eles fazem o que querem. Digo... Tem um break ali que quebra o laço qnd n tem mais linhas lidas.
        int a = 0, b = 0, tipo = -1;
        char fig[4];
        int t = scanf("%d/%d/%s",&a, &b, fig);
        if(t<=0) break;
        void *figura = NULL;
        if(!strcmp(fig,"TRI")){
            int base = 0, altura = 0;
            scanf(" %d %d",&base,&altura);
            figura = (void *)cria_triangulo(base, altura);
            tipo = 2;
            imprime_triangulo(figura);
            }
        if(!strcmp(fig,"RET")){
            int base = 0, altura = 0;
            scanf(" %d %d",&base,&altura);
            figura = (void *)cria_retangulo(base, altura);
            tipo = 3;
            imprime_retangulo(figura);
        }
        if(!strcmp(fig,"TRA")){
            int base_menor = 0, base_maior = 0, altura = 0;
            scanf(" %d %d %d",&base_maior, &base_menor, &altura);
            figura = (void *)cria_trapezio(base_menor,base_maior,altura);
            tipo = 4;
            imprime_trapezio(figura);
        }
        if(!strcmp(fig,"CIR")){
            int raio = 0;
            scanf(" %d",&raio);
            figura = (void *)cria_circulo(raio);
            tipo = 0;
            imprime_circulo(figura);
        }
        if(!strcmp(fig,"QUA")){
            int lado = 0;
            scanf(" %d",&lado);
            figura = (void *)cria_quadrado(lado);
            tipo = 1;
            imprime_quadrado(figura);
        }
        arv = insere_cria(arv, a, b, tipo, figura);
    }
    if (!freopen("/dev/tty", "r", stdin)) {
        perror("/dev/tty");
        exit(1);
    }
    return arv;
}