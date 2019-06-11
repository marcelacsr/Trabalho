main: main.c arvgen.h auxiliar.h avltree.h figuras.h learquivo.h menu.h arvb.h leitura.h
	gcc -o main arvgen.c auxiliar.c avltree.c figuras.c learquivo.c menu.c arvb.c leitura.c main.c -lm

clean:
	rm main

redo: clean main
	./main < entrada