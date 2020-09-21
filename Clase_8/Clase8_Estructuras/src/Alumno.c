/*
 * Alumno.c
 *
 *  Created on: 05 feb. 1674 :O
 *      Author: Flores Federico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"


/**
 * \brief inicializo el array de alumnos
 * \param pArray: un puntero al array de alumnos
 * \param limite: define el tamaño del array
 * \return retorna 0 (OK) sino -1 (ERROR)
 */
int initArrayAlumnos(Alumno* pArray,int limite){
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0){
		for(i=0;i<limite;i++){
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}



/**
 * \brief imprimo el array de alumnos
 * \param pArray: un puntero al array de alumnos
 * \param limite: define el tamaño del array
 * \return retorna 0 (OK) sino -1 (ERROR)
 */
int imprimirArrayAlumnos(Alumno* pArray,int limite){
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0){
		for(i=0;i<limite;i++){
			if(!pArray[i].isEmpty){
				printf("Nombre: %s  - Legajo: %d  - Altura: %.2f\n",pArray[i].nombre,pArray[i].legajo,pArray[i].altura);
			}
		}
		retorno = 0;
	}
	return retorno;
}

