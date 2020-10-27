#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"

static int cargarListaCuit(Contratacion* pArray,int limite,char pArrayCuit[][CUIT_LEN],int limiteCuit,int* indice); // utilizada en informar_imprimirContratacionesConImportePorCliente

/**
 * \brief: se lista el importe a pagar por cada contratacion.
 * \param: pArray: Array de Contrataciones
 * \param limite: limite del array de contrataciones
 * \param pArrayPantalla: Array de Pantallas
 * \param limitePantalla: limite del array de pantallas
 * \nreturn Retorna 0 (EXITO) y -1 (ERROR)
 */
int informar_consultarFacturacion(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	char auxCuit[CUIT_LEN];
	int existeCuit;
	int i;
	int buscarIndicePantalla;
	float auxImporte;
	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0)
	{
		utn_getDni(auxCuit,CUIT_LEN,"\nIngrese Cuit de cliente: ","\nCuit invalido!\n",3);
		existeCuit = contratacion_buscarCuit(pArray,limite,auxCuit);
		if(existeCuit != -1)
		{
			printf("\n-Cliente: %s\n",auxCuit);
			for(i=0;i<limite;i++)
			{
				if(strncmp(pArray[i].cuit,auxCuit,CUIT_LEN) == 0)
				{
					buscarIndicePantalla = pantalla_buscarId(pArrayPantalla,limitePantalla,pArray[i].idPantalla);
					if(buscarIndicePantalla != -1)
					{
						auxImporte = pArray[i].cantidadDeDias*pArrayPantalla[buscarIndicePantalla].precio;
						printf("\nID: %d\n"
								"NOMBRE DE ARCHIVO: %11s\n"
								"CUIT: %s DIAS: %d  IDPANTALLA: %d\n"
								"IMPORTE: %.2f\n",pArray[i].id,pArray[i].nombreDeArchivo,pArray[i].cuit,pArray[i].cantidadDeDias,pArray[i].idPantalla,auxImporte);
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}

//Lista de cada cliente con cantidad de contrataciones e importe a pagar por cada una.

/**
 * \brief: Informe que imprime los Clientes por Cuit e imprime el importe a pagar de cada Cliente.
 * \param: pArray: Array de Contrataciones
 * \param limite: limite del array de contrataciones
 * \param pArrayPantalla: Array de Pantallas
 * \param limitePantalla: limite del array de pantallas
 * \nreturn Retorna 0 (EXITO) y -1 (ERROR)
 */
int informar_imprimirContratacionesConImportePorCliente(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	char listaCuit[CANTIDAD_CUIT][CUIT_LEN];
	int i;
	int indiceCuitLibre = 0;
	float auxiliarDeuda;
	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0)
	{
		cargarListaCuit(pArray,limite,listaCuit,CANTIDAD_CUIT,&indiceCuitLibre);
		for(i=0;i<indiceCuitLibre;i++)
		{
			printf("\nEl Cliente con Cuit: %s",listaCuit[i]);
			contratacion_mostrarPantallasContratadas(pArray,limite,pArrayPantalla,limitePantalla,listaCuit[i]);
			printf("\n----------------------------------------------------\n");
		}
		for(i=0;i<indiceCuitLibre;i++)
		{
			informar_calcularDeudaCliente(pArray,limite,pArrayPantalla,limitePantalla,listaCuit[i],&auxiliarDeuda);
			printf("\nEl Cliente con el Cuit: %s - debe: %.2f",listaCuit[i],auxiliarDeuda);
			printf("\n----------------------------------------------------\n");
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief: Calcula la deuda de un Cliente pasandole su cuit y devolviendo su deuda por parametro.
 * \param: pArray: Array de Contrataciones
 * \param limite: limite del array de contrataciones
 * \param pArrayPantalla: Array de Pantallas
 * \param limitePantalla: limite del array de pantallas
 * \param *cuit: cuit a ser comparado
 * \param *deuda: puntero a deuda
 * \nreturn Retorna 0 (EXITO) y -1 (ERROR)
 */
int informar_calcularDeudaCliente(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla,char* cuit,float* deuda)
{
	int retorno = -1;
	int existeCuit;
	int i;
	int buscarIndicePantalla;
	float auxImporte;
	float auxDeuda = 0;
	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0 && cuit != NULL && deuda != NULL)
	{
		existeCuit = contratacion_buscarCuit(pArray,limite,cuit);
		if(existeCuit != -1)
		{
			for(i=0;i<limite;i++)
			{
				if(strncmp(pArray[i].cuit,cuit,CUIT_LEN) == 0)
				{
					buscarIndicePantalla = pantalla_buscarId(pArrayPantalla,limitePantalla,pArray[i].idPantalla);
					if(buscarIndicePantalla != -1)
					{
						auxImporte = pArray[i].cantidadDeDias*pArrayPantalla[buscarIndicePantalla].precio;
						auxDeuda +=auxImporte;
						*deuda = auxDeuda;
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief: imprime al cliente con el mayor importe de deuda.
 * \param: pArray: Array de Contrataciones
 * \param limite: limite del array de contrataciones
 * \param pArrayPantalla: Array de Pantallas
 * \param limitePantalla: limite del array de pantallas
 * \nreturn Retorna 0 (EXITO) y -1 (ERROR)
 */
int informar_imprimirMaximoImporte(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	char listaCuit[CANTIDAD_CUIT][CUIT_LEN];
	int i;
	int indiceCuitLibre = 0;
	float auxiliarDeuda;
	int indiceMaximo = 0;
	float auxMaximo;
	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0)
	{
		cargarListaCuit(pArray,limite,listaCuit,CANTIDAD_CUIT,&indiceCuitLibre);

		for(i=0;i<indiceCuitLibre;i++)
		{
			informar_calcularDeudaCliente(pArray,limite,pArrayPantalla,limitePantalla,listaCuit[i],&auxiliarDeuda);
			if(i == 0 || auxMaximo < auxiliarDeuda)
			{
				auxMaximo = auxiliarDeuda;
				indiceMaximo = i;
			}
		}
		printf("\nCuit del cliente con maximo importe: %s\nDebe: %.2f",listaCuit[indiceMaximo],auxMaximo);
		printf("\n----------------------------------------------------\n");
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief: Carga en un array de String,los Cuits de la entidad Contratacion.
 * \param: pArray: Array de Contrataciones
 * \param limite: limite del array de contrataciones
 * \param pArrayCuit: Array de Cuits
 * \param limiteCuit: limite del array de Cuits
 * \param *indice: puntero indice donde se guardaran los cuits en el array.
 * \nreturn Retorna 0 (EXITO) y -1 (ERROR)
 */
static int cargarListaCuit(Contratacion* pArray,int limite,char pArrayCuit[][CUIT_LEN],int limiteCuit,int* indice)
{
	int retorno = -1;
	int i;
	int j;
	int flagExisteCuit;
	int indiceCuitLibre = 0;
	if(pArray != NULL && limite > 0 && pArrayCuit != NULL && limiteCuit > 0 && indice != NULL)
	{
		for(i=0;i<limite;i++)
		{
			flagExisteCuit = 0;
			if(pArray[i].isEmpty == FALSE)
			{
				for(j=0;j<indiceCuitLibre;j++)
				{
					if(strncmp(pArray[i].cuit,pArrayCuit[j],CUIT_LEN) == 0)
					{
						flagExisteCuit = 1;
						break;
					}
				}
				if(!flagExisteCuit)
				{
					//AGREGAR
					strncpy(pArrayCuit[indiceCuitLibre],pArray[i].cuit,CUIT_LEN);
					indiceCuitLibre++;
				}
			}
		}
		*indice = indiceCuitLibre;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief: Sub menu de informes.
 * \param: pArray: Array de Contrataciones
 * \param limite: limite del array de contrataciones
 * \param pArrayPantalla: Array de Pantallas
 * \param limitePantalla: limite del array de pantallas
 * \nreturn Retorna 0 (EXITO) y -1 (ERROR)
 */
int subMenu_informes(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	int subOpcion;
	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0)
	{

		if(!utn_getNumero(&subOpcion,"\n---MENU INFORMES---\n"
										  "1-Lista de cada cliente con cant. de contrataciones e importe a pagar por cada una.\n"
										  "2-Cliente con importe mas alto a facturar.\n"
										  "3-Salir.\nElija una opcion(1-3): ","\nOpcion invalida!\n",1,3,3))
		{
			switch(subOpcion)
			{
			case 1:
				printf("\nINFORME N°1\n");
				if(!informar_imprimirContratacionesConImportePorCliente(pArray,limite,pArrayPantalla,limitePantalla))
				{
					retorno = 0;
				}else
				{
					printf("\nHubo un error al imprimir los importes por cliente\n");
				}
				break;
			case 2:
				printf("\nINFORME N°2\n");
				if(!informar_imprimirMaximoImporte(pArray,limite,pArrayPantalla,limitePantalla))
				{
					retorno = 0;
				}else
				{
					printf("\nHubo un error al imprimir el importe maximo!\n");
				}
				break;
			default:
				retorno = 0;
			}
		}
	}
	return retorno;
}
