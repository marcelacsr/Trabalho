#include <math.h>
#define PI 3.14

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
TCIR* cria_circulo(float raio){
	TCIR* novo = (TCIR*) malloc(sizeof(TCIR));
	novo->raio = raio;
	return novo;
}

TQUA* cria_quadrado(float lado){
	TQUA* novo = (TQUA*) malloc(sizeof(TQUA));
	novo->lado = lado;
	return novo;
}

TTRI* cria_triangulo(float base, float altura){
	TTRI* novo = (TTRI*) malloc(sizeof(TTRI));
	novo->base = base;
	novo->altura = altura;
	return novo;
}

TRET* cria_retangulo(float base, float altura){
	TRET* novo = (TRET*) malloc(sizeof(TRET));
	novo->base = base;
	novo->altura = altura;
	return novo;
}

TTRA* cria_trapezio(float base_menor, float base_maior, float altura){
	TTRA* novo = (TTRA*) malloc(sizeof(TTRA));
	novo->base_menor = base_menor;
	novo->base_maior = base_maior;
	novo->altura = altura;
	return novo;
}


/*
Impressão: Imprimir atritutos e área
*/
void imprime_circulo(void* elem){
	TCIR* p = (TCIR*)elem;
	printf("Este é um tipo Círculo \nRaio: %.2f - Área: %.2f\n\n", p->raio, area_circulo(p));
}

void imprime_quadrado(void* elem){
	TQUA* p = (TQUA*)elem;
	printf("Este é um tipo Quadrado \nLado: %.2f - Área: %.2f\n\n", p->lado, area_quadrado(p));
}

void imprime_retangulo(void* elem){
	TRET* p = (TRET*)elem;
	printf("Este é um tipo Retangulo \nBase: %.2f - Altura: %.2f - Área: %.2f\n\n", p->base, p->altura, area_retangulo(p));
}

void imprime_trapezio(void* elem){
	TTRA* p = (TTRA*)elem;
	printf("Este é um tipo Trapezio \nBase Menor: %.2f - Base Maior: %.2f - Altura: %.2f - Área: %.2f\n\n",
	p->base_maior, p->base_menor,p->altura,area_trapezio(p));
}

void imprime_triangulo(void* elem){
	TTRI* p = (TTRI*)elem;
	printf("Este é um tipo Triangulo \nBase: %.2f - Altura: %.2f - Área: %.2f\n\n", p->base, p->altura,area_triangulo(p));
}

float area_trapezio(TTRA * elem){
	return ((elem->base_maior + elem->base_menor)/2)* elem->altura;
}

float area_triangulo(TTRI * elem){
	return ((elem->base * elem->altura)/2);
}

float area_quadrado(TQUA * elem){
	return (elem->lado * elem->lado);
}

float area_circulo(TCIR * elem){
	return PI*(pow(elem->raio,2));
}

float area_retangulo(TRET * elem){
	return  elem->base * elem-> altura;
}