main: main.c arvgen.h auxiliar.h avltree.h figuras.h learquivo.h menu.h arvb.h
	gcc -o main arvgen.c auxiliar.c avltree.c figuras.c learquivo.c menu.c arvb.c main.c -lm
	