/*
 ============================================================================
  1)Se tiene el siguiente array de variables del tipo int
	int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};
	Hacer una funcion que reciba el array y su tamaño, y lo imprima.
 	Escribir un programa para probar la funcion.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_ELEMENTOS 12

int imprimirArray(int* pArray,int longitud);

int main(void) {
	setbuf(stdout,NULL);
	int numeros[]={3,7,4,5,2,3,7,1,7,3,2,7};

	imprimirArray(numeros,QTY_ELEMENTOS);

	return EXIT_SUCCESS;
}

int imprimirArray(int* pArray,int longitud){
	int retorno = -1;
	int i;
	if(pArray != NULL && longitud > 0){
		for(i=0;i<longitud;i++){
			printf("\nIndice: %d - Valor: %d \n",i,pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}
