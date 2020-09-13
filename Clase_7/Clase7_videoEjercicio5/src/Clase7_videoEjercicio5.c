/*
=====================================================================================================
|Ejercicio 5:																						||
 a) Realizar un programa que le pide 5 numeros int al usuario y los alacene en un array.			||
 Luego ejecutar la funcion borrarImpares() pasandole el array y que debera reemplazar				||
 los numeros que son impares por un cero															||
																									||
 b) Luego imprimir el array para chequear el funcionamiento.										||
																									||
 c) Ordenar el array de menor a mayor y volver a imprimirlo.										||
-----------------------------------------------------------------------------------------------------|
|Ejercicio 6:																						||
 Hacer un programa con el siguiente menu:															||
 1)Ingresar nuevo nombre (no acepta nombres repetidos)												||
 2)Listar todos																						||
 3)Ordenar por nombre																				||
 4)Borrar nombre. Se ingresa el nombre y si se encuentra se elimina de la lista						||
=====================================================================================================|
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define CANTIDAD_NUM 5

int borrarImpares(int arrayDeImpares[],int len);
int ordenarArrayPorInsercion(int array[],int len);

int main(void) {
	setbuf(stdout,NULL);

	int numeros[CANTIDAD_NUM];
	int i;

	for(i=0;i<CANTIDAD_NUM;i++){
		if(!utn_getNumero(&numeros[i],"\nIngrese numero: ","\nNumero invalido!",-5,100,3)){

		}else{
			printf("\nSe acabaron los intentos para ingresar bien le numero.\n");
		}
	}
	borrarImpares(numeros,CANTIDAD_NUM);
	imprimirArray(numeros,CANTIDAD_NUM);
	printf("\nOrden de mayor a menor\n---\n");
	ordenarArrayPorInsercion(numeros,CANTIDAD_NUM);
	imprimirArray(numeros,CANTIDAD_NUM);
	return EXIT_SUCCESS;
}

int borrarImpares(int arrayDeImpares[],int len){
	int retorno = -1;
	int i;
	if(arrayDeImpares != NULL){
		for(i=0;i<len;i++){
			if(arrayDeImpares[i] % 2 != 0){
				arrayDeImpares[i] = 0;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int ordenarArrayPorInsercion(int array[],int len){
	int retorno = -1;
	int i;
	int j;
	int auxiliar;
	if(array != NULL && len > 0){
		for(i=1;i<len;i++){
			auxiliar = array[i];
			j = i - 1;
			while(j >= 0 && auxiliar < array[j]){
				array[j+1] = array[j];
				j--;
			}
			array[j+1] = auxiliar;
		}
		retorno = 0;
	}
	return retorno;
}
