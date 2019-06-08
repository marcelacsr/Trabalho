#include "arvgen.h"
#include "arvgen.c"
#include "learquivo.h"
#include "learquivo.c"

int main(void){
    TAG *a = inicializa();
    
    printf("Lendo arquivo..\n");
    a = read_arquivo(a);
    printf("arquivo lido\n preparando impressão\n");
    imprime(a);
    printf("\n");
    retira_figuras(a, 4);
    imprime(a);
    retira_figuras(a, 5);
    imprime(a);
    retira_figuras(a, 12);
    imprime(a);
    retira_figuras(a, 9);
    imprime(a);
    retira_figuras(a, 5);
    imprime(a);
    retira_figuras(a, 6);
    libera_destroi(a); //Dando erro na impressão do trapézio
    imprime(a);        //Dando erro na impressão do trapézio
    return 0;
}