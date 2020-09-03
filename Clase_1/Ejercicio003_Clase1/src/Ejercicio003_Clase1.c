/*
 ============================================================================
 Name        : Ejercicio003_Clase1.c
 Author      : Flores Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
		int numero1;
		int numero2;
		int resultadoScan;
		int resta;

		printf("\nIngrese un valor para numero1: ");
		resultadoScan = scanf("%d",&numero1);
		while(resultadoScan == 0)
		{
			printf("\nValor invalido! Ingrese nuevamente: ");
			fflush(stdin);
			resultadoScan = scanf("%d",&numero1);
		}
		printf("\nIngrese un valor para numero2: ");
		resultadoScan = scanf("%d",&numero2);
		while(resultadoScan == 0)
		{
			printf("\nValor invalido! Ingrese nuevamente: ");
			fflush(stdin);
			resultadoScan = scanf("%d",&numero2);
		}
		resta = numero1 - numero2;
		if(resta < 0){
			printf("\nResultado Negativo: %d\n",resta);
		}else{
			printf("\nResultado Positivo: %d\n",resta);
		}
	return EXIT_SUCCESS;
}
