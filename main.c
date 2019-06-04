#include "le_arquivo.c"

int main(void)
{
    TAG *a = inicializa();
    printf("Lendo arquivo.. \n");
    a = read_arquivo(a);
    printf("arquivo lido\n preparando impressão\n");
    imprime(a);
    
    printf("\n");
    return 0;
}