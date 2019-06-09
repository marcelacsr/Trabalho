main: main.c arvgen.h figuras.h menu.h learquivo.h
	gcc -o main main.c arvgen.c figuras.c menu.c learquivo.c -lm