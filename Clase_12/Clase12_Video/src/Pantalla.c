#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"

static int generadorIdPantalla(void); //utilizado en la funcion pantalla_altaArray

/**
 * brief: Imprime los datos de la variable Pantalla
 * \param: auxProducto: variable de Pantalla a ser imprimida
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int pantalla_imprimir(Pantalla* auxPantalla)
{
	int retorno= -1;
	char tipoDescripcion[20];
	if(auxPantalla != NULL)
	{
		if(auxPantalla->tipo == 1)
		{
			strncpy(tipoDescripcion,"Led",sizeof(tipoDescripcion));
		}else
		{
			strncpy(tipoDescripcion,"LCD",sizeof(tipoDescripcion));
		}
		printf("\nID PANTALLA: %d NOMBRE: %11s - TIPO: %s -  PRECIO: %.2f\nDIRECCION: %s\n",auxPantalla->id,auxPantalla->nombre,tipoDescripcion,auxPantalla->precio,auxPantalla->direccion);
		retorno = 0;
	}
	return retorno;
}
/**
 * brief: Imprime el array de pantallas
 * \param: pArray: Array de pantallas a ser actualizado
 * \param limite: limite del array de pantallas
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int pantalla_imprimirArray(Pantalla* pArray,int limite)
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
				pantalla_imprimir(&pArray[i]);
				flag = 1;
			}
		}
		if(flag)
		{
			retorno = 0;
		}else
		{
			printf("\nNo se ha cargado ningun Pantalla!\n");
		}
	}
	return retorno;
}

/**
 * brief: Inicializa el array
 * \param: pArray: Array de Pantallas a ser actualizado
 * \param limite: limite del array de Pantallas
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int pantalla_inicializarArray(Pantalla* pArray,int limite)
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
 * \param: pArray: Array de Pantalla a ser actualizado
 * \param limite: limite del array de Pantalla
 * \return Retorna i (EXITO) y -1(ERROR)
 */
int pantalla_getEmptyIndex(Pantalla* pArray,int limite)
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
 * brief: Da de alta un Pantalla en una posicion del array
 * \param: pArray: Array de Pantalla a ser actualizado
 * \param limite: limite del array de Pantalla
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int pantalla_altaArray(Pantalla* pArray,int limite)
{
	int retorno = -1;
	Pantalla auxPantalla;
	int indiceLibre;
	if(pArray != NULL && limite > 0)
	{
		indiceLibre = pantalla_getEmptyIndex(pArray,limite);
		if(indiceLibre != -1 &&
		   !utn_getNombre(auxPantalla.nombre,NOMBRE_LEN,"\nIngrese nombre de la Pantalla: ","\nNombre invalido!\n",3) &&
		   !utn_getNumero(&auxPantalla.tipo,"\nTipos:\n1-Led.\n2-LCD.\nElija tipo(1-2): ","\nTipo invalido!\n",1,2,3)  &&
		   !utn_getDireccion(auxPantalla.direccion,DIREC_LEN,"Ingrese Direccion: ","\nDireccion invalida!\n",3) &&
		   !utn_getNumeroFloat(&auxPantalla.precio,"Elija precio(1000-9999): ","\nPrecio invalido!\n",MIN_PRECIO,MAX_PRECIO,3)
		   )
		{
			auxPantalla.id = generadorIdPantalla();
			auxPantalla.isEmpty = FALSE;
			pArray[indiceLibre] = auxPantalla;
			retorno = 0;
		}
		if(indiceLibre == -1)
		{
			printf("\nYa no hay espacio para seguir cargando Pantallas.\n");
		}
	}
	return retorno;
}
/**
 * \brief: genera un valor de ID para array de Pantallas.Id
 * \return id
 */
static int generadorIdPantalla(void)
{
	static int id = 99;
	id++;
	return id;
}

/**
 * brief: busca un Id existente en el array de Pantallas y devuelve su indice si se encontro
 * \param: pArray: Array de Pantalla a ser actualizado
 * \param limite: limite del array de Pantalla
 * \param: idABuscar: id a ser buscado
 * \return Retorna i (ID ENCONTRADO) y -1(ID NO ENCONTRADO)
 */
int pantalla_buscarId(Pantalla* pArray,int limite,int idABuscar)
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
 * brief: Actualiza los datos de una Pantalla en una posicion del array
 * \param: pArray: Array de Pantallas a ser actualizado
 * \param limite: limite del array de Pantalla
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int pantalla_modificarArray(Pantalla* pArray,int limite)
{
	int retorno = -1;
	int idModificacion;
	int indiceAModificar;
	char auxNombre[NOMBRE_LEN];
	int auxTipo;
	char auxDireccion[DIREC_LEN];
	float auxPrecio;
	int opcionModificar;
	if(pArray != NULL && limite > 0 && !pantalla_imprimirArray(pArray,limite))
	{
		utn_getNumero(&idModificacion,"Ingrese el ID de la Pantalla que desea modificar(100-999): ","\nID invalido!\n",100,999,3);
		indiceAModificar = pantalla_buscarId(pArray,limite,idModificacion);
		if(indiceAModificar != - 1 &&
		   !utn_getNumero(&opcionModificar,"\n¿Que desea modificar?\n"
										   "1-Nombre.\n"
										   "2-Tipo.\n"
										   "3-Direccion.\n"
										   "4-Precio.\n"
										   "5-Salir.\nElija una opcion(1-5): ","\nOpcion invalida!\n",1,5,3)
			)
		{
			switch(opcionModificar)
			{
			case 1:
				if(!utn_getNombre(auxNombre,NOMBRE_LEN,"\nIngrese nuevo nombre: ","\nNombre invalido!\n",3))
				{
					strncpy(pArray[indiceAModificar].nombre,auxNombre,NOMBRE_LEN);
					printf("\nSe ha modificado el nombre!\n");
					retorno = 0;
				}else
				{
					printf("\nSe acabo el numero de reintentos para ingresar un nombre valido\n");
				}
				break;
			case 2:
				if(!utn_getNumero(&auxTipo,"\ntipos de pantalla:\n1-Led.\n2-LCD.\nIngrese un nuevo tipo(1-2): ","\nTipo invalido!\n",1,2,3))
				{
					pArray[indiceAModificar].tipo = auxTipo;
					printf("\nSe ha modificado el tipo!\n");
					retorno = 0;
				}else
				{
					printf("\nSe acabo el numero de reintentos para ingresar un tipo valido\n");

				}
				break;
			case 3:
				if(!utn_getDni(auxDireccion,DIREC_LEN,"\nIngrese nueva Direccion: ","\nDireccion invalida!\n",3))
				{
					strncpy(pArray[indiceAModificar].direccion,auxDireccion,DIREC_LEN);
					printf("\nSe ha modificado la Direccion!\n");
					retorno = 0;
				}else
				{
					printf("\nSe acabo el numero de reintentos para ingresar una Direccion valida\n");
				}
				break;
			case 4:
				if(!utn_getNumeroFloat(&auxPrecio,"\nIngrese nuevo precio(1000-9999): ","\nPrecio invalido!\n",MIN_PRECIO,MAX_PRECIO,3))
				{
					pArray[indiceAModificar].precio = auxPrecio;
					printf("\nSe ha modificado el precio!\n");
					retorno = 0;
				}else
				{
					printf("\nSe acabo el numero de reintentos para ingresar un precio valido\n");

				}
				break;
			case 5:
				retorno = 0;
				printf("\nModificacion cancelada\n");
				break;
			}
		}
		if(indiceAModificar == -1)
		{
			printf("\nNo se encontro a una Pantalla con el ID ingresado.\n");
		}
	}
	return retorno;
}

/**
 * brief: Da de baja una Pantalla del Array.
 * \param: pArray: Array de Pantallas a ser actualizado
 * \param limite: limite del array de Pantalla
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int pantalla_bajaArray(Pantalla* pArray,int limite)
{
	int retorno = -1;
	int idBaja;
	int indiceADarDeBaja;
	if(pArray != NULL && limite > 0)
		{
			pantalla_imprimirArray(pArray,limite);
			utn_getNumero(&idBaja,"Ingrese el ID de la Pantalla que desea dar de baja(100-999): ","\nID invalido!\n",100,999,3);
			indiceADarDeBaja = pantalla_buscarId(pArray,limite,idBaja);
			if(indiceADarDeBaja != - 1)
			{
				pArray[indiceADarDeBaja].isEmpty = TRUE;
				retorno = 0;
			}
			if(indiceADarDeBaja == -1)
			{
				printf("\nNo se encontro a una Pantalla con ese ID.\n");
			}
		}
	return retorno;
}

/**
 * brief: Ordena al array de Pantallas por Nombre y altura, dependiendo valor de orden pasado por parametro.
 * \param: pArray: Array de Pantallas a ser actualizado
 * \param limite: limite del array de Pantalla
 * \nparam orden: 0 (ASCENDENTE)/ 1 (DESCENDENTE)
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int pantalla_ordenarPorNombre(Pantalla* pArray,int limite,int orden)
{
	int retorno = -1;
	int flagSwap;
	int i;
	Pantalla auxPantalla;
	if(pArray != NULL && limite > 0 && (orden == 0 || orden == 1))
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if((orden == 0 && strncmp(pArray[i].nombre,pArray[i+1].nombre,NOMBRE_LEN) > 0) ||
				   (orden == 1 && strncmp(pArray[i].nombre,pArray[i+1].nombre,NOMBRE_LEN) < 0))
				{
					auxPantalla = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = auxPantalla;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}
