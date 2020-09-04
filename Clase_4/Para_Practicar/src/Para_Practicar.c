#include <stdio.h>
#include <stdlib.h>
/*
 pedir al usuario dos numeros flotantes:

crear funcion "Calculadora"
 -funcion sumar
 -funcion restar
 -funcion multiplicar
 -funcion dividir

 si todas las funciones salieron bien, return 0
 y en caso de que hayan salido mal, return -1

 */
int getFloat(char* mensaje,char* mensajeError,int reintentos,float* operadorFloat);
int getInt(char* mensaje,char* mensajeError,int reintentos,int* operadorInt);


int main(void) {
	setbuf(stdout,NULL);

	return EXIT_SUCCESS;
}

int getFloat(char* mensaje,char* mensajeError,int reintentos,float* operadorFloat){
	int retorno = 1;
	float bufferFloat;
	int resultadoScan;
	printf("%s",mensaje);
	fflush(stdin);
	resultadoScan = scanf("%f",&bufferFloat);
	while(!(resultadoScan) && reintentos > 0){
		printf("\n--REINTENTOS: %d --\n",reintentos);
		printf("%s",mensajeError);
		fflush(stdin);
		resultadoScan = scanf("%f",&bufferFloat);
		reintentos--;
	}
	if(resultadoScan){
		*operadorFloat = bufferFloat;
		retorno = 0;
	}
	return retorno;
}

int getInt(char* mensaje,char* mensajeError,int reintentos,int* operadorInt){
	int retorno = 1;
	int bufferInt;
	int resultadoScan;
	printf("%s",mensaje);
	fflush(stdin);
	resultadoScan = scanf("%d",&bufferInt);
	while(!(resultadoScan) && reintentos > 0){
		printf("\n--REINTENTOS: %d --\n",reintentos);
		printf("%s",mensajeError);
		fflush(stdin);
		resultadoScan = scanf("%d",&bufferInt);
		reintentos--;
	}
	if(resultadoScan){
		*operadorInt = bufferInt;
		retorno = 0;
	}
	return retorno;
}
