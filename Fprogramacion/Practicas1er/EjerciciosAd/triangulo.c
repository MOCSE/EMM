#include <stdio.h>
#include <math.h>

float leerLado(void);
float calcularSemiperimetro(float, float, float);
float calcularArea(float, float, float, float);
void mostrarResultado(float);

void main() {
  float a = leerLado();
  float b = leerLado();
  float c = leerLado();

  float semiPerimetro = calcularSemiperimetro(a, b, c);

  mostrarResultado(calcularArea(a, b, c, semiPerimetro));
}

float leerLado() {
  float numeroEntrada;
  printf("Ingresa el valor del lado: ");
  scanf("%f", &numeroEntrada);

  return numeroEntrada;
}

float calcularSemiperimetro(float a, float b, float c) {
  return (a + b + c) / 2;
}

float calcularArea(float a, float b, float c, float semiPerimetro) {
  return sqrtf(
    semiPerimetro * (semiPerimetro - a) * (semiPerimetro - b) * (semiPerimetro - c)
  );
}

void mostrarResultado(float area) {
  printf("El area calculada es: %.3f\n", area);
}