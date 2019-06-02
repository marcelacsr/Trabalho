#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void read_arquivo(){
    while(1){
        int a = 0, b = 0;
        char fig[4];
        int t = scanf("%d/%d/%s",&a,&b,&fig);
        if(t<=0) break;
        printf("codigo %d\n",t);
        printf("a = %d b = %d fig = %s\n",a,b,fig);
        if(!strcmp(fig,"TRI")){
            int base = 0, altura = 0;
            int t =scanf(" %d %d",&base,&altura);
            printf("base = %d altura = %d\n",base,altura);
            printf("codigo %d\n",t);
            }
        if(!strcmp(fig,"RET")){
            int base = 0, altura = 0;
            scanf(" %d %d",&base,&altura);
            printf("base = %d altura = %d\n",base,altura);
        }
        if(!strcmp(fig,"TRA")){
            int base_menor = 0, base_maior = 0, altura = 0;
            scanf(" %d %d %d",&base_maior, &base_menor, &altura);
            printf("base_maior = %d base_menor = %d  altura = %d\n",base_maior, base_menor,altura);
        }
        if(!strcmp(fig,"CIR")){
            int raio = 0;
            scanf(" %d",&raio);
            printf("raio = %d \n",raio);
        }
        if(!strcmp(fig,"QUA")){
            int lado = 0;
            scanf(" %d",&lado);
            printf("lado = %d \n",lado);
        }
    }
    return;
}