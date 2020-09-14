/*
 * logica.c
 *
 *  Created on: 14 sep. 2020
 *      Author: fedef
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * \brief Solicita un numero al usuario
 * \param arrayNumeros: array donde se guardara los valores obtenidos
 * \param len: longitud del array
 * \param min: rango minimo de numeros para poder ingresar
 * \nparam max:rango maximo de numeros para poder ingresar
 * \return retorna 0 si todo esta bien, de lo contrario retorna -1
 */
int solicitarNumeros(int arrayNumeros[],int len,int min,int max){
	int retorno = -1;
	int i;
	int bufferInt;
	if(arrayNumeros != NULL && len > 0){
		for(i=0;i<len;i++){
			if(!utn_getNumero(&bufferInt,"\nIngrese numero: ","\nNumero invalido!",min,max,3)){
				arrayNumeros[i] = bufferInt;
				retorno = 0;
			}else{
				printf("\nSe acabaron los intentos para ingresar bien le numero.\n");
			}
		}
	}
	return retorno;
}
/**
 * \brief Borra los numeros impares del array de enteros pasado por parametro
 * \param arrayDeImpares: array de enteros
 * \param len: longitud del array
 * \return retorna 0 si todo esta bien, de lo contrario retorna -1
 */
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
/**
 * \brief Ordena Array de enteros de menor a mayor
 * \param array: array de enteros
 * \param len: longitud del array
 * \return retorna 0 si todo esta bien, de lo contrario retorna -1
 */
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
