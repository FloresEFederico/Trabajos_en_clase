/*
 ========================================================================================
3) Modificar la funcion del punto 2 para que NO imprima el valor
	contado, sino que lo devuelva por referencia
 	 (recibiendo la direccion de memoria de una variable donde escribirá el valor contado).
 	 Escribir un programa para probar la funcion.
 ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_ELEMENTOS 12

int contarSietesEnArray(int* pArray,int longitud,int* pContador);

int main(void) {
	setbuf(stdout,NULL);
	int numeros[]={3,7,4,5,2,3,7,1,7,3,2,7};
	int contadorNumero;

	if(!contarSietesEnArray(numeros,QTY_ELEMENTOS,&contadorNumero)){
		printf("\nCantidad de N°7 contados: %d",contadorNumero);
	}else{
		printf("\nERROR\n");
	}

	return EXIT_SUCCESS;
}

int contarSietesEnArray(int* pArray,int longitud,int* pContador){
	int retorno = -1;
	int i;
	int contadorDeSietes = 0;
	if(pArray != NULL && longitud > 0 && pContador != NULL){
		for(i=0;i<longitud;i++){
			if(pArray[i] == 7){
				contadorDeSietes++;
			}
		}
		*pContador = contadorDeSietes;
		retorno = 0;
	}
	return retorno;
}
