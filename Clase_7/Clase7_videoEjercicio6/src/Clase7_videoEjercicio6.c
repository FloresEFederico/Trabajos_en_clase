/*
=====================================================================================================|
 Ejercicio 6:																						||
 Hacer un programa con el siguiente menu:															||
 1)Ingresar nuevo nombre (no acepta nombres repetidos)												||
 2)Listar todos																						||
 3)Ordenar por nombre																				||
 4)Borrar nombre. Se ingresa el nombre y si se encuentra se elimina de la lista						||
=====================================================================================================|
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



int main(void){
	setbuf(stdout,NULL);

	int opcion;

	do{
		printf("\nMENU------\n\n"
				"1-Ingresar nuevo nombre.\n"
				"2-Listar todos.\n"
				"3-Ordenar por nombre.\n"
				"4-Borrar nombre.(se ingresa el nombre y si se encuentra se elimina de la lista)\n"
				"5-Salir\n\n");
		if(!utn_getNumero(&opcion,"Ingrese opcion(1-5): ","\nOpcion Invalida!\n",1,5,3)){
			switch(opcion){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
		}else{
			printf("\nNo se pudo ingresar una opcion valida!\nCerrando el programa\n\n");
			break;
		}
	}while(opcion != 5);
	return EXIT_SUCCESS;
}
