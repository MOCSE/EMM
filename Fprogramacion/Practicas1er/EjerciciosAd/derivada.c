#include <stdio.h>
#include <math.h>

float leerNumero(void);
float evaluarDerivada(float);
void mostrarResultado(float);

void main() {
  float x = leerNumero();
  mostrarResultado(evaluarDerivada(x));
}

float leerNumero() {
  float numeroEntrada;
  printf("Ingresa un numero: ");
  scanf("%f", &numeroEntrada);

  return numeroEntrada;
}

float evaluarDerivada(float x) {
  return 4 * powf((powf(x, 7) / 7 + sqrtf(3) * powf(x, 6)), 3) 
    * (powf(x, 6) + 3 * sqrtf(3) * pow(x, 2));
}

void mostrarResultado(float resultado) {
  printf("Resultado: %f", resultado);
}
