#include <stdio.h>

float calculaSuperficie(float radio);
float calculaLongitud(float);
void mostrarResult(float s, float);
float datosEntrada(void);

#define PI 3.1416

void main() {
  float radio = 0;
  float s = 0;
  float l = 0;

  radio = datosEntrada();
  s = calculaSuperficie(radio);
  l = calculaLongitud(radio);

  mostrarResult(s, l);
}

float calculaSuperficie(float radio) {
  float s = 0;
  s = PI * (radio * radio);
  return s;
}

float calculaLongitud(float radio) {
  float l = 0;
  l = 2 * PI * radio;
  return l;
}

float datosEntrada(void) {
  float radio = 0;
  printf("Introcuce el radio: ");
  scanf("%f", &radio);
  return radio;
}

void mostrarResult(float s, float l) {
  printf("La superfice es: %f\n", s);
  printf("La longitud es: %f\n", l);
}
