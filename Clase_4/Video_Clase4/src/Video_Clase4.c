/*
 ============================================================================
 Name        : Video_Clase4.c
 Author      : Flores E. Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void) {
	setbuf(stdout,NULL);

	/*ESTO DE LA PRIMER VIDEO
	float resultado;
	int numero1;
	int numero2;
	int respuesta;

	printf("\nIngrese numero 1: ");
	scanf("%d",&numero1);
	printf("\nIngrese numero 2: ");
	scanf("%d",&numero2);
	respuesta = dividir(&resultado,numero1,numero2);
	if(!respuesta){
		printf("\nPudo dividir!\n La division es igual a: %.2f", resultado);
	}else{
		printf("\nNo es posible dividir por 0!");
	}*/

	//SEGUNDO VIDEO--FUNCION utn_getNumero()------

	int edad;
	int peso;
	int respuesta;

	//para edad-------
	respuesta = utn_getNumero(&edad,"\nIngrese la edad: ","\nError, Tiene que ser dentro de 0 y 199\n ",0,199,2);
	if(respuesta == 0){
		printf("La edad es: %d", edad);
	}else{
		printf("\nError!!\n");
	}

	//para el peso-----
	respuesta = utn_getNumero(&peso,"\npeso?: ","\nError, desde 0 a 500",0,500,3);
	if(respuesta == 0){
		printf("El peso es: %d", peso);
	}else{
		printf("\nError!!\n");
	}
	return EXIT_SUCCESS;
}


