#include <stdio.h>
#include <stdlib.h>

void darNumElem(int*);
void darNumBuscar(int*);
void insertarDatos(int*, const int*);
void mostrar(int*, const int*);
void mostrarPosicion(const int*);
void copiar(const int*, int* n, const int*);
int buscar(const int*, const int*, const int*);
int busquedaBinaria(const int*, const int*, const int*);
void ordenaBurbuja(int*, const int*);

#define MAXTAM 50

void main() {
  int arr[MAXTAM];
  int copyArr[MAXTAM];
  int tam, clave, pos;

  //Llenado y copia del arreglo.
  darNumElem(&tam);
  insertarDatos(arr, &tam);
  copiar(arr, copyArr, &tam);

  //Ordenamiento de arreglo:
  ordenaBurbuja(arr, &tam);
  printf("\nArreglo sin ordenar: \n");
  mostrar(copyArr, &tam);
  printf("Arreglo ordenado: \n");
  mostrar(arr, &tam);

  printf("\n");
  
  //Busqueda de elementos:
  darNumBuscar(&clave);

  printf("\nBusqueda secuencial: \n");
  pos = buscar(arr, &clave, &tam);
  mostrarPosicion(&pos);

  printf("Busqueda binaria: \n");
  pos = busquedaBinaria(arr, &clave, &tam);
  mostrarPosicion(&pos);

  exit(0);
}

void darNumElem(int* tam) {
  int status = 0;
  while(status == 0) {
    printf("\nIngresa la cantidad de datos a leer (x < 50): ");
    scanf("%d", tam);

    if (*tam < 50) { status = 1; }
    else {
      printf("El numero debe ser menor a 50. Intente de nuevo.\n");
      status = 0;
    }
  }
}

void darNumBuscar(int* clave) {
  printf("Ingresa el elemento a buscar: ");
  scanf("%d", clave);
}

void insertarDatos(int* arr, const int* tam) {
  for(int i = 0; i < *tam; i++) {
    printf("Ingresa el elemento %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
}

void mostrar(int* arr, const int* n) {
  for(int i = 0; i < *n; i++) {
    printf("Dato [%d]: %d\n", (i + 1), arr[i]);
  }
}

void copiar(const int* arr, int* copyArr, const int* n) {
  for(int i = 0; i < *n; i++) {
    copyArr[i] = arr[i];
  }
}

int buscar(const int* arr, const int* clave, const int* n) {
  for (int i = 0; i < *n; i++) {
    if (*clave == arr[i]) {
      return i;
    }
  }
  return -1;
}

int busquedaBinaria(const int* arr, const int* clave, const int* n) {
  int izq = 0, der, central;
  der = *n - 1;

  while(izq <= der) {
    central = (izq + der) / 2;

    if (*clave == arr[central]) {
      return central;
    }
    else if (*clave > arr[central]) {
      izq = central + 1;
    }
    else {
      der = central - 1;
    }
  }

  return -1;
}

void ordenaBurbuja(int* arr, const int* n) {
  int temp;
  
  for (int j = 0; j < *n; j++) {
    for (int i = 0; i < *n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
}

void mostrarPosicion(const int* pos) {
  if (*pos != -1) {
    printf("Elemento encontrado en la posicion: %d\n", *pos);
  }
  else {
    printf("Elemento no encontrado en el arreglo\n");
  }
}
