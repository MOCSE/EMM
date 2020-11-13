#include <stdio.h>
#include <math.h>

void datosEntrada(float *);
void evaluarDerivada(float *, float *);

void main() {
	float x, res;
	
	datosEntrada(&x);
	evaluarDerivada(&x, &res);
	
	printf("El valor de f(x) es: %f \n", res);
}

void datosEntrada(float *x) {
	printf("Ingresa el valor de x a evaluar: ");
	scanf("%f", x);
}

void evaluarDerivada(float *x, float *res) {
	*res = 2.0 / (3.0 * pow((2.0 * (*x) + 4.0), (2.0 / 3.0)));
}
