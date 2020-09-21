/*
 ============================================================================
2) Hacer una funcion que reciba el array del punto 1 y
 su tamaño, y cuente cuantas veces aparece el numero 7.
  Al terminar de contar, la funcion deberá imprimir por
   pantalla el valor contado. Escribir un programa para
   probar la funcion.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_ELEMENTOS 12

int contarSietesEnArray(int* pArray,int longitud);

int main(void) {
	setbuf(stdout,NULL);
	int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};

	contarSietesEnArray(numeros,QTY_ELEMENTOS);

	return EXIT_SUCCESS;
}

int contarSietesEnArray(int* pArray,int longitud){
	int retorno = -1;
	int i;
	int contadorDeSiete = 0;
	if(pArray != NULL && longitud > 0){
		for(i=0;i<longitud;i++){
			if(pArray[i] == 7){
				contadorDeSiete++;
			}
		}
		printf("\nEl numero siete aparece %d veces\n",contadorDeSiete);
		retorno = 0;
	}
	return retorno;
}
