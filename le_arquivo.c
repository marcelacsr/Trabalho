#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "figuras.c"
#include "arvgen.h"
#include "arvgen.c"


void read_arquivo(TAG* arv){
    while(1){
        int a = 0, b = 0;
        char fig[4];
        int t = scanf("%d/%d/%s",&a,&b,&fig);
        if(t<=0) break;
        printf("a = %d b = %d fig = %s\n",a,b,fig);
        void *figura = NULL;
        if(!strcmp(fig,"TRI")){
            int base = 0, altura = 0;
            scanf(" %d %d",&base,&altura);
            printf("base = %d altura = %d\n",base,altura);
            figura = (void *)cria_triangulo(base, altura);
            imprime_triangulo(figura);
            }
        if(!strcmp(fig,"RET")){
            int base = 0, altura = 0;
            scanf(" %d %d",&base,&altura);
            printf("base = %d altura = %d\n",base,altura);
            figura = (void *)cria_retangulo(base, altura);
            imprime_retangulo(figura);
        }
        if(!strcmp(fig,"TRA")){
            int base_menor = 0, base_maior = 0, altura = 0;
            scanf(" %d %d %d",&base_maior, &base_menor, &altura);
            printf("base_maior = %d base_menor = %d  altura = %d\n",base_maior, base_menor,altura);
            figura = (void *)cria_trapezio(base_menor,base_maior,altura);
            imprime_trapezio(figura);
        }
        if(!strcmp(fig,"CIR")){
            int raio = 0;
            scanf(" %d",&raio);
            printf("raio = %d \n",raio);
            figura = (void *)cria_circulo(raio);
            imprime_circulo(figura);
        }
        if(!strcmp(fig,"QUA")){
            int lado = 0;
            scanf(" %d",&lado);
            printf("lado = %d \n",lado);
            figura = (void *)cria_quadrado(lado);
            imprime_quadrado(figura);
        }
        insere_cria(arv, a, b, fig);
    }
    return;
}