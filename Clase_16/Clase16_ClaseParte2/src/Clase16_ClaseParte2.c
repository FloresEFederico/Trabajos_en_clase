/*
 ============================================================================
 Name        : Clase16_ClaseParte2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int* crearArrayInt(int cantidad, int valorInit);

int* resizeArrayInt(int cantidad,int* pArrayARidimencionar);
int main(void) {
	setbuf(stdout,NULL);
	/*int* pEdad = NULL;
	int* pArrayEdad = NULL;
	int sizeArrayEdades = 100;
	int i;
	int* pAuxArrayEdad = NULL;

	pEdad = (int*)malloc(sizeof(int));
	pArrayEdad = (int*)malloc(sizeof(int)*sizeArrayEdades);
	if(pEdad != NULL && pArrayEdad != NULL)
	{
		*pEdad = 24;
		for(i=0;i < sizeArrayEdades;i++)
		{
			*(pArrayEdad + i) = 0;
		}
	}else
	{
		printf("\nError\n");
	}
	sizeArrayEdades = 200;
	pAuxArrayEdad = (int*)realloc(pArrayEdad,sizeof(int)*sizeArrayEdades);
	if(pAuxArrayEdad != NULL)
	{
		pArrayEdad = pAuxArrayEdad;
		pAuxArrayEdad = NULL;
		for(i=0;i < sizeArrayEdades;i++)
		{
			*(pArrayEdad + i) = 0;
		}
	}else
	{
		//Informar el error
		printf("\nError\n");
	}

	free(pArrayEdad); //Si yo no hago esto, me quedo ocupando memoria dinamica
	*/
	int* pArray = NULL;
	int sizeArray = 500;
	pArray = crearArrayInt(sizeArray,-1);
	if(pArray != NULL)
	{
		//lo uso
	}else
	{
		//error
	}
	pArray = resizeArrayInt(600,pArray);

	free(pArray);
	return EXIT_SUCCESS;
}

int* crearArrayInt(int cantidad, int valorInit)
{
	int* pArray= NULL;
	int i;
	pArray = (int*)malloc(sizeof(int)*cantidad);
	if(pArray != NULL)
	{
		for(i=0;i < cantidad;i++)
		{
			*(pArray + i) = valorInit;
		}
	}
	return pArray;
}

int* resizeArrayInt(int cantidad,int* pArrayARidimencionar)
{
	int* pArrayAux= NULL;
	int i;
	pArrayAux = (int*)realloc(pArrayARidimencionar,sizeof(int)*cantidad);
	return pArrayAux;
}
