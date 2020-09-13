/*
 =================================================================================================================================================
Ejercicio 4:
Completar la funcion getFloat() para que devuelva un numero float
ingresado por el usuario.
 =================================================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


static int isFloat(char array[]);
static int getFloat(float* pResultado);

int main(void) {
	setbuf(stdout,NULL);

	float precio;

	printf("\nIngrese precio: ");
	if(getFloat(&precio)){
		printf("\nEl precio es valido: %.2f",precio);
	}else{
		printf("\nNo es un float\n");
	}
	return EXIT_SUCCESS;
}

static int isFloat(char array[]){
	int retorno = 1;
	int i = 0;
	int contadorDePuntos = 0;

	if(array != NULL){
		while(array[i] != '\0'){
			if((array[i] < '0' || array[i] > '9') && array[i] != '.' &&  array[0] != '+' && array[0] != '-'){
				retorno = 0;
				break;
			}
			if(array[i] == '.'){
				contadorDePuntos++;
				if(contadorDePuntos > 1){
					retorno = -1;
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}


static int getFloat(float* pResultado){
	int retorno = 0;
	char buffer[128];
	if(pResultado != NULL){
		fflush(stdin);
		fgets(buffer,sizeof(buffer),stdin);
		if(buffer[strlen(buffer)-1] == '\n'){
			buffer[strlen(buffer)-1] = '\0';
		}
		if(isFloat(buffer) == 1){
			*pResultado = atof(buffer);
			retorno = 1;
		}
	}
	return retorno;
}
