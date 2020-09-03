/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: fedef
 */
#include <stdio.h>
#include <stdlib.h>

int dividir(float* pResultado,int num1,int num2)
{
	float resultado;
	int retorno = -1;
	if(pResultado != NULL && num2 != 0){
		resultado = (float)num1/num2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}
