/*
 * calculosArray.c
 *
 *  Created on: 8 sep. 2020
 *      Author: fedef
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * \brief Calcula el numero maximo del array recibio como parametro
 * \param el array de enteros
 * \param la cantidad de elementos a ser procesado
 * \param puntero al espaicio de memoria donde se dejara el valor obtenido
 * \return -1 ERROR / 0 OK
 */
int calcularMaximo(int* pArray,int len,int* pMaximo){
	int retorno = -1;
	int maximo;
	int i;
	if(pArray != NULL && len > 0 && pMaximo != NULL){
		for(i=0;i<len;i++){
			if(i == 0 || pArray[i] > maximo){
				maximo = pArray[i];
			}
		}
		*pMaximo = maximo;
		retorno = 0;
	}
	return retorno;
}

int calcularMinimo(int* pArray,int len,int* pMinimo){
	int retorno = -1;
	int minimo;
	int i;
	if(pArray != NULL && len > 0 && pMinimo != NULL){
		for(i=0;i<len;i++){
			if(i == 0 || pArray[i] < minimo){
				minimo = pArray[i];
			}
		}
		*pMinimo = minimo;
		retorno = 0;
	}
	return retorno;
}

int calcularProbabilidad(int* pArray,int len,float* pProbabilidad){
	int retorno = -1;
	float probabilidad;
	int i;
	int acumulador = 0;
	if(pArray != NULL && len > 0 && pProbabilidad != NULL){
		for(i=0;i<len;i++){
			acumulador += pArray[i];
		}
		probabilidad = (float)acumulador/len;
		*pProbabilidad = probabilidad;
		retorno = 0;
	}
	return retorno;
}
