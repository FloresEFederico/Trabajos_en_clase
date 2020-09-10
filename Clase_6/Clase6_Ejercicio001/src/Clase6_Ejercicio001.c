/*
========================================================================================================================================
Agregar a la biblioteca utn.h funciones para obtener y validar diferentes tipos de valores:

- Solo números, ej. 123436679
- Solo letras, ej. abBD
- Alfanumericos, ej. ab555gT6
- Teléfonos, ej. 4XXX-XXXX

Realizar un programa que pida al usuario el ingreso de un dato y determine con cuales de los tipos cumple.
========================================================================================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



int main(void) {
	setbuf(stdout,NULL);
	char numeroDeTelefono[] = "-ad43050518";

	if(esTelefono(numeroDeTelefono)){
		printf("%s",numeroDeTelefono);
	}else{
		printf("\nNop\n");
	}

	return EXIT_SUCCESS;
}




