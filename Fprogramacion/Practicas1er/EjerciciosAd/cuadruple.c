#include <stdio.h>
#include <math.h>

int leerNumero(void);
int calcularCuadruple(int);
void mostrarResultado(int);

void main() {
  int numero = leerNumero();
  mostrarResultado(calcularCuadruple(numero));
}

int leerNumero() {
  int numeroEntrada;
  printf("Ingresa un numero: ");
  scanf("%d", &numeroEntrada);

  return numeroEntrada;
}

int calcularCuadruple(int numero) {
  return (int) pow(numero, 4);
}

void mostrarResultado(int resultado) {
  printf("El cuadruple es: %d\n", resultado);
}