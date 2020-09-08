/*
 ============================================================================
 	 	 	 	 	 	 	 	 |BURBUJEO|
Sirve para ordenar variables siempre cumpliendo con la condicion que se le
otorga. Por ejemplo: ordenar un numero de mayor a menor o de menor a mayor
y lo mismo con letras y etc.

swap: significa cambiar dos cosas de lugar.

Harcodeo de datos: significa darle valores ya de entrada a un array para
de esa forma poder hacer el codigo mas rapido. Con el hardcodeo no tengo
que ir compilando y repitiendo ese proceso de pedido de datos una y otra vez
para probar el codigo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 9

//2° hacemos la funcion que imprima el array
int printArrayInt(int array[],int limite);

//3° hacemos la funcion que ordena
int ordenar(int array[],int limite);

int main(void) {
	setbuf(stdout,NULL);
// Fabricaremos dos funciones: una de mostrar y una de ordenar

//1°- definimos un array y la harcodeamos!
	int edades[QTY_EMPLEADOS] = {54,26,93,17,77,31,44,55,27};

	//2°aca mostramos por print
	printArrayInt(edades,QTY_EMPLEADOS);
	//3°llamamos a la funcion que ordena
	int respuesta;
	printf("\n\nPRIMER ORDENAMIENTO\n\n");
	respuesta = ordenar(edades,QTY_EMPLEADOS);
	if(respuesta > 0){
		printf("\n iteraciones: %d\n\n",respuesta);
	}
	printArrayInt(edades,QTY_EMPLEADOS);

	printf("\n\nSEGUNDO ORDENAMIENTO\n\n");
	respuesta = ordenar(edades,QTY_EMPLEADOS);
	if(respuesta > 0){
		printf("\n iteraciones: %d\n\n",respuesta);
	}
	printArrayInt(edades,QTY_EMPLEADOS);

	return EXIT_SUCCESS;
}

/**
 * \brief Imprime a modo DEBUG la informacion de un array de enteros
 * \param array Es el puntero al array a ser ordenado
 * \param limite es la longitud del array
 * \return 0 si Ok o -1 para indicar error
 */
int printArrayInt(int array[],int limite){
	int retorno = -1;
	int i;
	if(array != NULL && limite >= 0){
		for(i=0;i<limite;i++){
			printf("[DEBUG]   Indice: %d  -  Valor: %d \n",i,array[i]);
		}
		retorno = 0;
	}

	return retorno;
}



/**
 * \brief Ordena un array de enteros DESC
 * \param array Es el puntero al array a ser ordenado
 * \param limite es la longitud del array
 * \return Cantidad de iteraciones necesarios para ordenar si Ok o -1 para indicar error
 */
int ordenar(int array[],int limite){
	int retorno = -1;
	int flagSwap;
	int i;
	int contador = 0;
	int bufferAuxiliar;
	int nuevoLimite;
	if(array != NULL && limite >= 0){
		nuevoLimite = limite - 1;
		do{
			flagSwap = 0;
			for(i=0;i<nuevoLimite;i++){
				if(array[i] < array[i+1]){
					flagSwap = 1;
					bufferAuxiliar = array[i];
					array[i] = array[i+1];
					array[i+1] = bufferAuxiliar;
				}
				contador++;
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno = contador;

	}
	return retorno;
}
