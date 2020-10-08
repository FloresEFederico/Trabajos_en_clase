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

static int generarIdAlumnoNuevo(void);


/**
 * \brief Realiza el alta de un alumno solo si el indice corresponde a un Empty
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \param int indice: es el indice donde se cargara el Alumno
 * \return (-1) ERROR/ (0) Ok
 */
int alumno_alta(Alumno* pArray,int limite){
	int retorno = -1;
	int indiceLibre;
	Alumno bufferAlumno;
	if(pArray != NULL &&  limite > 0){
		indiceLibre = alumno_buscarLibre(pArray,limite);
		if(indiceLibre != -1 && !utn_getNumero(&bufferAlumno.legajo,"\nLegajo?(1-9999): ","\nLegajo invalido!\n",MIN_LEGAJO,MAX_LEGAJO,3) &&
		   !utn_getCadena(bufferAlumno.nombre,LONG_NOMBRE,"\nIngrese Nombre: ","\nNombre invalido\n",3)
			){
			bufferAlumno.id = generarIdAlumnoNuevo();
			bufferAlumno.isEmpty = FALSE;
			pArray[indiceLibre] = bufferAlumno;
			retorno = 0;
		}
		if(indiceLibre == -1){
			printf("\nNo hay espacios libres!\n");
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
	printf("\nIndice: %d   - ID: %d   -   Nombre: %-11s  -  Legajo: %d",indice,bufferAlumno.id,bufferAlumno.nombre,bufferAlumno.legajo);
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
 * \brief modifica a un  alumno solo si el indice corresponde a un No Empty y existe el id.
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int alumno_modificar(Alumno* pArray,int limite){
	int retorno = -1;
	int idBuscar;
	int existeId;
	Alumno auxAlumno;
	if(pArray != NULL && limite > 0){
		alumno_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija ID del alumno que desea modificar(1000-1999): ","\nID invalido!\n",1000,1999,3);
		existeId = alumno_buscarId(pArray,limite,idBuscar);
		if(existeId != -1 &&
		   !utn_getNumero(&auxAlumno.legajo,"\nIngrese legajo a modificar(0-9999): ","\nLegajo invalido!\n",MIN_LEGAJO,MAX_LEGAJO,3 &&
		   !utn_getCadena(auxAlumno.nombre,LONG_NOMBRE,"\nIngrese nombre nuevo: ","\nNombre invalido!\n",3))
		){
			pArray[existeId].legajo = auxAlumno.legajo;
			strncpy(pArray[existeId].nombre,auxAlumno.nombre,LONG_NOMBRE);
			retorno = 0;
		}
		if(existeId == -1){
			printf("\nEse id no se encontro en ningun alumno\n");
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
	int idBuscar;
	int existeId;
	if(pArray != NULL && limite > 0){
		alumno_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija indice del alumno que desea dar de baja: ","\nIndice invalido!\n",0,QTY_ALUMNOS-1,3);
		existeId = alumno_buscarId(pArray,limite,idBuscar);
		if(existeId != -1){
			pArray[idBuscar].isEmpty = TRUE;
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
 * \param int orden: (0) descendente / (1) ascendente
 * \return (-1) ERROR/ (0) Ok
 */
int alumno_ordenarPorNombre(Alumno* pArray,int limite,int orden){
	int retorno = -1;
	int i;
	int flagSwap;
	Alumno bufferAlumno;
	if(pArray != NULL && limite > 0 && (orden == 0 || orden == 1)){
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if((orden == 1 && strncmp(pArray[i].nombre,pArray[i+1].nombre,LONG_NOMBRE) > 0)
					||
				   (orden == 0 && strncmp(pArray[i].nombre,pArray[i+1].nombre,LONG_NOMBRE) < 0))
				{
					bufferAlumno = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = bufferAlumno;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

/**
 * \brief le da un valor al id de un alumno y lo incrementa en 1
 * \return idAlumno incrementado en 1
 */
static int generarIdAlumnoNuevo(void)
{
	static int idAlumno=999;
	idAlumno++;
	return idAlumno;
}


/**
 * \brief busca que el id pasado por parametro (idAlumno) exista dentro del arrayAlumno.En caso de existir, lo retorna.
 * \param Alumno* pArray: es el puntero al array de Alumno
 * \param int limite: es el limite del array
 * \param int idAlumno el id que se buscara.
 * \return (-1) si no se encontro el id/ (i) si se encontro.
 */
int alumno_buscarId(Alumno* pArray,int len,int idAlumno){
	int existeId = -1;
	int i;
	if(pArray != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty == FALSE && pArray[i].id == idAlumno)
			{
				existeId = i;
				break;
			}
		}
	}
	return existeId;
}

