#include <stdio.h>
#include <stdlib.h>

void darNumeroElem(int*);
void llenarArray(int*, const int*);
void mostrarArray(const int*, const int*);
int obtenerElementosRepetidos(const int*, const int*, int*);
int buscar(const int*, const int*, const int*);

#define MAXTAM 25

void main() {
  int arr[MAXTAM], arrRepeticiones[MAXTAM];
  int tam, tam2;

  darNumeroElem(&tam);
  llenarArray(arr, &tam);
  tam2 = obtenerElementosRepetidos(arr, &tam, arrRepeticiones);

  printf("\nArreglo Original:\n");
  mostrarArray(arr, &tam);
  printf("\nArreglo de repeticiones:\n");
  mostrarArray(arrRepeticiones, &tam2); 
}

void darNumeroElem(int* tam) {
  int status = 0;
  while (status == 0) {
    printf("\nIngresa la cantidad de datos a leer (x < %d): ", MAXTAM);
    scanf("%d", tam);

    if (*tam < MAXTAM) { status = 1; }
    else {
      printf("El numero debe ser menor a 50. Intente de nuevo.\n");
      status = 0;
    }
  }
}

void llenarArray(int* arr, const int* tam) {
  for(int i = 0; i < *tam; i++) {
    printf("Ingresa el elemento %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
}

void mostrarArray(const int* arr, const int* tam) {
  for (int i = 0; i < *tam; i++) {
    printf("Dato [%d]: %d\n", (i + 1), arr[i]);
  }
}

int buscar(const int* arr, const int* clave, const int* tam) {
  int conteo = 0;
  for (int i = 0; i < *tam; i++) {
    if (*clave == arr[i]) {
      conteo++;
    }
  }
  return conteo;
}

/**
 * Retorna el tamaño del arrRepeticiones (elementos repetidos) y
 * asigna el numero de elementos repetidos al arrRepeticiones
 */
int obtenerElementosRepetidos(const int *arr, const int* tam, int* arrRepeticiones) {
  int clave;
  int e = 0;
  for(int i = 0; i < *tam; i++) {
    clave = arr[i];

    if (clave != arr[i + 1]) {
      arrRepeticiones[e] = buscar(arr, &clave, tam);
      e++;
    }
  }

  return e;
}
