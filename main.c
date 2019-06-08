#include "menu.c"

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
    imprime(a);



    printf("\n");
    imprime(a);
    menu();
    return 0;
}