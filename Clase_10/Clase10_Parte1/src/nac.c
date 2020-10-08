/*
 * nac.c
 *
 *  Created on: 29 sep. 2020
 *      Author: fedef
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "nac.h"

static int generarIdNacionalidadNuevo(void);


/**
 * \brief Realiza el alta de un Nacionalidad solo si el indice corresponde a un Empty
 * \param Nacionalidad* pArray: es el puntero al array de Nacionalidad
 * \param int limite: es el limite del array
 * \param int indice: es el indice donde se cargara el Nacionalidad
 * \return (-1) ERROR/ (0) Ok
 */
int nacionalidad_alta(Nacionalidad* pArray,int limite){
	int retorno = -1;
	int indiceLibre;
	Nacionalidad bufferNacionalidad;
	if(pArray != NULL &&  limite > 0){
		indiceLibre = nacionalidad_buscarLibre(pArray,limite);
		if(indiceLibre != -1 && !utn_getCadena(bufferNacionalidad.nombre,SIZE_NAC,"\nIngrese Nombre de nacionalidad: ","\nNombre de nacionalidad invalido\n",3)
			){
			bufferNacionalidad.id = generarIdNacionalidadNuevo();
			bufferNacionalidad.isEmpty = FALSE;
			pArray[indiceLibre] = bufferNacionalidad;
			retorno = 0;
		}
		if(indiceLibre == -1){
			printf("\nNo hay espacios libres!\n");
		}
	}
	return retorno;
}


/**
 * \brief imprime al array de Nacionalidads que estan cargados
 * \param Nacionalidad* pArray: es el puntero al array de Nacionalidad
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int nacionalidad_imprimirTodos(Nacionalidad* pArray,int lenArray){
	int retorno = -1;
	int i;
	int flag = 0;
	if(pArray != NULL &&  lenArray > 0){
		for(i=0;i<lenArray;i++){
			if(pArray[i].isEmpty == FALSE){
				nacionalidad_imprimir(pArray[i],i);
				flag = 1;
			}
		}
		if(!flag){
			printf("\nNo hay Nacionalidads que mostrar\n");
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief imprime Nacionalidad que este cargado
 * \param Nacionalidad bufferNacionalidad: Nacionalidad
 * \param indice: indice del Nacionalidad
 */
void nacionalidad_imprimir(Nacionalidad buffer,int indice){
	printf("\nIndice: %d   - ID: %d   -   Nombre: %-11s",indice,buffer.id,buffer.nombre);
}

/**
 * \brief inicializa al array de Nacionalidad
 * \param Nacionalidad* pArray: es el puntero al array de Nacionalidad
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int nacionalidad_initArray(Nacionalidad* pArray,int lenArray){
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
 * \brief busca un indice libre(isEmpty == 1) en el array de Nacionalidad
 * \param Nacionalidad* pArray: es el puntero al array de Nacionalidad
 * \param int limite: es el limite del array
 * \return (-1) ERROR / (i) si encontro un indice libre
 */
int nacionalidad_buscarLibre(Nacionalidad* pArray,int limite)
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


int nacionalidad_indiceExistente(Nacionalidad* pArray,int limite,int indice){
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
 * \brief modifica a una  Nacionalidad solo si el indice corresponde a un No Empty y existe el id.
 * \param Nacionalidad* pArray: es el puntero al array de Nacionalidad
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int nacionalidad_modificar(Nacionalidad* pArray,int limite){
	int retorno = -1;
	int idBuscar;
	int existeId;
	Nacionalidad auxNacionalidad;
	if(pArray != NULL && limite > 0)
	{
		nacionalidad_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija ID de la Nacionalidad que desea modificar(1000-1999): ","\nID invalido!\n",2000,2999,3);
		existeId = nacionalidad_buscarId(pArray,limite,idBuscar);
		if(existeId != -1 && !utn_getCadena(auxNacionalidad.nombre,SIZE_NAC,"\nIngrese nombre nuevo: ","\nNombre invalido!\n",3))
		{

			strncpy(pArray[existeId].nombre,auxNacionalidad.nombre,SIZE_NAC);
			retorno = 0;
		}
		if(existeId == -1)
		{
			printf("\nEse id no se encontro en ninguna Nacionalidad\n");
		}
	}
	return retorno;
}

/**
 * \brief da de baja a una Nacionalidad si el indice corresponde a un no Empty.
 * \param Nacionalidad* pArray: es el puntero al array de Nacionalidad
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int nacionalidad_baja(Nacionalidad* pArray,int limite){
	int retorno = -1;
	int idBuscar;
	int existeId;
	if(pArray != NULL && limite > 0){
		nacionalidad_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija indice de la Nacionalidad que desea dar de baja: ","\nIndice invalido!\n",0,QTY_NACIONALIDAD-1,3);
		existeId = nacionalidad_buscarId(pArray,limite,idBuscar);
		if(existeId != -1){
			pArray[idBuscar].isEmpty = TRUE;
			printf("\nSe ha dado de baja la Nacionalidad!\n");
			retorno = 0;
		}else{
			printf("\nNo se encontro la Nacionalidad en ese indice\n");
		}
	}
	return retorno;
}
/**
 * \brief ordena las nacionalidades por nombre.
 * \param Nacionalidad* pArray: es el puntero al array de Nacionalidad
 * \param int limite: es el limite del array
 * \param int orden: (0) descendente / (1) ascendente
 * \return (-1) ERROR/ (0) Ok
 */
int nacionalidad_ordenarPorNombre(Nacionalidad* pArray,int limite,int orden){
	int retorno = -1;
	int i;
	int flagSwap;
	Nacionalidad bufferNacionalidad;
	if(pArray != NULL && limite > 0 && (orden == 0 || orden == 1)){
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if((orden == 1 && strncmp(pArray[i].nombre,pArray[i+1].nombre,SIZE_NAC) > 0)
					||
				   (orden == 0 && strncmp(pArray[i].nombre,pArray[i+1].nombre,SIZE_NAC) < 0))
				{
					bufferNacionalidad = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = bufferNacionalidad;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

/**
 * \brief le da un valor al id de una Nacionalidad y lo incrementa en 1
 * \return idNacionalidad incrementado en 1
 */
static int generarIdNacionalidadNuevo(void)
{
	static int idNacionalidad=1999;
	idNacionalidad++;
	return idNacionalidad;
}

/**
 * \brief busca que el id pasado por parametro (id) exista dentro del array.En caso de existir, lo retorna.
 * \param Nacionalidad* pArray: es el puntero al array de Nacionalidad
 * \param int limite: es el limite del array
 * \param int idNacionalidad el id que se buscara.
 * \return (-1) si no se encontro el id/ (i) si se encontro.
 */
int nacionalidad_buscarId(Nacionalidad* pArray,int len,int id){
	int existeId = -1;
	int i;
	if(pArray != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty == FALSE && pArray[i].id == id)
			{
				existeId = i;
				break;
			}
		}
	}
	return existeId;
}

