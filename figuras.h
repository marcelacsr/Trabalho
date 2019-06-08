#ifndef FIGURAS_H
#define FIGURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

typedef struct triangulo TTRI;

typedef struct circulo TCIR;

typedef struct quadrado TQUA;

typedef struct trapezio TTRA;

typedef struct retangulo TRET;

TCIR *cria_circulo(float raio);
TQUA *cria_quadrado(float lado);
TTRI *cria_triangulo(float base, float altura);
TRET *cria_retangulo(float base, float altura);
TTRA *cria_trapezio(float base_menor, float base_maior, float altura);

float area_trapezio(TTRA *elem);
float area_triangulo(TTRI *elem);
float area_quadrado(TQUA *elem);
float area_circulo(TCIR *elem);
float area_retangulo(TRET *elem);

#endif
