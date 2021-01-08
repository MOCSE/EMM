#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTAM 50

void leerCadena(char*);
void intercambiarCadena(char*);
int conteoVocales(const char*);
int conteoMayusculas(const char*);
void esPalindromo(char*);
int getLongitud(const char*);
void invertirCadena(const char*, char*);
void formatCadena(const char*, char*);

void main() {
	char cadena[MAXTAM];
	char cadenaIntercambio[MAXTAM];
	leerCadena(cadena);
	invertirCadena(cadena, cadenaIntercambio);
	printf("%s\n", cadenaIntercambio);
	exit(0);
}

void leerCadena(char* cadena) {
	printf("Ingresa una cadena: ");
	scanf("%[^\n]", cadena);
}

void intercambiarCadena(char* cadena) {
	int posiciones = getLongitud(cadena) - 1;
	int elF, elU;
	for (int i = 0; i <= posiciones; i++) {
		if (posiciones - i > 1) {
			elF = cadena[i];
			elU = cadena[posiciones - i];

			cadena[i] = elU;
			cadena[posiciones - i] = elF;
		}
	}
}

int conteoVocales(const char* cadena) {
	const char vocales[] = "aeiou";
	int conteo = 0;

	for (int i = 0; i < getLongitud(cadena); i++) {
		for (int e = 0; e < getLongitud(vocales); e++) {
			if (tolower(cadena[i]) == vocales[e]) {
				conteo++;
			}
		}
	}
	return conteo;
}

int conteoMayusculas(const char* cadena) {
	int conteoMayusculas = 0;
	for (int i = 0; i < getLongitud(cadena); i++) {
		if (isupper(cadena[i]) == 1) {
			conteoMayusculas++;
		}
	}
	return conteoMayusculas;
}

void esPalindromo(char* cadena) {
	char cadenaInversa[MAXTAM];
	char cadenaF[MAXTAM]; //Cadena formateada sin espacios y minusculas
	formatCadena(cadena, cadenaF);
	invertirCadena(cadenaF, cadenaInversa);

	if (strcmp(cadenaF, cadenaInversa) == 0) {
		printf("ES PALINDROMO\n");
	}
	else {
		printf("NO ES PALINDROMO\n");
	}

}

void invertirCadena(const char* cadena, char* cadenaInversa) {
	int e = 0;
	for(int i = getLongitud(cadena) - 1; i >= 0; i--) {
		cadenaInversa[e] = cadena[i];
		e++;
	}
}

void formatCadena(const char* cadena, char* cadenaF) {
	int e = 0;
	for (int i = 0; i < getLongitud(cadena); i++) {
		if (cadena[i] != ' ') {
			cadenaF[e] = tolower(cadena[i]);
			e++;
		}
	}
	printf("%s\n", cadenaF);
}

int getLongitud(const char* cadena) {
	return (strlen(cadena));
}