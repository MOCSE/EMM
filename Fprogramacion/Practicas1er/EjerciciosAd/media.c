#include <stdio.h>

float leerNumero(void);
float calcularMedia(float, float, float);
void mostrarResultado(float);

void main() {
  int n1 = leerNumero();
  int n2 = leerNumero();
  int n3 = leerNumero();

  mostrarResultado(calcularMedia(n1, n2, n3));
}

float leerNumero() {
  float numeroEntrada;
  printf("Ingresa un numero: ");
  scanf("%f", &numeroEntrada);

  return numeroEntrada;
}

float calcularMedia(float n1, float n2, float n3) {
  return (n1 + n2 + n3) / 3;
}

void mostrarResultado(float resultado) {
  printf("La media es: %f\n", resultado);
}