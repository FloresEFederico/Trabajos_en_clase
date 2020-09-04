/*
 ============================================================================
 TAREA: HACER ESTA DOS FUNCIONES:
 -utn_getNumeroFloat(): para un float.
 -utn_getCaracter(): para un caracter.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "homework.h"

int main(void) {
	setbuf(stdout,NULL);
	int edad;
	float peso;
	char letra;

	if(!utn_getInt(&edad,"\nEdad? ","\nEdad invalida!\n",5,100,3)){
		printf("\nTodo Ok\n");
		if(!utn_getFloat(&peso,"\nPeso? ","\nPeso invalida!\n",36,200,3)){
			printf("\nPERFECTO\n");
			if(!utn_getChar(&letra,"\nIngrese letra ('a' -'z')","\nLetra invalida! tiene que ser de la 'a' a la 'z'",'a','z',5)){
				printf("\nTODO ALUCINANTE!!!!\n\n");
				printf("\nEdad: %d",edad);
				printf("\nPeso: %.2f",peso);
				printf("\nLetra: %c",letra);
			}else{
				printf("\nNo se pudo ingresar una letra\n");
			}
		}else{
			printf("\nNo se pudo ingresar el peso\n");
		}
	}else{
		printf("\nNo se pudo ingresar la edad\n");
	}

	return EXIT_SUCCESS;
}
