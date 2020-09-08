/*
 ====================================================================================================================================================
 EJERCICIO: Hacer una funcion que calcule el promedio de los valores del array que recibe y me devuelva el promedio:
 opcion 1: promedio = calcularPromedio(edades,EDADSIZE)
 opcion 2: calcularPromedio(edades,EDADSIZE,&promedio)
 ====================================================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define EDADSIZE 5

float calcularPromedio(int array[],int size);
void imprimirArray(int array[],int size);

int main(void) {
	setbuf(stdout,NULL);
	int edades[EDADSIZE];
	int i;
	float promedio;

	for(i=0;i<EDADSIZE;i++){
		if(utn_getNumero(&edades[i],"\nIngrese edad(rango: 1 - 100): ","\nEdad invalida! Respestar rango!\n",1,100,5)){
			printf("\nHubo un error al cargar esa edad\n");
			break;
		}
	}
	if(i == 5){
		promedio = calcularPromedio(edades,EDADSIZE);
		printf("\nEDADES\n");
		imprimirArray(edades,EDADSIZE);
		printf("\n---------------------------\n");
		printf("promedio de edades: %.2f",promedio);
	}else{
		printf("\nNo se pudo ingresar el total de edades\n");
	}

	return EXIT_SUCCESS;
}
/**
 * CalcularPromedio = recibe array, calcula el promedio  y devuelve de retorno el promedio calculado
 * array[]: array de int
 * size: tamaño del array
 * retorna: el promedio
 */
float calcularPromedio(int array[],int size){
	int acumulador = 0;
	int i;
	float promedioCalculado;
	for(i=0;i<size;i++){
		acumulador+=array[i];
	}
	promedioCalculado = (float)acumulador/size;

	return promedioCalculado;
}
/**
 * imprimirArray = imprime el array
 * array[]: array de int
 * size: tamaño del array
 * retorna: VOID
 */
void imprimirArray(int array[],int size){
	int i;
	if(array != NULL && size > 0){
		for(i=0;i<size;i++){
			printf("%d \n",array[i]);
		}
	}
}
