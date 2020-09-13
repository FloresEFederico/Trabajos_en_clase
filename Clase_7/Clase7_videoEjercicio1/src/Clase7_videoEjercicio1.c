/*
 ============================================================================
Ejercicio 1:
Escribir la funcion calcularMayor(). La funcion debe recibir dos numeros int
y devolver por referencia, el numero mayor.
La funcion debe retornar un 1 si encontro mayor, o un 0 si ambos numeros
son iguales
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int calcularMayor(int* pResultado,int n1,int n2);

int main(void) {
	setbuf(stdout,NULL);
	int resultado;
	int num1;
	int num2;
	int mayor;
	if(!utn_getNumero(&num1,"\nIngrese primer numero(0-100): ","\nNumero invalido!\n",0,100,3) &&
	   !utn_getNumero(&num2,"\nIngrese segundo numero(0-100): ","\nNumero invalido!\n",0,100,3)){
		mayor = calcularMayor(&resultado,num1,num2);
		if(mayor == 0){
			printf("\nLos numeros son iguales\n");
		}else if(mayor == 1){
			printf("\nEl mayor es: %d\n",resultado);
		}else{
			printf("\nHubo un error\n");
		}
	}else{
		printf("\nHubo un error al ingresar el numero!\n");
	}
	return EXIT_SUCCESS;
}

int calcularMayor(int* pResultado,int n1,int n2){
	int retorno = -1;

	if(pResultado != NULL){
		if(n1 == n2){
			retorno = 0;
		}else if(n1 > n2){
			*pResultado = n1;
			retorno = 1;
		}else{
			*pResultado = n2;
			retorno = 1;
		}
	}
	return retorno;
}
