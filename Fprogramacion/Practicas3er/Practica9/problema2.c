#include <stdio.h>
#include <stdlib.h>

#define FIL_COL_TAM 10

void leerDim(int*, int*);
void leerMatriz(int [FIL_COL_TAM][FIL_COL_TAM], int, int);
void sumatoriaFilCol(int [FIL_COL_TAM][FIL_COL_TAM], int*, int*, int, int);
void mostrarArreglo(int*, int*);
void mostrarMatriz(int [FIL_COL_TAM][FIL_COL_TAM], int, int);

void main() {
  int matriz[FIL_COL_TAM][FIL_COL_TAM];
  int vectorFilas[FIL_COL_TAM];
  int vectorCol[FIL_COL_TAM];

  int dimFil, dimCol;

  leerDim(&dimFil, &dimCol);
  leerMatriz(matriz, dimFil, dimCol);
  sumatoriaFilCol(matriz, vectorFilas, vectorCol, dimFil, dimCol);
  printf("\n\nMatriz:\n");
  mostrarMatriz(matriz, dimFil, dimCol);
  printf("\n\nSumatoria de filas:\n");
  mostrarArreglo(vectorFilas, &dimFil);
  printf("\n\nSumatoria de columnas:\n");
  mostrarArreglo(vectorCol, &dimCol);
}

void leerDim(int* dimFil, int* dimCol) {
  printf("Ingresa las dimensiones del arreglo: \n");
  printf("Dimensiones > ");
  scanf("%d", dimFil);
  *dimCol = *dimFil;
}

void leerMatriz(int matriz[FIL_COL_TAM][FIL_COL_TAM], int dimFil, int dimCol) {
  int i, e;
  printf("\n\n");
  for(i = 0; i < dimFil; i++) {
    for (e = 0; e < dimCol; e++) {
      printf("Ingrese dato [%d][%d]: ", i, e);
      scanf("%d", &matriz[i][e]);
    }
  }
}

void sumatoriaFilCol(int matriz[FIL_COL_TAM][FIL_COL_TAM], int* vectorFilas, int* vectorCol,
  int dimFil, int dimCol) {
  int i = 0, e = 0;

  for (e = 0; e < dimCol; e++) {
    vectorFilas[e] = 0; 
    for(i = 0; i < dimFil; i++) {
      vectorFilas[e] += matriz[i][e];
    }
  }

  for (int i = 0; i < dimFil; i++) {
    vectorCol[i] = 0;
    for (int e = 0; e < dimCol; e++) {
      vectorCol[i] += matriz[i][e];
    }
  }
}

void mostrarArreglo(int* arr, int* dim) {
  int i;
  for (i = 0; i < *dim; i++) {
    printf("Dato [%d]: %d\n", i, arr[i]);
  }
}

void mostrarMatriz(int matriz[FIL_COL_TAM][FIL_COL_TAM], int dimFil, int dimCol) {
  int i, e;

  for (i = 0; i < dimFil; i++) {
    for(e = 0; e < dimCol; e++) {
      printf("Dato[%d][%d]: %d\n", i, e, matriz[i][e]);
    }
  }
}
