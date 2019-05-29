#include <stdio.h>
#include <stdlib.h>

typedef struct ag TAG;

/* deve ser permitido ao usuário do sistema: 
(a) buscar figuras geométricas, por meio de um código único;  ok
(b) imprimir informações relevantes, tanto da árvore, quanto das figuras, incluindo-se sua área; 
(c) inserir novas figuras; 
(d) retirar figuras, passando seus descendentes para outro pai; 
(e) destruir a árvore; e ok
(f) alterar as dimensões de figuras;  */

TNO * inicializa (void);
TNO * cria (int cod);

//a
TNO *busca (TNO *a, int cod);
int busca2 (TNO *a, int cod);

//b 
void imprime (TNO *a);
void imprime_pre (TNO *a);
void imprime_pos (TNO *a);

//c
void insere (TNO *a, TNO *sa);

//d TODO
void retira_figuras (TNO *a, int cod);

//e
void libera_destroi (TNO *a);

//f TODO
void altera_dimensoes (TNO *a, int cod);