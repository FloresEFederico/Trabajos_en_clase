/*
============================================================================
				|¡CADENA DE CARACTERES!|
Cadena de caracteres: es un array de caracteres
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

void imprimirTexto(char array[]);

int main(void) {
	setbuf(stdout,NULL);
	char texto[8]; // cadena de caracteres (array de chars)

	texto[0] = 'F';
	texto[1] = 'l';
	texto[2] = 'a';
	texto[3] = 'c';
	texto[4] = 'o';
	texto[5] = 0;

	imprimirTexto(texto);
	texto[0] = 'H';
	texto[1] = 'A';
	texto[2] = '!';
	texto[3] = 0;
	imprimirTexto(texto);

	return EXIT_SUCCESS;
}

void imprimirTexto(char array[]){
	int i = 0;
	while(array[i] != 0){
		printf("%c",array[i]);
		i++;
	}
}
