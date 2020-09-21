/*
 * Alumno.h
 *
 *  Created on: 16 sep. 2020
 *      Author: Flores Federico
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

typedef struct
{
	//datos primitivos
	int legajo;
	char nombre[51];
	float altura;
	int isEmpty;  //Variable utilizada internamente
}Alumno;

#endif /* ALUMNO_H_ */

int imprimirArrayAlumnos(Alumno* pArray,int limite);
int initArrayAlumnos(Alumno* pArray,int limite);
