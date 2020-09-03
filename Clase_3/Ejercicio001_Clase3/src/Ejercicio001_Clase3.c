/*
 * Crear una función que permita ingresar un numero al usuario y lo retorne.
 * Crear una función que reciba el radio de un círculo y retorne su área.
 * Utilizar las funciones de los puntos 1 y 2 para hacer un programa que
 * calcule el área de un círculo cuyo radio es ingresado por el usuario.
 * Documentar las funciones al estilo Doxygen.
 */
#include <stdio.h>
#include <stdlib.h>

float asignarValor();
float calcularAreaDelCirculo(float radio);

int main(void) {
	setbuf(stdout,NULL);

	float radioDelCirculo;
	float areaDelCirculo;

	radioDelCirculo = asignarValor();
	areaDelCirculo = calcularAreaDelCirculo(radioDelCirculo);
	printf("\nEl radio es de: %.2f\n\nY su area es de: %.2f\n",radioDelCirculo,areaDelCirculo);

	return EXIT_SUCCESS;
}

float asignarValor(){

	float operador;
	int resultadoScan;

	printf("\nIngrese el radio: ");
	resultadoScan = scanf("%f",&operador);
	while(!resultadoScan){
		printf("\nArea invalida, ingreselo nuevamente: ");
		fflush(stdin);
		resultadoScan = scanf("%f",&operador);
	}

	return operador;
}

float calcularAreaDelCirculo(float radio){

	float area;
	float pi = 3.14159265359;

	area = pi * radio * radio;

	return area;
}
