#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void leerCadena(char*);
int contarVocales(char*);
void eliminarMayusculas(char*, char*);
void esPalindromo(char*);
void formatearCadena(char*, char*);
void invertirCadena(char*, char*);
void imprimirCadena(const char*);

#define MAXTAM 80

void main() {
  char cadena[MAXTAM], cadenaMay[MAXTAM],
  cadenaMin[MAXTAM];

  leerCadena(cadena);
  printf("\nCADENA ORIGINAL: ");
  imprimirCadena(cadena);

  esPalindromo(cadena);

  printf("\nNumero de vocales: %d\n", contarVocales(cadena));

  eliminarMayusculas(cadena, cadenaMay);

  printf("\nMayusculas:\n");
  imprimirCadena(cadenaMay);

  printf("Minusculas (CADENA ORIGINAL SIN MAYUSCULAS):\n");
  imprimirCadena(cadena);

  exit(0);
}

void leerCadena(char* cadena) {
  printf("Ingrese una cadena de texto: ");
  scanf("%[^\n]", cadena);
  getchar();
}

void eliminarMayusculas(char* cadena, char* cadenaMay) {
  int i = 0, j = 0, k = 0;
  while (cadena[i] != '\0') {
    if (isupper(cadena[i])) {
      cadenaMay[j] = cadena[i];
      cadena[i] = ' ';
      j++;
    }
    i++;
  }
  cadenaMay[j] = '\0';
}

int contarVocales(char* cadena) {
  int i = 0;
  int cantidadVocales = 0;
  while (cadena[i] != '\0') {
    switch (tolower(cadena[i])) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        cantidadVocales++;
        break;
      default: break;
    }
    i++;
  }
  return cantidadVocales;
}

void esPalindromo(char* cadena) {
  char cadenaFormateada[MAXTAM], cadenaInversa[MAXTAM];
  formatearCadena(cadena, cadenaFormateada);
  invertirCadena(cadenaFormateada, cadenaInversa);

  //printf("%s\n", cadenaFormateada);
  //printf("%s\n", cadenaInversa);

  if (strcmp(cadenaFormateada, cadenaInversa) == 0) {
    printf("ES PALINDROMO\n");
  }
  else {
    printf("NO ES PALINDROMO\n");
  }
}

void formatearCadena(char* cadena, char* cadenaFormateada) {
  int i = 0;
  int e = 0;
  while (cadena[i] != '\0') {
    if (cadena[i] != ' ') {
      cadenaFormateada[e] = tolower(cadena[i]);
      e++;
    }
    i++;
  }
  cadenaFormateada[e] = '\0';
}

void invertirCadena(char* cadenaFormateada, char* cadenaInversa) {
  int i = strlen(cadenaFormateada) - 1;
  int e = 0;

  while (i >= 0) {
    cadenaInversa[e] = cadenaFormateada[i];
    i--;
    e++;
  }

  cadenaInversa[e] = '\0';
}

void imprimirCadena(const char* cadena) {
  printf("Cadena: %s\n", cadena);
}