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

TCIR* criar_circulo(float raio);
TQUA* criar_quadrado(float lado);
TTRI* criar_triangulo(float base, float altura);
TRET* criar_retangulo(float base, float altura);
TTRA* criar_trapezio(float base_menor, float base_maior, float altura);

TCIR* criar_circulo(float raio){
	TCIR* novo = (TCIR*) malloc(sizeof(TCIR));
	novo->raio = raio;
	return novo;
}

TQUA* criar_quadrado(float lado){
	TQUA* novo = (TQUA*) malloc(sizeof(TQUA));
	novo->lado = lado;
	return novo;
}

TTRI* criar_triangulo(float base, float altura){
	TTRI* novo = (TTRI*) malloc(sizeof(TTRI));
	novo->base = base;
	novo->altura = altura;
	return novo;
}

TRET* criar_retangulo(float base, float altura){
	TRET* novo = (TRET*) malloc(sizeof(TRET));
	novo->base = base;
	novo->altura = altura;
	return novo;
}

TTRA* criar_trapezio(float base_menor, float base_maior, float altura){
	TTRA* novo = (TTRA*) malloc(sizeof(TTRA));
	novo->base_menor = base_menor;
	novo->base_maior = base_maior;
	novo->altura = altura;
	return novo;
}


/*
Impressão: Imprimir atritutos e área
*/
void imprime_quadrado(void* elem){
	TQUA* p = (TQUA*)elem;
	printf("Este é um tipo Quadrado \nLado: %.2f - Área: %.2f\n", p->lado, p->lado*p->lado);
}
