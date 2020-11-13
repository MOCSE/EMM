#include <stdio.h>
#include <stdlib.h>

void leerOpcion(int *);
void ejecutarOpcionSel(const int *);
void conFor(int *);
void conWhile(int *);
void conDoWhile(int *);
void mostrarSumatoria(const int *);

void main() {
	int opc;
	
	leerOpcion(&opc);
	ejecutarOpcionSel(&opc);
}

void leerOpcion(int *opc) {
	printf("\nELIGE UNA OPCION:\n");
	printf("\n[1] Ciclo for.\n[2] Ciclo while.\n[3] Ciclo do-while.\n[4] Salir\n");
	printf("Selecciona una opcion > ");
	scanf("%d", opc);
} 

void ejecutarOpcionSel(const int *opc) {
	int sum = 0;
	switch(*opc) {
		case 1: {
			conFor(&sum);
			break;
		}
		case 2: {
			conWhile(&sum);
			break;
		}
		case 3: {
			conDoWhile(&sum);
			break;
		}
		case 4: {
			exit(0);
			break;
		}
		default: {
			printf("\nOPCION NO VALIDA\n");
			exit(0);
			break;
		}
	}
	mostrarSumatoria(&sum);
}

void conFor(int *sum) {
	for (int i = 10; i <= 100; i++) {
		if (i % 5 == 0) {
			*sum += i;
		}
	}
}

void conWhile(int *sum) {
	int i = 0;
	while (i <= 100) {
		if (i % 5 == 0) {
			*sum += i;
		}
		i++;
	}
}

void conDoWhile(int *sum) {
	int i = 0;
	do {
		if (i % 5 == 0) {
			*sum += i;
		}
		i++;
	} while (i <= 100);
}

void mostrarSumatoria(const int *sum) {
	printf("La sumatoria es: %d \n", *sum);
}
