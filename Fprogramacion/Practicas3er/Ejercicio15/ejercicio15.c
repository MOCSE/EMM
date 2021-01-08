#include <stdio.h>
#include <stdlib.h>

#define FIL 10
#define COL 10

void mostrarMenu(int*);
void pedirDimensiones(int*, int*);
void solicitarMatriz(int [FIL][COL], int, int);
void sumarDiagonalSec(int [FIL][COL], int, int);
void restarDiagonalInf(int [FIL][COL], int, int);
void mostrarMatriz(int [FIL][COL], int, int);
void salir();

void main() {
  int op = 0,
  filUsuario, 
  colUsuario;

  int mtz[FIL][COL];

  do {
    mostrarMenu(&op);
    switch (op) {
      case 1: pedirDimensiones(&filUsuario, &colUsuario); break;
      case 2: solicitarMatriz(mtz, filUsuario, colUsuario); break;
      case 3: sumarDiagonalSec(mtz, filUsuario, colUsuario); break;
      case 4: restarDiagonalInf(mtz, filUsuario, colUsuario); break;
      case 5: mostrarMatriz(mtz, filUsuario, colUsuario); break;
      case 6: salir();
      default: printf("OPCION NO VALIDA"); break;
    }
  } while (op >= 1 && op <= 6);
}

void mostrarMenu(int* op) {
  printf("\n\nMENU DE OPCIONES:\n");
  printf("1.- Pedir dimensiones de la matriz.\n");
  printf("2.- Solicitar datos de la matriz.\n");
  printf("3.- Sumar los elementos de la diagonal secundaria.\n");
  printf("4.- Restar los elementos de la diagonal inferior.\n");
  printf("5.- Mostrar la matriz.\n");
  printf("6.- Salir\n");

  printf("Seleccione una opción con el numero correspondiente: ");
  scanf("%d", op);
}

void pedirDimensiones(int* filUsuario, int* colUsuario) {
  printf("\n\nEL NUMERO DE FILAS DEBE SER IGUAL DEL DE COLUMNAS.\n");
  printf("EL PROGRAMA NO AVANZARA HASTA QUE ESTA CONDICION SE CUMPLA\n");

  do {
    printf("Ingresa el numero de filas: ");
    scanf("%d", filUsuario);
    printf("Ingresa el numero de columnas: ");
    scanf("%d", colUsuario);
  } while (*filUsuario != *colUsuario);
}

void solicitarMatriz(int mtz[FIL][COL], int filUsuario, int colUsuario) {
  int i, e;
  printf("\n\n");
  for(i = 0; i < filUsuario; i++) {
    for (e = 0; e < colUsuario; e++) {
      printf("Ingrese dato [%d][%d]: ", i, e);
      scanf("%d", &mtz[i][e]);
    }
  }
}

void sumarDiagonalSec(int mtz[FIL][COL], int filUsuario, int colUsuario) {
  int i, e;
  int sum = 0;

  printf("\n\nElementos de la diagonal secundaria: ");

  for(i = 0; i < filUsuario; i++) {
    for (e = 0; e < colUsuario; e++) {
      if (i + e == filUsuario - 1) {
        sum += mtz[i][e];
        printf("%d, ", mtz[i][e]);
      }
    }
  }

  printf("\nPor tanto, la suma de la diagonal secundaria: %d\n", sum);
}

void restarDiagonalInf(int mtz[FIL][COL], int filUsuario, int colUsuario) {
  int i, e;
  int res = mtz[1][0];

  printf("\n\nElementos de la diagonal inferior: ");

  for (i = 0; i < filUsuario; i++) {
    for(e = 0; e < colUsuario; e++) {
      if (i > e) {
        printf("%d, ", mtz[i][e]);

        if (i != 1 && e != 0) {
          res -= mtz[i][e];
        }
      }
    }
  }

  printf("\nPor tanto la resta de la diagonal inferior es: %d\n", res);
}

void mostrarMatriz(int mtz[FIL][COL], int filaUsuario, int colUsuario) {
  int i, e;
  printf("\n\n");
  for(i = 0; i < filaUsuario; i++) {
    for (e = 0; e < colUsuario; e++) {
      printf("Dato [%d][%d]: %d\n", i, e, mtz[i][e]);
    }
  }
}

void salir() { exit(0); }