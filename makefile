main: main.c arvgen.h auxiliar.h avltree.h figuras.h learquivo.h menu.h
	gcc -o main arvgen.c  auxiliar.c  avltree.c  figuras.c  learquivo.c  main.c  menu.c -lm
	