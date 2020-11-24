#include <stdio.h>
#include <stdlib.h>

void leerDatos(float*, char*);
void calcularSueldo(float*, float*, char*);
void mostrarSueldo(float);

void main() {
  float horas, sueldoB;
  char catg;

  leerDatos(&horas, &catg);
  calcularSueldo(&horas, &sueldoB, &catg);

  mostrarSueldo(sueldoB);
}

void leerDatos(float* horas, char* catg) {
  printf("Ingresa la categoria del trabajador: ");
  scanf("%c", catg);
  printf("Ingresa las horas trabajadas esta semana: ");
  scanf("%f", horas);
}

void calcularSueldo(float* horas, float* sueldoB, char* catg) {
  switch (*catg) {
  case 'a':
  case 'A':
    *sueldoB = 7 * (*horas);
    break;
  case 'b':
  case 'B':
    *sueldoB = 5 * (*horas);
    break;
  case 'c':
  case 'C':
    *sueldoB = 4 * (*horas);
    break;
  case 'd':
  case 'D':
    *sueldoB = 3.5 * (*horas);
    break;
  default:
    printf("OPCION NO VALIDA.\n");
    exit(0);
    break;
  }
}

void mostrarSueldo(float sueldoB) {
  printf("El sueldo calculado es: %.2f\n", sueldoB);
}
