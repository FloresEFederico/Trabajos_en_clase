/*
 ============================================================================
 Name        : Clase8_DesarrolloDeFunciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int myGets(char* cadena, int longitud);
int getInt(int* pResultado);
int esNumerica(char* cadena,int limite);

int main(void) {
	setbuf(stdout,NULL);
	int numero;

	while(1){
		if(!utn_getNumero(&numero,"\nNumero: ","\nNumero invalido!",-200,200,2)){
			printf("\nNumero: %d\n",numero);
		}else{
			printf("\nERROR\n");
		}
	}
	return EXIT_SUCCESS;
}

/*
 * utn_getNumero : Solicita un numero al usuario, luego de verificarlo, devuelve el resultado
 * pResultado :puntero al espacio de memoria donde se dejara el resultado de la funcion
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = -1;
	int bufferInt;
	do{
		printf("%s",mensaje);
		if(!getInt(&bufferInt) &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
		{
			*pResultado = bufferInt;
			retorno = 0;
			break;
		}else{
			printf("%s",mensajeError);
			reintentos--;
		}
	}while(reintentos >= 0);
	return retorno;
}

/**
* getInt: Obtiene un numero entero
* pResultado: Puntero al espacio de memoria donde se dejara el resultado de la funcion
* Retorno: 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
int getInt(int* pResultado){
	int retorno = -1;
	char bufferString[50];
	if(pResultado != NULL){
		if(!myGets(bufferString,sizeof(bufferString)) &&
			esNumerica(bufferString,sizeof(bufferString)))
		{
			*pResultado = atoi(bufferString);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* myGets: Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de ' longitud - 1' caracteres .
* cadena: Puntero al espacio de memoria donde se copiara la cadena obtenida
* longitud:  Define el tamaño de cadena
* Retorno: 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
int myGets(char* cadena,int longitud){
	int retorno = -1;
	char bufferString[4096]; // EEEESSSTOOO ES UN MAMARRAACHHOOOOOOOOOOOOO
	if(cadena != NULL && longitud > 0){
		fflush(stdin); //con esto aseguras que no haya nada en el bufferString/
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strlen(bufferString) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}

	}
	return retorno;
}

/**
* esNumerica: Verifica si la cadena ingresada es numerica
* cadena: cadena de caracteres a ser analizada
* limite: limite de la cadena
* Retorno: 1 (verdadero) si la cadena es numerica , 0 (falso) si no y -1 en caso de ERROR de parametro
*
*/
int esNumerica(char* cadena,int limite){
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0){
		retorno = 1; //VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++){
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9'){
				retorno = 0; //ESTA MAL
				break;
			}
		}
	}
	return retorno;
}
