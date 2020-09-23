/*
 * alumno.c
 *
 *  Created on: 22 sep. 2020
 *      Author: fedef
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"


/**
 * \brief Realiza el alta de un alumno solo si el indice corresponde a un Empty
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \param int indice: es el indice donde se cargara el Alumno
 * \return (-1) ERROR/ (0) Ok
 */
int alumno_alta(Alumno* pArray,int limite){
	int retorno = -1;
	int indice;
	Alumno bufferAlumno;
	if(pArray != NULL &&  limite > 0){
		indice = alumno_buscarLibre(pArray,limite);
		if(indice != -1 && !utn_getNumero(&bufferAlumno.legajo,"\nLegajo?(1-9999): ","\nLegajo invalido!\n",MIN_LEGAJO,MAX_LEGAJO,3) &&
		   !utn_getCadena(bufferAlumno.nombre,LONG_NOMBRE,"\nIngrese Nombre: ","\nNombre invalido\n",3)
			){
			bufferAlumno.isEmpty = FALSE;
			pArray[indice] = bufferAlumno;
			retorno = 0;
		}else{
			printf("\nHubo un error al realizar el alta\n");
		}
	}
	return retorno;
}


/**
 * \brief imprime al array de alumnos que estan cargados
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int alumno_imprimirTodos(Alumno* pArray,int lenArray){
	int retorno = -1;
	int i;
	int flag = 0;
	if(pArray != NULL &&  lenArray > 0){
		for(i=0;i<lenArray;i++){
			if(pArray[i].isEmpty == FALSE){
				alumno_imprimir(pArray[i],i);
				flag = 1;
			}
		}
		if(!flag){
			printf("\nNo hay alumnos que mostrar\n");
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief imprime alumno que este cargado
 * \param Alumno bufferAlumno: alumno
 * \param indice: indice del alumno
 */
void alumno_imprimir(Alumno bufferAlumno,int indice){
	printf("\nIndice: %d   -   Nombre: %-11s  -  Legajo: %d",indice,bufferAlumno.nombre,bufferAlumno.legajo);
}

/**
 * \brief inicializa al array de alumnos
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int alumno_initArray(Alumno* pArray,int lenArray){
	int retorno = -1;
	int i;
	if(pArray != NULL &&  lenArray > 0){
		for(i=0;i<lenArray;i++){
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief busca un indice libre(isEmpty == 1) en el array de alumnos
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \return (-1) ERROR / (i) si encontro un indice libre
 */
int alumno_buscarLibre(Alumno* pArray,int limite)
{
	int indiceLibre = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == 1)
			{
				indiceLibre = i;
				break;
			}
		}
	}
	return indiceLibre;
}


int alumno_indiceExistente(Alumno* pArray,int limite,int indice){
	int indiceExistente = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == 0 && i == indice)
			{
				indiceExistente = i;
				break;
			}
		}
	}
	return indiceExistente;
}

/**
 * \brief modifica a un  alumno solo si el indice corresponde a un No Empty
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int alumno_modificar(Alumno* pArray,int limite){
	int retorno = -1;
	int indiceABuscar;
	int existe;
	Alumno auxAlumno;
	if(pArray != NULL && limite > 0){
		alumno_imprimirTodos(pArray,limite);
		utn_getNumero(&indiceABuscar,"\nElija indice del alumno que desea modificar: ","\nIndice invalido!\n",0,QTY_ALUMNOS-1,3);
		existe = alumno_indiceExistente(pArray,limite,indiceABuscar);
		if(existe != -1 &&
		   !utn_getNumero(&auxAlumno.legajo,"\nIngrese legajo a modificar(0-9999): ","\nLegajo invalido!\n",MIN_LEGAJO,MAX_LEGAJO,3 &&
		   !utn_getCadena(auxAlumno.nombre,LONG_NOMBRE,"\nIngrese nombre nuevo: ","\nNombre invalido!\n",3))
		){
			pArray[indiceABuscar].legajo = auxAlumno.legajo;
			strncpy(pArray[indiceABuscar].nombre,auxAlumno.nombre,LONG_NOMBRE);
			retorno = 0;
		}else{
			printf("\nNo se pudo modificar el alumno\n");
		}
	}
	return retorno;
}

/**
 * \brief da de baja a un alumno si el indice corresponde a un no Empty.
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int alumno_baja(Alumno* pArray,int limite){
	int retorno = -1;
	int indiceABuscar;
	int existe;
	if(pArray != NULL && limite > 0){
		alumno_imprimirTodos(pArray,limite);
		utn_getNumero(&indiceABuscar,"\nElija indice del alumno que desea dar de baja: ","\nIndice invalido!\n",0,QTY_ALUMNOS-1,3);
		existe = alumno_indiceExistente(pArray,limite,indiceABuscar);
		if(existe != -1){
			pArray[indiceABuscar].isEmpty = TRUE;
			printf("\nSe ha dado de baja el alumno!\n");
			retorno = 0;
		}else{
			printf("\nNo se encontro un alumno en ese indice\n");
		}
	}
	return retorno;
}
/**
 * \brief ordena a los alumnos por nombre.
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int alumno_ordenarPorNombre(Alumno* pArray,int limite){
	int retorno = -1;
	int i;
	int j;
	Alumno auxAlumn;
	if(pArray != NULL && limite > 0){
		for(i=0;i<limite-1;i++)
		{
			for(j=i+1;j<limite;j++)
			{
				if(strcmp(pArray[i].nombre,pArray[j].nombre) > 0)
				{
					auxAlumn = pArray[i];
					pArray[i] = pArray[j];
					pArray[j] = auxAlumn;
				}
			}
		}
		printf("\nSe han ordenado los alumnos!\n");
		retorno = 0;
	}
	return retorno;
}
