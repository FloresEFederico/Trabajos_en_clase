/*
 * utn.h
 *
 *  Created on: 3 sep. 2020
 *      Author: Flores E. Federico
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int mininimo,int maximo,int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
#endif /* UTN_H_ */
