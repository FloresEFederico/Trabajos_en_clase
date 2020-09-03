/*
 ============================================================================
 Name        : Clase.c
 Author      : Flores Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
/*EJERCICIO
 * pedir cinco numeros y mostrar promedio
 */
int main(void) {

	setbuf(stdout,NULL);

/* ------------------------CLASE 1---------------------------------
 *  int numero1;
	int numero2;
	int resultado;
	int respuestaScanf;


	printf("Numero1: ");
	fflush(stdin);
	respuestaScanf = scanf("%d",&numero1);
	while(respuestaScanf == 0)
	{
		printf("\nERROR - Numero1: ");
		fflush(stdin);
		respuestaScanf = scanf("%d",&numero1);
	}
	printf("Numero2: ");
		fflush(stdin);
		respuestaScanf = scanf("%d",&numero2);
		printf("\nrespuesta scanf es %d\n",respuestaScanf);
	while(respuestaScanf == 0)
		{
			printf("\n ERROR - Numero2: ");
			fflush(stdin);
			respuestaScanf = scanf("%d",&numero2);
		}

		resultado = numero1 + numero2;
		printf("\nEl resultado es %d\n\n",resultado);
*/
//----------------------------EJERCICIO--------------------------------------
	int numero;
	int acumulador = 0;
	float promedio;
	int respuestaScanf;
	int i;

	for(i = 0;i < 5;i++){
		printf("\nIngrese el  numero: ");
		respuestaScanf = scanf("%d",&numero);
		while(respuestaScanf == 0){
			printf("\nERROR! reingrese el numero: ");
			fflush(stdin);
			respuestaScanf = scanf("%d",&numero);
		}
		acumulador = acumulador + numero;
	}
	promedio =(float)acumulador / i;
	printf("\nEl promedio es de: %.2f\n",promedio);
	return EXIT_SUCCESS;
}
