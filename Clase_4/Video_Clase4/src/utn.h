/*
 * utn.h
 *
 *  Created on: 3 sep. 2020
 *      Author: fedef
 */

#ifndef UTN_H_
#define UTN_H_

int dividir(float* pResultado,int num1,int num2);

//--------------------segunda parte del video: funcion utn_getNumero utn_getFloat utn_getChar-------------
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

//------------------------------------------------------------------------------------
#endif /* UTN_H_ */
