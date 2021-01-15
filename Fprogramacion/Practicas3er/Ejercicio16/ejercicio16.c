#include <stdio.h>
#include <stdlib.h>

void darDim(int*);
float* crearArreglo(int);
void darDatos(float*, int);
void mostrar(float*, int);
void liberar(float*);
void copia(float*, float*, int);
void restaVectores(float*, float*, float*, int);
void calcularProductoEscalar(float*, float*, int, float*);
void ordenarDesc(float*, int);

void main() {
  int dim;
  float *a, *b, *vResta, *vRestaOrdenado;
  float productoEscalar;

  darDim(&dim);
  a = crearArreglo(dim);
  b = crearArreglo(dim);
  vResta = crearArreglo(dim);
  vRestaOrdenado = crearArreglo(dim);

  darDatos(a, dim);
  darDatos(b, dim);

  restaVectores(a, b, vResta, dim);
  calcularProductoEscalar(a, b, dim, &productoEscalar);
  copia(vResta, vRestaOrdenado, dim);
  ordenarDesc(vRestaOrdenado, dim);

  printf("\nArreglo A:\n");
  mostrar(a, dim);
  printf("\nArreglo B:\n");
  mostrar(b, dim);
  printf("\nResta B-A:\n");
  mostrar(vResta, dim);
  printf("\nResta B-A ordenado\n");
  mostrar(vRestaOrdenado, dim);
  printf("\nProducto Escalar A y B:\n");
  printf("%.2f", productoEscalar);

  liberar(a);
  liberar(b);
  liberar(vResta);
  liberar(vRestaOrdenado);
}

void darDim(int* elem) {
  printf("Ingresa la dimension del arreglo: ");
  scanf("%d", elem);
}

float* crearArreglo(int elem) {
  float* arr;

  arr = (float*) malloc(elem * sizeof(float));

  if (arr == NULL) {
    printf("No hay memoria disponible\n");
    exit(0);
  }
  return arr;
}

void darDatos(float *arr, int elem) {
  int i;

  printf("Ingrese los datos del arreglo:\n");

  for (i = 0; i < elem; i++) {
    printf("\nDato [%d]: ", i + 1);
    scanf("%f", &arr[i]);
  }
}

void mostrar(float *arr, int elem) {
  int i;

  printf("Los datos del arreglo son:\n");
  for (i = 0; i < elem; i++)
    printf("A[%d] = %.2f\n", (i + 1), arr[i]);
}

void liberar(float* arr) {
  free(arr);
  printf("\nMemoria liberada...\n");
}

void restaVectores(float *a, float *b, float *vResta, int dim) {
  // b - a
  int i;

  for (i = 0; i < dim; i++) {
    vResta[i] = b[i] - a[i];
  }
}

void calcularProductoEscalar(float *a, float *b, int dim, float *productoEscalar) {
  int i;
  *productoEscalar = 0;

  for (i = 0; i < dim; i++) {
    *productoEscalar += a[i] * b[i];
  }
}

void copia(float *arr, float *arrCopia, int dim) {
  int i = 0;
  for (i = 0; i < dim; i++) {
    arrCopia[i] = arr[i];
  }
}

void ordenarDesc(float *vRestaOrdenado, int dim) {
  int temp, i, j;
  
  for (j = 0; j < dim; j++) {
    for (i = 0; i < dim - 1; i++) {
      if (vRestaOrdenado[i] < vRestaOrdenado[i + 1]) {
        temp = vRestaOrdenado[i];
        vRestaOrdenado[i] = vRestaOrdenado[i + 1];
        vRestaOrdenado[i + 1] = temp;
      }
    }
  }
}
