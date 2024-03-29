#ifndef MENU_H
#define MENU_H

#include "arvgen.h"
#include "figuras.h"
#include "avltree.h"

void menu(TAG *a);
TAG *menu_nova_figura(TAG *a);
void menu_retira_figura(TAG *a);
void menu_altera_dimensoes(TAG *a);
void menu_busca_figura(TAG *a);
int dialogo_codigo_pai();
#endif /* MENU_H */