#include <stdio.h>
#include <stdlib.h>

void determinarCompra(float);
void obtenerDinero(float*);
void mostrarPaqueteAComprar(char);

void main() {
  float presupuesto;
  obtenerDinero(&presupuesto);
  determinarCompra(presupuesto);
}

void obtenerDinero(float* presupuesto) {
  printf("Ingrese el dinero que tiene de presupuesto > ");
  scanf("%f", presupuesto);
}

void determinarCompra(float presupuesto) {
  if (presupuesto > 0) {
    if (presupuesto > 50000) {
      mostrarPaqueteAComprar('A');
    }
    else {
      if (presupuesto >= 20000) {
        mostrarPaqueteAComprar('B');
      }
      else {
        if (presupuesto >= 10000) {
          mostrarPaqueteAComprar('C');
        }
        else {
          mostrarPaqueteAComprar('D');
        }
      }
    }
  }
  else {
    printf("Presupuesto no valido\n");
    exit(0);
  }
}

void mostrarPaqueteAComprar(char paquete) {
  printf("Usted puede adquirir el paquete %c\n", paquete);
}