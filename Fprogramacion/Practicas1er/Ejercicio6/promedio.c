/**
 * No se si se podían usar ciclos, lo considero mucho mas 
 * eficiente, pero pues así lo resolví.
 */
#include <stdio.h>

float leerNumero();
float calcularPromedio(float, float, float, float, float);
void mostrarPromedio(float);

void main() {
    float num1 = 0;
    float num2 = 0;
    float num3 = 0;
    float num4 = 0;
    float num5 = 0;
    float promedio = 0;

    num1 = leerNumero();
    num2 = leerNumero();
    num3 = leerNumero();
    num4 = leerNumero();
    num5 = leerNumero();

    promedio = calcularPromedio(num1, num2, num3, num4, num5);

    mostrarPromedio(promedio);
}

float leerNumero() {
    float num = 0;
    printf("Ingresa un numero: ");
    scanf("%f", &num);
    return num;
}

float calcularPromedio(float num1, float num2, float num3, float num4, float num5) {
    float sumatoriaNumeros = 0;
    float promedio = 0;

    sumatoriaNumeros += num1;
    sumatoriaNumeros += num2;
    sumatoriaNumeros += num3;
    sumatoriaNumeros += num4;
    sumatoriaNumeros += num5;

    promedio = sumatoriaNumeros / 5;
    return promedio;
}

void mostrarPromedio(float promedio) {
    printf("El promedio de los 5 numeros es: %f\n", promedio);
}