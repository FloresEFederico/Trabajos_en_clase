/*
 =================================================================================================================================================
Ejercicio 3:
Definir una funcion validarFloat()que reciba un array de
caracteres representan un numero decimal. La funcion debera
devolver si la cadena recibida contiene o no un valor numerico
en formato texto.
 =================================================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int validarFloat(char array[]);

int main(void) {
	setbuf(stdout,NULL);

	char numeros[8];

	//prueba 1 RESULTO
	//snprintf(numeros,sizeof(numeros),"%.2f",3.14); //PUEDE SER NUMERO
	//prueba 2 RESUELTO
	//snprintf(numeros,sizeof(numeros),"%d",2357); //PUEDE SER NUMERO
	//prueba 3 RESUELTO
	//snprintf(numeros,sizeof(numeros),"2.5.9"); //NO PUEDE SER NUMERO, MUCHOS PUNTOS
	//prueba 4 RESUELTO
	//snprintf(numeros,sizeof(numeros),"hola"); //NO PUEDE SER NUMERO
	snprintf(numeros,sizeof(numeros),"-4.5");
	if(validarFloat(numeros) == 1){
		printf("\nPuede ser numero. %f\n",atof(numeros));
	}else if(validarFloat(numeros) == 0){
		printf("\nNo puede ser numero\n");
	}else if(validarFloat(numeros) == -1){
		printf("\nNo puede ser numero, tiene muchos puntos\n");
	}

	return EXIT_SUCCESS;
}

static int validarFloat(char array[]){
	int retorno = 1;
	int i = 0;
	int contadorDePuntos = 0;

	if(array != NULL){
		while(array[i] != '\0'){
			if((array[i] < '0' || array[i] > '9') && array[i] != '.' &&  array[0] != '+' && array[0] != '-'){
				retorno = 0;
				break;
			}
			if(array[i] == '.'){
				contadorDePuntos++;
				if(contadorDePuntos > 1){
					retorno = -1;
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}
