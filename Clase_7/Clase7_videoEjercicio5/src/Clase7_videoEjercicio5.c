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
#include "logica.h"
#define CANTIDAD_NUM 5



int main(void) {
	setbuf(stdout,NULL);

	int numeros[CANTIDAD_NUM];

	if(!solicitarNumeros(numeros,CANTIDAD_NUM,-10,100)){
		borrarImpares(numeros,CANTIDAD_NUM);
		imprimirArray(numeros,CANTIDAD_NUM);
		printf("\nOrden de mayor a menor\n---\n");
		ordenarArrayPorInsercion(numeros,CANTIDAD_NUM);
		imprimirArray(numeros,CANTIDAD_NUM);
	}
	return EXIT_SUCCESS;
}

