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
int myGets(char* cadena, int longitud);

int main(void) {
	setbuf(stdout,NULL);
	return EXIT_SUCCESS;
}


/**
* myGets: Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de ' longitud - 1' caracteres .
* cadena: Puntero al espacio de memoria donde se copiara la cadena obtenida
* longitud:  Define el tamaño de cadena
* Retorno: 1 (EXITO) si se obtiene una cadena y 0 (ERROR) si no
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
