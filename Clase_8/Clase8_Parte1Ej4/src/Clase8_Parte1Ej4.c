/*
 ============================================================================
4) Dada la siguiente cadena de caracteres:
char nombre[8]={'p','e','p','e','1','2','3','\0'};

Hacer una funcion que reciba el array y su tamaño, y cuente cuantas veces aparece la letra 'e'.
Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado.
Escribir un programa para probar la funcion.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_LETRAS 8

int contarLetraE(char* pArray,int longitud);

int main(void) {
	setbuf(stdout,NULL);
	char nombre[QTY_LETRAS]={'p','e','p','e','1','2','3','\0'};

	if(!contarLetraE(nombre,QTY_LETRAS)){

	}else{
		printf("\nERROR\n");
	}

	return EXIT_SUCCESS;
}

int contarLetraE(char* pArray,int longitud){
	int retorno = -1;
	int i;
	int contadorDeLetra = 0;
	if(pArray != NULL && longitud > 0){
		for(i=0;i<longitud && pArray[i] != '\0';i++){
			if(pArray[i] == 'e'){
				contadorDeLetra++;
			}
		}
		retorno = 0;
		printf("\nCantidad de letra 'e' contadas: %d",contadorDeLetra);
	}
	return retorno;
}
