/*
 * utn.h
 *
 *  Created on: 3 sep. 2020
 *      Author: Flores E. Federico
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int mininimo,int maximo,int reintentos);
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
#endif /* UTN_H_ */
