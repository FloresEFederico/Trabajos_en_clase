#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"

static int generadorIdCliente(void); //utilizado en la funcion cli_altaArray


/**
 * brief: Imprime los datos de la variable Cliente
 * \param: auxProducto: variable de clientes a ser imprimida
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int cli_imprimir(Cliente* auxProducto)
{
	int retorno= -1;
	if(auxProducto != NULL)
	{
		printf("\nID: %d\nNOMBRE: %11s\nALTURA: %.2f  -  DNI: %11s\n---------------------------------------\n",auxProducto->id,auxProducto->nombre,auxProducto->altura,auxProducto->dni);
		retorno = 0;
	}
	return retorno;
}
/**
 * brief: Imprime el array de clientes
 * \param: pArray: Array de clientes a ser actualizado
 * \param limite: limite del array de clientes
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int cli_imprimirArray(Cliente* pArray,int limite)
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
				cli_imprimir(&pArray[i]);
				flag = 1;
			}
		}
		if(flag)
		{
			retorno = 0;
		}else
		{
			printf("\nNo se ha cargado ningun Cliente!\n");
		}
	}
	return retorno;
}

/**
 * brief: Inicializa el array
 * \param: pArray: Array de clientes a ser actualizado
 * \param limite: limite del array de clientes
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int cli_inicializarArray(Cliente* pArray,int limite)
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
 * \param: pArray: Array de clientes a ser actualizado
 * \param limite: limite del array de clientes
 * \return Retorna i (EXITO) y -1(ERROR)
 */
int cli_getEmptyIndex(Cliente* pArray,int limite)
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
 * brief: Da de alta un cliente en una posicion del array
 * \param: pArray: Array de clientes a ser actualizado
 * \param limite: limite del array de clientes
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int cli_altaArray(Cliente* pArray,int limite)
{
	int retorno = -1;
	Cliente auxCliente;
	int indiceLibre;
	if(pArray != NULL && limite > 0)
	{
		indiceLibre = cli_getEmptyIndex(pArray,limite);
		if(indiceLibre != -1 &&
		   !utn_getNombre(auxCliente.nombre,NOMBRE_LEN,"\nIngrese nombre del cliente: ","\nNombre invalido!\n",3) &&
		   !utn_getDni(auxCliente.dni,DNI_LEN,"Ingrese DNI: ","\nDNI invalido!\n",3) &&
		   !utn_getNumeroFloat(&auxCliente.altura,"\nIngrese la altura(1-2.20): ","\nAltura invalida!\n",1,2.20,3)
		   )
		{
			auxCliente.id = generadorIdCliente();
			auxCliente.isEmpty = FALSE;
			pArray[indiceLibre] = auxCliente;
			retorno = 0;
		}
		if(indiceLibre == -1)
		{
			printf("\nYa no hay espacio para seguir cargando Clientes.\n");
		}
	}
	return retorno;
}
/**
 * \brief: genera un valor de ID para array de Clientes.Id
 * \return id
 */
static int generadorIdCliente(void)
{
	static int id = 999;
	id++;
	return id;
}

/**
 * brief: busca un Id existente en el array de Clientes y devuelve su indice si se encontro
 * \param: pArray: Array de clientes a ser actualizado
 * \param limite: limite del array de clientes
 * \param: idABuscar: id a ser buscado
 * \return Retorna i (ID ENCONTRADO) y -1(ID NO ENCONTRADO)
 */
int cli_buscarId(Cliente* pArray,int limite,int idABuscar)
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
 * brief: Actualiza los datos de un Cliente en una posicion del array
 * \param: pArray: Array de Clientes a ser actualizado
 * \param limite: limite del array de clientes
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int cli_modificarArray(Cliente* pArray,int limite)
{
	int retorno = -1;
	int idModificacion;
	int indiceAModificar;
	char auxNombre[NOMBRE_LEN];
	char auxDni[DNI_LEN];
	float auxAltura;
	int opcionModificar;
	if(pArray != NULL && limite > 0 && !cli_imprimirArray(pArray,limite))
	{
		utn_getNumero(&idModificacion,"Ingrese el ID del cliente que desea modificar(1000-1100): ","\nID invalido!\n",1000,1100,3);
		indiceAModificar = cli_buscarId(pArray,limite,idModificacion);
		if(indiceAModificar != - 1 &&
		   !utn_getNumero(&opcionModificar,"\n¿Que desea modificar?\n"
										   "1-Nombre.\n"
										   "2-DNI.\n"
										   "3-Altura.\n"
										   "4-Salir.\nElija una opcion(1-4): ","\nOpcion invalida!\n",1,4,3)
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
				if(!utn_getDni(auxDni,DNI_LEN,"\nIngrese nuevo DNI: ","\nDNI invalido!\n",3))
				{
					strncpy(pArray[indiceAModificar].dni,auxDni,DNI_LEN);
					printf("\nSe ha modificado el DNI!\n");
					retorno = 0;
				}else
				{
					printf("\nSe acabo el numero de reintentos para ingresar un DNI valido\n");
				}
				break;
			case 3:
				if(!utn_getNumeroFloat(&auxAltura,"\nIngrese nueva altura(1-2.20): ","\nAltura invalida!\n",1,2.20,3))
				{
					pArray[indiceAModificar].altura = auxAltura;
					printf("\nSe ha modificado la altura!\n");
					retorno = 0;
				}else
				{
					printf("\nSe acabo el numero de reintentos para ingresar una altura valida\n");

				}
				break;
			case 4:
				retorno = 0;
				printf("\nModificacion cancelada\n");
				break;
			}
		}
		if(indiceAModificar == -1)
		{
			printf("\nNo se encontro a un cliente con el ID ingresado.\n");
		}
	}
	return retorno;
}

/**
 * brief: Da de baja un Cliente del Array.
 * \param: pArray: Array de Clientes a ser actualizado
 * \param limite: limite del array de clientes
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int cli_bajaArray(Cliente* pArray,int limite)
{
	int retorno = -1;
	int idBaja;
	int indiceADarDeBaja;
	if(pArray != NULL && limite > 0)
		{
			cli_imprimirArray(pArray,limite);
			utn_getNumero(&idBaja,"Ingrese el ID del cliente que desea dar de baja(1000-1100): ","\nID invalido!\n",1000,1100,3);
			indiceADarDeBaja = cli_buscarId(pArray,limite,idBaja);
			if(indiceADarDeBaja != - 1)
			{
				pArray[indiceADarDeBaja].isEmpty = TRUE;
				retorno = 0;
			}
			if(indiceADarDeBaja == -1)
			{
				printf("\nNo se encontro a un cliente con el ID ingresado.\n");
			}
		}
	return retorno;
}

/**
 * brief: Ordena al array de Clientes por Nombre y altura, dependiendo valor de orden pasado por parametro.
 * \param: pArray: Array de Clientes a ser actualizado
 * \param limite: limite del array de clientes
 * \nparam orden: 0 (ASCENDENTE)/ 1 (DESCENDENTE)
 * \return Retorna 0 (EXITO) y -1(ERROR)
 */
int cli_ordenarPorNombreYAltura(Cliente* pArray,int limite,int orden)
{
	int retorno = -1;
	int flagSwap;
	int i;
	Cliente auxCliente;
	if(pArray != NULL && limite > 0 && (orden == 0 || orden == 1))
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if((orden == 0 && strncmp(pArray[i].nombre,pArray[i+1].nombre,NOMBRE_LEN) > 0) ||
				   (orden == 0 && strncmp(pArray[i].nombre,pArray[i+1].nombre,NOMBRE_LEN) == 0 && pArray[i].altura > pArray[i+1].altura) ||
				   (orden == 1 && strncmp(pArray[i].nombre,pArray[i+1].nombre,NOMBRE_LEN) < 0) ||
				   (orden == 1 && strncmp(pArray[i].nombre,pArray[i+1].nombre,NOMBRE_LEN) == 0 && pArray[i].altura < pArray[i+1].altura))
				{
					auxCliente = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = auxCliente;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}

