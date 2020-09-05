/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: fedef
 */
#include <stdio.h>
#include <stdlib.h>

int dividir(float* pResultado,int num1,int num2)
{
	float resultado;
	int retorno = -1;
	if(pResultado != NULL && num2 != 0){
		resultado = (float)num1/num2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;
	int respuestaScan;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			respuestaScan = scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}else{
				printf("\n-REINTENTOS: %d\n",reintentos);
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(respuestaScan == 0 || reintentos >= 0);

	}
		return retorno;
}


int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = -1;
	float bufferFloat;
	int resultadoScan;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScan = scanf("%f",&bufferFloat);
			if(resultadoScan == 1 && bufferFloat >= minimo && bufferFloat < maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}else{
				printf("\n-REINTENTOS : %d\n",reintentos);
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = -1;
	char bufferChar;
	int resultadoScan;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScan = scanf("%c",&bufferChar);
			if(resultadoScan == 1 && bufferChar >= minimo && bufferChar <= maximo){
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}else{
				printf("\n-REINTENTOS : %d\n",reintentos);
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
