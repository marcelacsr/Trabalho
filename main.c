#include "le_arquivo.c"

int main(void)
{
    TAG *a = inicializa();
    printf("Lendo arquivo.. \n");
    a = read_arquivo(a);
    printf("arquivo lido\n preparando impressão\n");
    imprime(a);   
    printf("\n\n\n\n");
    altera_dimensoes(a,2);
    printf("\n\n\n\n");
    // retira_figuras(a, 4);
    // imprime(a);
    // retira_figuras(a, 5);
    // imprime(a);
    // retira_figuras(a, 12);
    // imprime(a);
    // retira_figuras(a, 9);
    // imprime(a);
    // retira_figuras(a, 5);
    // imprime(a);
    // retira_figuras(a, 6);
    imprime(a);



    printf("\n");
    return 0;
}