#include <stdio.h>
#include <stdlib.h>

void darDim(int*, int*);
int** crearMatriz(int, int);
void darDatosMtz(int**, int, int);
void mostrarMtz(int**, int, int);
void liberarMtz(int**, int);

void main() {
  int fil, col, **mtz;

  darDim(&fil, &col);
  mtz = crearMatriz(fil, col);
  darDatosMtz(mtz, fil, col);
  mostrarMtz(mtz, fil, col);
  liberarMtz(mtz, fil);
}

void darDim(int* fil, int* col) {
  printf("Ingresa el numero de filas: ");
  scanf("%d", fil);
  printf("Ingresa el numero de columnas: ");
  scanf("%d", col);
}

int** crearMatriz(int fil, int col) {
  int** mtz, i;

  mtz = (int**) malloc(fil * sizeof(int*));

  if (mtz == NULL) {
    printf("No hay memoria disponible\n");
    exit(0);
  }

  for (i = 0; i < fil; i++) {
    mtz[i] = (int*) malloc(sizeof(int) * col);
  }

  return mtz;
}

void darDatosMtz(int** mtz, int fil, int col) {
  int i, j;

  printf("Ingrese los datos de la matriz\n");

  for(i = 0; i < fil; i++) {
    for(j = 0; j < col; j++){
      printf("Dato[%d][%d]: ", (i + 1), (j + 1));
      scanf("%d", &mtz[i][j]);
    }
  }
}

void mostrarMtz(int** mtz, int fil, int col) {
  int i, j;

  printf("Los datos de la matriz son:\n");
  for (i = 0; i < fil; i++) {
    for (j = 0; j < col; j++) {
      printf("\t%d", mtz[i][j]);
    }
    printf("\n");
  }
}

void liberarMtz(int** mtz, int fil) {
  int i;

  for (i = 0; i < fil; i++) {
    free(mtz[i]);
  }
  free(mtz);

  printf("\nMemoria liberada....\n");
}