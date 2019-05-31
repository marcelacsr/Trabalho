#include <stdio.h>
#include <stdlib.h>

typedef struct ag TAG;
typedef struct no TNO;

/* deve ser permitido ao usuário do sistema: 
(a) buscar figuras geométricas, por meio de um código único;  ok
(b) imprimir informações relevantes, tanto da árvore, quanto das figuras, incluindo-se sua área; 
(c) inserir novas figuras; 
(d) retirar figuras, passando seus descendentes para outro pai; 
(e) destruir a árvore; e ok
(f) alterar as dimensões de figuras;  */

TAG *inicializa (void);
TAG *cria (int cod, int cod_pai);

TAG *insere_cria(TAG *a, int cod, int cod_pai);
//a
TAG *busca (TAG *a, int cod);
int busca2 (TAG *a, int cod);

//b 
void imprime (TAG *a);
void imprime_pre (TAG *a);
void imprime_pos (TAG *a);

//c
void insere (TAG *filho, TAG *pai);

//d TODO
void retira_figuras (TAG *a, int cod);

//e
void libera_destroi (TAG *a);

//f TODO
void altera_dimensoes (TAG *a, int cod);

TAG* le_arquivo(TAG *t, char* path);