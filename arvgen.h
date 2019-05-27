#include <stdio.h>
#include <stdlib.h>

typedef struct ag TAG;

/* deve ser permitido ao usuário do sistema: 
(a) buscar figuras geométricas, por meio de um código único; 
(b) imprimir informações relevantes, tanto da árvore, quanto das figuras, incluindo-se sua área; 
(c) inserir novas figuras; 
(d) retirar figuras, passando seus descendentes para outro pai; 
(e) destruir a árvore; e 
(f) alterar as dimensões de figuras;  */

TAG * inicializa (void);
TAG * cria (int cod);

//a
int busca (TAG *a, int cod);

//b 
void imprime (TAG *a);

//c
void insere (TAG *a, TAG *sa);

//d
void retira_figuras (TAG *a, int cod);

//e
void libera_destroi (TAG *a);

//f
void altera_dimensoes (TAG *a, int cod);