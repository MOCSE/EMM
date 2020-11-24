#include <stdio.h>

void datosEntrada(float *, float *);
void suma(float *, float *, float *);
void resta(float *, float *, float *);
void multiplicacion(float *, float *, float *);
void division(float *, float *, float *);

void main() {
  float n1, n2;
  float res;

  datosEntrada(&n1, &n2);

  //suma:
  printf("\nSuma:\n");
  suma(&n1, &n2, &res);
  printf("%f + %f = %f\n", n1, n2, res);

  //resta:
  printf("\nResta:\n");
  resta(&n1, &n2, &res);
  printf("%f - %f = %f\n", n1, n2, res);

  //multiplicacion:
  printf("\nMultiplicacion:\n");
  multiplicacion(&n1, &n2, &res);
  printf("%f * %f = %f\n", n1, n2, res);

  //division:
  printf("\nDivision:	\n");
  division(&n1, &n2, &res);
  printf("%f / %f = %f\n", n1, n2, res);
}

void datosEntrada(float *n1, float *n2) {
  printf("Ingresa un numero: ");
  scanf("%f", n1);

  printf("Ingresa otro numero: ");
  scanf("%f", n2);
}

void suma(float *n1, float *n2, float *res) {
  *res = *n1 + *n2;
}

void resta(float *n1, float *n2, float *res) {
  *res = *n1 - *n2;
}

void multiplicacion(float *n1, float *n2, float *res) {
  *res = (*n1) * (*n2);
}

void division(float *n1, float *n2, float *res) {
  *res = *n1 / *n2;
}
