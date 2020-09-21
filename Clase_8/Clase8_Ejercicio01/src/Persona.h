/*
 * Persona.h
 *
 *  Created on: 16 sep. 2020
 *      Author: fedef
 */

#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct{
	char nombre[51];
	char apellido[51];
	int legajo;
	int isEmpty;
}Persona;

#endif /* PERSONA_H_ */


int initArrayPersonas(Persona* pArray,int sizePer);
int buscarIndiceLibre(Persona* pArray,int sizePer);
int validarLegajoNoExistente(Persona* pArray,int sizePer,int legajoABuscar);
int imprimeArrayPersona(Persona* pArray,int sizePer);
void imprimePersona(Persona pPersona,int indice);
int buscarLegajo(Persona* pArray,int sizePer,int legajoABuscar);
int menuAgenda(int* opcion);
int altaPersona(Persona* pArray,int sizePer);
int bajaPersona(Persona* pArray,int sizePer);
int modificarPersona(Persona* pArray,int sizePer);
