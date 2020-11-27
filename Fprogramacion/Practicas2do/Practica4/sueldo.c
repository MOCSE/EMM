#include <stdio.h>
#include <stdlib.h>

void leerHorasTrabajadas(float*);
void leerCategoriaTrabajador(char*);
void casoCalcSueldo(float*, float*, char*);
float getSueldo(float*, float);
void mostrarSueldo(float*);


void main() {
	float horasTrabajadas, sueldo;
	char categoriaTrabajador;
	
	leerCategoriaTrabajador(&categoriaTrabajador);
	leerHorasTrabajadas(&horasTrabajadas);
	casoCalcSueldo(&horasTrabajadas, &sueldo, &categoriaTrabajador);
	mostrarSueldo(&sueldo);
	
	exit(0);
}

void leerHorasTrabajadas(float* horasTrabajadas) {
	printf("Ingresa el numero de horas trabajadas a la semana: ");
	scanf("%f", horasTrabajadas);
}

void leerCategoriaTrabajador(char* categoriaTrabajador) {
	printf("Ingresa la categoria del trabajador: ");
	scanf("%c", categoriaTrabajador);
}

void casoCalcSueldo(float* horasTrabajadas, float* sueldo, char* categoriaTrabajador) {
	*sueldo = 0;
	switch(*categoriaTrabajador) {
		case 'a':
		case 'A': {
			*sueldo = getSueldo(horasTrabajadas, 7.0);
			break;
		}
		case 'b':
		case 'B': {
			*sueldo = getSueldo(horasTrabajadas, 5.0);
			break;
		}
		case 'c':
		case 'C': {
			*sueldo = getSueldo(horasTrabajadas, 4.0);
			break;
		}
		case 'd':
		case 'D': {
			*sueldo = getSueldo(horasTrabajadas, 3.5);
			break;
		}
		default: {
			printf("OPCION NO VALIDA\n");
			exit(0);
			break;
		}
	}
}

float getSueldo(float* horasTrabajadas, float pagoPorHora) {
	return *horasTrabajadas * pagoPorHora;
}

void mostrarSueldo(float* sueldo) {
	printf("El sueldo es: %.2f \n", *sueldo);
}
