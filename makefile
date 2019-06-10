main: main.c arvgen.h auxiliar.h avltree.h figuras.h learquivo.h menu.h arvb.h
	gcc -o main arvgen.c  arvb.c  auxiliar.c  avltree.c  figuras.c  learquivo.c  main.c  menu.c -lm
	