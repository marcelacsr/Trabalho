#include "le_arquivo.c"

int main(void)
{
    TAG *a = inicializa();
    printf("Lendo arquivo.. \n");
    a = read_arquivo(a);
    printf("arquivo lido\n preparando impressão\n");
    imprime(a);
    
    printf("\n");

    retira_figuras(a, 4);
    retira_figuras(a, 9);
    retira_figuras(a, 8);
    imprime(a);
    retira_figuras(a, 1);
    retira_figuras(a, 9);
    retira_figuras(a, 11);
    imprime(a);

    return 0;
}