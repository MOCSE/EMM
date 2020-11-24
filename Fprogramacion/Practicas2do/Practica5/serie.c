#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leerK(int*);
void calcularSerie(int*, float*);
void desplegarSumatoria(const float*);

void main() {
  int k;
  float sum;

  leerK(&k);
  calcularSerie(&k, &sum);
  desplegarSumatoria(&sum);
}

void leerK(int* k) {
  printf("Ingresa el valor de k: ");
  scanf("%d", k);

  if (*k <= 0) { exit(0); }
}

void calcularSerie(int* k, float* sum) {
  *sum = 0;
  for (int i = 1; i <= 2 * (*k); i++) {
    *sum += powf(-1, i + 1) / i;
  }
}

void desplegarSumatoria(const float* sum) {
  printf("La sumatoria es: %.2f \n", *sum);
}
