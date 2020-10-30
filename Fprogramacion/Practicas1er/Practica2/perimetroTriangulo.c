#include <stdio.h>
#include <math.h>

void leerPunto(float *, float *);
float distanciaDosPuntos(const float *, const float *, 
  const float *, const float *);
float calcularPerimetro(const float *, const float *, const float *);
void mostrarResultado(const float *);

void main() {
  float Ax = 0;
  float Ay = 0;
  float Bx = 0;
  float By = 0;
  float Cx = 0;
  float Cy = 0;

  printf("\nA: \n");
  leerPunto(&Ax, &Ay);
  printf("\nB: \n");
  leerPunto(&Bx, &By);
  printf("\nC: \n");
  leerPunto(&Cx, &Cy);

  float distAB = distanciaDosPuntos(&Ax, &Ay, &Bx, &By);
  float distCB = distanciaDosPuntos(&Cx, &Cy, &Bx, &By);
  float distCA = distanciaDosPuntos(&Cx, &Cy, &Ax, &Ay);

  float perimetro = calcularPerimetro(&distAB, &distCB, &distCA); 

  mostrarResultado(&perimetro);
}

void leerPunto(float *x, float *y) {
  printf("Ingresa el valor de x: ");
  scanf("%f", x);
  printf("Ingresa el valor de y: ");
  scanf("%f", y);
}

float distanciaDosPuntos(const float *x1, const float *y1, 
  const float *x2, const float *y2) {
  return sqrtf(pow(*x2 - *x1, 2) + powf(*y2 - *y1, 2));
}

float calcularPerimetro(const float *distAB, const float *distCB, 
  const float *distCA) {
  return *distAB + *distCB + *distCA;
}

void mostrarResultado(const float *perimetro) {
  printf("El perimetro es: %f\n", *perimetro);
}
