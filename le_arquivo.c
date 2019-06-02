#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "figuras.c"


void read_arquivo(){
    while(1){
        int a = 0, b = 0;
        char fig[4];
        int t = scanf("%d/%d/%s",&a,&b,&fig);
        if(t<=0) break;
        printf("a = %d b = %d fig = %s\n",a,b,fig);
        if(!strcmp(fig,"TRI")){
            int base = 0, altura = 0;
            scanf(" %d %d",&base,&altura);
            printf("base = %d altura = %d\n",base,altura);
            TTRI *fig = cria_triangulo(base, altura);
            imprime_triangulo(fig);
            }
        if(!strcmp(fig,"RET")){
            int base = 0, altura = 0;
            scanf(" %d %d",&base,&altura);
            printf("base = %d altura = %d\n",base,altura);
            TRET *fig = cria_retangulo(base, altura);
            imprime_retangulo(fig);
        }
        if(!strcmp(fig,"TRA")){
            int base_menor = 0, base_maior = 0, altura = 0;
            scanf(" %d %d %d",&base_maior, &base_menor, &altura);
            printf("base_maior = %d base_menor = %d  altura = %d\n",base_maior, base_menor,altura);
            TTRA *fig = cria_trapezio(base_menor,base_maior,altura);
            imprime_trapezio(fig);
        }
        if(!strcmp(fig,"CIR")){
            int raio = 0;
            scanf(" %d",&raio);
            printf("raio = %d \n",raio);
            TCIR *fig = cria_circulo(raio);
            imprime_circulo(fig);
        }
        if(!strcmp(fig,"QUA")){
            int lado = 0;
            scanf(" %d",&lado);
            printf("lado = %d \n",lado);
            TQUA *fig = cria_quadrado(lado);
            imprime_quadrado(fig);
        }
    }
    return;
}