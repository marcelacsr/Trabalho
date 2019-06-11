#ifndef FIGURAS_H
#define FIGURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

typedef struct triangulo
{
	float base, altura;
} TTRI;

typedef struct circulo
{
	float raio;
} TCIR;

typedef struct quadrado
{
	float lado;
} TQUA;

typedef struct trapezio
{
	float base_menor, base_maior, altura;
} TTRA;

typedef struct retangulo
{
	float base, altura;
} TRET;

TCIR *cria_circulo(float raio);
TQUA *cria_quadrado(float lado);
TTRI *cria_triangulo(float base, float altura);
TRET *cria_retangulo(float base, float altura);
TTRA *cria_trapezio(float base_menor, float base_maior, float altura);

void imprime_circulo(void *elem);
void imprime_quadrado(void *elem);
void imprime_retangulo(void *elem);
void imprime_trapezio(void *elem);
void imprime_triangulo(void *elem);

float area_trapezio(TTRA *elem);
float area_triangulo(TTRI *elem);
float area_quadrado(TQUA *elem);
float area_circulo(TCIR *elem);
float area_retangulo(TRET *elem);

void *copia_elem(int tipo, void* elem);
#endif
