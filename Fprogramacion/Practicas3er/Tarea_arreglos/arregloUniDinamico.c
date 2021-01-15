#include <stdio.h>
#include <stdlib.h>

void darDim(int* elem);
int* crearArreglo(int elem);
void darDatos(int*, int);
void mostrar(int*, int);
void liberar(int*);
void redimensionar(int*, int*);

void main(){
  int* arr, elem;

  darDim(&elem);
  arr = crearArreglo(elem);
  darDatos(arr, elem);
  mostrar(arr, elem);
  redimensionar(arr, &elem);
  mostrar(arr, elem);
  liberar(arr);
}

void darDim(int* elem) {
  printf("Ingresa la dimension del arreglo: ");
  scanf("%d", elem);
}

int* crearArreglo(int elem) {
  int* arr;

  arr = (int*) malloc(elem * sizeof(int));

  if (arr == NULL) {
    printf("No hay memoria disponible\n");
    exit(0);
  }
  return arr;
}

void darDatos(int* arr, int elem) {
  int i;

  printf("Ingrese los datos del arreglo:\n");

  for (i = 0; i < elem; i++) {
    printf("\nA[%d]: ", i + 1);
    scanf("%d", &arr[i]);
  }
}

void mostrar(int* arr, int elem) {
  int i;

  printf("Los datos del arreglo son:\n");
  for (i = 0; i < elem; i++)
    printf("A[%d] = %d\n", (i + 1), arr[i]);
}

void liberar(int* arr) {
  free(arr);
  printf("\nMemoria liberada...\n");
}

void redimensionar(int* arr, int* elem) {
  int i, n, nvotam, *arr1;

  printf("Ingrese el numero de nuevos elementos: ");
  scanf("%d", &n);

  nvotam = (*elem) + n;
  arr1 = (int*) realloc(arr, nvotam * sizeof(int));

  for(i = (*elem); i < nvotam; i++) {
    printf("\nA[%d]: ", i + 1);
    scanf("%d", &arr1[i]);
  }

  (*elem) = nvotam;
  arr = arr1;
}