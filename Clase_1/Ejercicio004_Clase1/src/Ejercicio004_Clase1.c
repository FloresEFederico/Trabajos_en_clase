/*
 ============================================================================
 Name        : Ejercicio004_Clase1.c
 Author      : Flores Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 10
int main(void) {
	setbuf(stdout,NULL);
	int numeros;
	int resultadoScanf;
	int i;
	int cantidadDeNegativos = 0;
	int cantidadDePositivos = 0;
	int negativos[TAM];
	int positivos[TAM];

	for(i=0;i<TAM;i++){
		printf("\nIngrese el %d° numero: ",i+1);
		resultadoScanf = scanf("%d",&numeros);
		while(resultadoScanf == 0){
			printf("\nNumero ingresado invalido! Vuelva a intentar: ");
			fflush(stdin);
			resultadoScanf = scanf("%d",&numeros);
		}
		if(numeros < 0){
			negativos[cantidadDeNegativos] = numeros;
			cantidadDeNegativos++;
		}else{
			positivos[cantidadDePositivos] = numeros;
			cantidadDePositivos++;
		}
	}
	printf("\nLa cantidad de Negativos ingresados fue de: %d\n",cantidadDeNegativos);
	printf("\nY los numeros negativos son: ");
	for(i=0;i<cantidadDeNegativos;i++){
		printf("%d ",negativos[i]);
	}
	printf("\n\nLa cantidad de Positivos ingresados fue de: %d\n",cantidadDePositivos);
	printf("\nY los numeros positivos son: ");
		for(i=0;i<cantidadDePositivos;i++){
			printf("%d ",positivos[i]);
		}
	return EXIT_SUCCESS;
}
