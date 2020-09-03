/*
 ============================================================================
 Name        : Calcular_Factorial.c
 Author      : Flores Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int numero);

int main(void) {
	setbuf(stdout,NULL);
	int numero = 4;
	int resultado;
	resultado = factorial(numero);
	printf("%d",resultado);
	return EXIT_SUCCESS;
}

int factorial(int numero){
	int resp;
	if(numero == 1){
		return 1;
	}
	resp = numero*factorial(numero-1);
	return resp;
}
