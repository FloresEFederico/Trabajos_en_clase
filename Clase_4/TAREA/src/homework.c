/*
 * homework.c
 *
 *  Created on: 4 sep. 2020
 *      Author: Flores E. Federico
 */
#include <stdio.h>
#include <stdlib.h>


int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = -1;
	int bufferInt;
	int resultadoScan;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScan = scanf("%d",&bufferInt);
			if(resultadoScan == 1 && bufferInt >= minimo && bufferInt < maximo){
				*pResultado = bufferInt;
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

