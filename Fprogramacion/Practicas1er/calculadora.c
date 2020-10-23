#include <stdio.h>

float leerNumero();
float sumar(float, float);
float restar(float, float);
float multiplicar(float, float);
float dividir(float, float);
void mostrarResultado(float, float, float, float);

void main() {
    float num1 = 0;
    float num2 = 0;

    num1 = leerNumero();
    num2 = leerNumero();

    mostrarResultado(sumar(num1, num2), restar(num1, num2),
    multiplicar(num1, num2), dividir(num1, num2));
}

float leerNumero() {
    float num = 0;
    printf("Ingresa un numero: ");
    scanf("%f", &num);
    return num;
}

float sumar(float num1, float num2) {
    return num1 + num2;
}

float restar(float num1, float num2) {
    return num1 - num2;
}

float multiplicar(float num1, float num2) {
    return num1 * num2;
}

float dividir(float num1, float num2) {
    return num1 / num2;
}

void mostrarResultado(float resSuma, float resResta, float resMulti, float resDiv) {
    printf("La suma es: %f\n", resSuma);
    printf("La suma es: %f\n", resResta);
    printf("La multiplicacion es: %f\n", resMulti);
    printf("La suma división: %f\n", resDiv);
}