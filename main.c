#include "le_arquivo.c"

int main(void)
{
    TAG *a = inicializa();
    printf("lendo arquivo \n");
    a = read_arquivo(a);
    printf("arquivo lido\n preparando impressão\n");
    imprime(a);
    return 0;
}