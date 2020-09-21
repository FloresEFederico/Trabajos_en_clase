/*
==================================================================================
|							   /_____________\									 |
|		 					   \_____________/									 |
|		  					   /|ESTRUCTURAS|\									 |
|							   \|||||||||||||/									 |
|							   /_____________\									 |
|							   \             /									 |
==================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"
#define QTY_ALUMNOS 5



int main(void){
	setbuf(stdout,NULL);

	//Creacion de un alumno
	Alumno auxiliar;

	//Creacion de un array de alumnos
	Alumno arrayAlumnos[QTY_ALUMNOS];

	initArrayAlumnos(arrayAlumnos,QTY_ALUMNOS); // Inicializacion del array[].isEmpty

	//Otorgamos valores a un auxiliar de alumno
	auxiliar.altura = 2.04;
	auxiliar.legajo = 25;
	strncpy(auxiliar.nombre,"FEDERICO",sizeof(auxiliar.nombre));
	auxiliar.isEmpty = 0;//aca le indicamos que este lugar del array no esta vacio

	//copiamos sencillamente al array todo los valores ingresados en el auxiliar
	arrayAlumnos[2] = auxiliar;

	//Imprimimos solo los arrays que esten ocupados.
	imprimirArrayAlumnos(arrayAlumnos,QTY_ALUMNOS);

	return EXIT_SUCCESS;
}
