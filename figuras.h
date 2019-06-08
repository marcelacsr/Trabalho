#ifndef FIGURAS_H
#define FIGURAS_H
typedef struct triangulo {
	float base, altura;
} TTRI;

typedef struct circulo {
	float raio;
} TCIR;

typedef struct quadrado {
	float lado;
} TQUA;

typedef struct trapezio {
	float base_menor, base_maior, altura;
} TTRA;

typedef struct retangulo {
	float base, altura;
} TRET;

TCIR* cria_circulo(float raio);
TQUA* cria_quadrado(float lado);
TTRI* cria_triangulo(float base, float altura);
TRET* cria_retangulo(float base, float altura);
TTRA* cria_trapezio(float base_menor, float base_maior, float altura);
float area_trapezio(TTRA * elem);
float area_triangulo(TTRI * elem);
float area_quadrado(TQUA * elem);
float area_circulo(TCIR * elem);
float area_retangulo(TRET * elem);

#endif /* FIGURAS_H */