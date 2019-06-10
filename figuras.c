#include <stdio.h>
#include <stdlib.h>
#include "figuras.h"
#include "math.h"
#define PI 3.14
#define CIR 0
#define QUA 1
#define TRI 2
#define RET 3
#define TRA 4

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


TCIR *cria_circulo(float raio){
	TCIR *novo = (TCIR *)malloc(sizeof(TCIR));
	novo->raio = raio;
	return novo;
}

TQUA *cria_quadrado(float lado){
	TQUA *novo = (TQUA *)malloc(sizeof(TQUA));
	novo->lado = lado;
	return novo;
}

TTRI *cria_triangulo(float base, float altura){
	TTRI *novo = (TTRI *)malloc(sizeof(TTRI));
	novo->base = base;
	novo->altura = altura;
	return novo;
}

TRET *cria_retangulo(float base, float altura){
	TRET *novo = (TRET *)malloc(sizeof(TRET));
	novo->base = base;
	novo->altura = altura;
	return novo;
}

TTRA *cria_trapezio(float base_menor, float base_maior, float altura){
	TTRA *novo = (TTRA *)malloc(sizeof(TTRA));
	novo->base_menor = base_menor;
	novo->base_maior = base_maior;
	novo->altura = altura;
	return novo;
}

/*
Impressão: Imprimir atritutos e área
*/
void imprime_circulo(void *elem){
	TCIR *p = (TCIR *)elem;
	printf(RED"Círculo Raio: %.2f - Área: %.2f"RESET, 
	p->raio, area_circulo(p));
}

void imprime_quadrado(void *elem){
	TQUA *p = (TQUA *)elem;
	printf(GRN"Quadrado Lado: %.2f - Área: %.2f"RESET,
	p->lado, area_quadrado(p));
}

void imprime_retangulo(void *elem){
	TRET *p = (TRET *)elem;
	printf(YEL"Retangulo Base: %.2f - Altura: %.2f - Área: %.2f"RESET,
	p->base, p->altura, area_retangulo(p));
}

void imprime_trapezio(void *elem){
	TTRA *p = (TTRA *)elem;
	printf(BLU"Trapezio Base Menor: %.2f - Base Maior: %.2f - Altura: %.2f - Área: %.2f"RESET,
	p->base_maior, p->base_menor, p->altura, area_trapezio(p));
}

void imprime_triangulo(void *elem){
	TTRI *p = (TTRI *)elem;
	printf(CYN"Triangulo Base: %.2f - Altura: %.2f - Área: %.2f"RESET,
	p->base, p->altura, area_triangulo(p));
}

float area_trapezio(TTRA *elem){
	return (((elem->base_maior + elem->base_menor) / 2) * elem->altura);
}

float area_triangulo(TTRI *elem){
	return ((elem->base * elem->altura) / 2);
}

float area_quadrado(TQUA *elem){
	return (elem->lado * elem->lado);
}

float area_circulo(TCIR *elem){
	return (PI * (pow(elem->raio, 2)));
}

float area_retangulo(TRET *elem){
	return (elem->base * elem->altura);
}