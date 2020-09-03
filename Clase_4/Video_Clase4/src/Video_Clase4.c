/*
 ============================================================================
 Name        : Video_Clase4.c
 Author      : Flores E. Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int dividir(float* pResultado,int num1,int num2);

int main(void) {
	setbuf(stdout,NULL);
	float resultado;
	int numero1;
	int numero2;
	int respuesta;

	printf("\nIngrese numero 1: ");
	scanf("%d",&numero1);
	printf("\nIngrese numero 2: ");
	scanf("%d",&numero2);
	respuesta = dividir(&resultado,numero1,numero2);
	if(!respuesta){
		printf("\nPudo dividir!\n La division es igual a: %.2f", resultado);
	}else{
		printf("\nNo es posible dividir por 0!");
	}
	return EXIT_SUCCESS;
}

int dividir(float* pResultado,int num1,int num2)
{
	float resultado;
	int retorno = -1;
	if(pResultado != NULL && num2 != 0){
		resultado = (float)num1/num2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}
