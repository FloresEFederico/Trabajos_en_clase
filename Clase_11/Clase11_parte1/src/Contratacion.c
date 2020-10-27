#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Contratacion.h"


static int generadorIdContratacion(void); //utilizado en la funcion contratacion_altaArray

/**
 * brief: Imprime los datos de la variable Contratacion
 * \param: auxProducto: variable de Contrataciones a ser imprimida
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int contratacion_imprimir(Contratacion* auxContratacion)
{
	int retorno= -1;
	if(auxContratacion != NULL)
	{
		printf("\nID: %d\nNOMBRE DE ARCHIVO: %11s\nCUIT: %s CANTIDAD DE DIAS: %d  -  IDPANTALLA: %d\n---------------------------------------\n",auxContratacion->id,auxContratacion->nombreDeArchivo,auxContratacion->cuit,auxContratacion->cantidadDeDias,auxContratacion->idPantalla);
		retorno = 0;
	}
	return retorno;
}
/**
 * brief: Imprime el array de Contrataciones
 * \param: pArray: Array de Contrataciones a ser actualizado
 * \param limite: limite del array de Contrataciones
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int contratacion_imprimirArray(Contratacion* pArray,int limite)
{
	int retorno = -1;
	int i;
	int flag = 0;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				contratacion_imprimir(&pArray[i]);
				flag = 1;
			}
		}
		if(flag)
		{
			retorno = 0;
		}else
		{
			printf("\nNo se ha cargado ninguna Contratacion!\n");
		}
	}
	return retorno;
}

/**
 * brief: Inicializa el array
 * \param: pArray: Array de Contrataciones a ser actualizado
 * \param limite: limite del array de Contrataciones
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int contratacion_inicializarArray(Contratacion* pArray,int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * brief: Busca un indice libre y lo devuelve
 * \param: pArray: Array de Contrataciones a ser actualizado
 * \param limite: limite del array de Contrataciones
 * \return Retorna i (EXITO) y -1(ERROR)
 */
int contratacion_getEmptyIndex(Contratacion* pArray,int limite)
{
	int indiceEncontrado = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == TRUE)
			{
				indiceEncontrado = i;
				break;
			}
		}
	}
	return indiceEncontrado;
}

/**
 * brief: Da de alta una Contratacion en una posicion del array
 * \param: pArray: Array de Contrataciones a ser actualizado
 * \param limite: limite del array de Contrataciones
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int contratacion_altaArray(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	Contratacion auxContratacion;
	int indiceLibre;
	int auxIdPantalla;
	int existeIdPantalla;
	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0)
	{
		indiceLibre = contratacion_getEmptyIndex(pArray,limite);
		if(indiceLibre != -1 &&
		   !pantalla_imprimirArray(pArrayPantalla,limitePantalla) &&
		   !utn_getNumero(&auxIdPantalla,"Elija ID donde desea publicar: ","\nId invalido!\n",MIN_IDPANTALLA,MAX_IDPANTALLA,3))
		{
			existeIdPantalla = pantalla_buscarId(pArrayPantalla,limitePantalla,auxIdPantalla);
			if(existeIdPantalla != -1 &&
			   !utn_getDni(auxContratacion.cuit,CUIT_LEN,"Ingrese Cuit del cliente: ","\nCuit invalido!\n",3) &&
			   !utn_getNumero(&auxContratacion.cantidadDeDias,"\nIngrese la cantidad de dias(1-365): ","\nCantidad invalida!\n",MIN_DIAS,MAX_DIAS,3) &&
			   !utn_getDireccion(auxContratacion.nombreDeArchivo,ARCHIVO_LEN,"\nIngrese nombre de archivo: ","\nNombre invalido!\n",3))
			{
				auxContratacion.idPantalla = auxIdPantalla;
				auxContratacion.id = generadorIdContratacion();
				auxContratacion.isEmpty = FALSE;
				pArray[indiceLibre] = auxContratacion;
				retorno = 0;
			}
		}
		if(indiceLibre == -1)
		{
			printf("\nNo hay espacios libres para hacer una Contratacion.\n");
		}
		if(existeIdPantalla == -1)
		{
			printf("\nNo se encontro ninguna pantalla con ese Id.\n");
		}
	}
	return retorno;
}
/**
 * \brief: genera un valor de ID para array de Contratacions.Id
 * \return id
 */
static int generadorIdContratacion(void)
{
	static int id = 999;
	id++;
	return id;
}

/**
 * brief: busca un Id existente en el array de Contrataciones y devuelve su indice si se encontro
 * \param: pArray: Array de Contrataciones a ser actualizado
 * \param limite: limite del array de Contrataciones
 * \param: idABuscar: id a ser buscado
 * \return Retorna i (ID ENCONTRADO) y -1(ID NO ENCONTRADO)
 */
int contratacion_buscarId(Contratacion* pArray,int limite,int idABuscar)
{
	int indiceEncontrado = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == FALSE && pArray[i].id == idABuscar)
			{
				indiceEncontrado = i;
				break;
			}
		}
	}
	return indiceEncontrado;
}

/**
 * brief: busca un Cuit existente en el array de Contrataciones y devuelve su indice si se encontro
 * \param: pArray: Array de Contrataciones a ser actualizado
 * \param limite: limite del array de Contrataciones
 * \param: CuitABuscar: Cuit a ser buscado
 * \return Retorna i (ID ENCONTRADO) y -1(ID NO ENCONTRADO)
 */
int contratacion_buscarCuit(Contratacion* pArray,int limite,char* cuitABuscar)
{
	int indiceEncontrado = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == FALSE &&
			   strncmp(pArray[i].cuit,cuitABuscar,CUIT_LEN) == 0)
			{
				indiceEncontrado = i;
				break;
			}
		}
	}
	return indiceEncontrado;
}





/**
 * brief: Actualiza los datos de una Contratacion en una posicion del array
 * \param: pArray: Array de Contratacions a ser actualizado
 * \param limite: limite del array de Contrataciones
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int contratacion_modificarArray(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	char auxCuit[CUIT_LEN];
	int existeCuit;
	int auxId;
	int auxCantidadDeDias;
	int buscarIndice;
	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0 && !contratacion_imprimirArray(pArray,limite))
	{
		utn_getDni(auxCuit,CUIT_LEN,"\nIngrese Cuit de cliente: ","\nCuit invalido!\n",3);
		existeCuit = contratacion_buscarCuit(pArray,limite,auxCuit);
		if(existeCuit != -1 &&
		   !contratacion_mostrarPantallasContratadas(pArray,limite,pArrayPantalla,limitePantalla,auxCuit) &&
		   !utn_getNumero(&auxId,"\nElija un id de contratacion: ","\nId invalido!\n",1000,1999,3))
		{
			buscarIndice = contratacion_buscarId(pArray,limite,auxId);
			if(buscarIndice != -1 &&
			   !utn_getNumero(&auxCantidadDeDias,"\nIngrese nueva cantidad de dias(1-365): ","\nCantidad invalida!\n",MIN_DIAS,MAX_DIAS,3))
			{
				pArray[buscarIndice].cantidadDeDias = auxCantidadDeDias;
				retorno = 0;
			}
		}
		if(existeCuit == -1)
		{
			printf("\nEse cuit no existe\n");
		}
		if(buscarIndice == -1)
		{
			printf("\nNo se encontro una publicidad contratada con ese id\n");
		}
	}
	return retorno;
}

/**
 * brief: Da de baja un Contratacion del Array.
 * \param: pArray: Array de Contrataciones a ser dado de baja
 * \param limite: limite del array de Contrataciones
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int contratacion_bajaArray(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	char auxCuit[CUIT_LEN];
	int existeCuit;
	int auxIdContratacion;
	int buscarIndice;

	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0)
	{
		utn_getDni(auxCuit,CUIT_LEN,"\nIngrese Cuit de cliente que desea dar de baja: ","\nCuit invalido!\n",3);
		existeCuit = contratacion_buscarCuit(pArray,limite,auxCuit);
		if(existeCuit != -1 &&
		   !contratacion_mostrarPantallasContratadas(pArray,limite,pArrayPantalla,limitePantalla,auxCuit) &&
		   !utn_getNumero(&auxIdContratacion,"\nElija un id de contratacion: ","\nId invalido!\n",1000,1999,3))
		{
			buscarIndice = contratacion_buscarId(pArray,limite,auxIdContratacion);
			if(buscarIndice != -1)
			{
				pArray[buscarIndice].isEmpty = TRUE;
				retorno = 0;
			}else
			{
				printf("\nNo se encontro una publicidad contratada con ese id\n");
			}
		}
		if(existeCuit == -1)
		{
			printf("\nEse cuit no existe\n");
		}
	}
	return retorno;
}

/**
 * brief: Ordena al array de Contrataciones por Nombre y altura, dependiendo valor de orden pasado por parametro.
 * \param: pArray: Array de Contrataciones a ser actualizado
 * \param limite: limite del array de contrataciones
 * \nparam orden: 0 (ASCENDENTE)/ 1 (DESCENDENTE)
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int contratacion_ordenarPorNombre(Contratacion* pArray,int limite,int orden)
{
	int retorno = -1;
	int flagSwap;
	int i;
	Contratacion auxContratacion;
	if(pArray != NULL && limite > 0 && (orden == 0 || orden == 1))
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if((orden == 0 && strncmp(pArray[i].nombreDeArchivo,pArray[i+1].nombreDeArchivo,ARCHIVO_LEN) > 0) ||
				   (orden == 1 && strncmp(pArray[i].nombreDeArchivo,pArray[i+1].nombreDeArchivo,ARCHIVO_LEN) < 0))
				{
					auxContratacion = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = auxContratacion;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief: lista todas las pantallas que el cliente tiene contratadas a partir del cuit y idPantalla, mostrando sus campos
 * \param: pArray: Array de Contrataciones
 * \param limite: limite del array de contrataciones
 * \param pArrayPantalla: Array de Pantallas
 * \param limitePantalla: limite del array de pantallas
 * \param cuit: cuit del cliente.
 * \nreturn Retorna 0 (EXITO) y -1 (ERROR)
 */
int contratacion_mostrarPantallasContratadas(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla,char* cuit)
{
	int retorno = -1;
	int i;
	int buscarIndicePantalla;
	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0 && cuit != NULL)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == FALSE && strncmp(pArray[i].cuit,cuit,CUIT_LEN) == 0)
			{
				buscarIndicePantalla = pantalla_buscarId(pArrayPantalla,limitePantalla,pArray[i].idPantalla);
				if(buscarIndicePantalla != -1)
				{
					printf("\nID: %d\nNOMBRE DE ARCHIVO: %11s CUIT: %s CANTIDAD DE DIAS: %d",pArray[i].id,pArray[i].nombreDeArchivo,pArray[i].cuit,pArray[i].cantidadDeDias);
					pantalla_imprimir(&pArrayPantalla[buscarIndicePantalla]);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}


