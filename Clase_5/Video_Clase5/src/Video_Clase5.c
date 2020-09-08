/*
============================================================================
							   |ARRAY|
								------
-Arrays: un array es un espacio de memoria donde habra valores
y tiene ciertas caracteristicas:
permite guardar espacio para varias variables en una con
el mismo nombre.

-indices de array: Son la posicion de donde comienza el array
y se empieza desde el 0. La sintaxis para los indices son
los corchetes [] y dentro el numero a la posicion que yo
quiero.

Funciones estaticas(static function): Si se le pone 'static' adelante de una
funcion, va a queda privada del archivo y fuera del archivo no se
puede usar.
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	/*int numeros[7]; // [7] que hay 7 lugares para darle valor a este array
	//quiero escribir un numero cinco en todas las posiciones
	    en vez de hacer esto, yo lo que puedo utilizar es
	 	 una variable (i) utilizando un bucle
	 	 para ir agregandole ese 5 a cada lugar
	numeros[0] = 5;
	numeros[1] = 5;
	numeros[2] = 5;
	numeros[3] = 5;
	numeros[4] = 5;
	numeros[5] = 5;
	numeros[6] = 5;
	----------------------------------------------------------
	Ejemplo 1:
	int x;
	x = 0;
	do{
		numeros[x] = 5;
		x++;
	}while(x < 7);
	Este bucle (mejor hacerlo con for) sirve para cargarle
	todos los valores de 5 al array 'numeros' gracias a que
	puedo utilizar a la variable 'x' y hacerla incrementar
	hasta el ultimo lugar de espacio de la variable numeros*/
//------------------------------------------------------------
	/*Ejemplo 2:
	 * genralmente usamos la variable 'i' como indice
	   haremos el mismo codigo pero con for

	int i;
	for(i=0;i<7;i++){
		numeros[i] = 5;
	}*/
//-------------------------------------------------------------------
/*EJERCICIO:
 Pedirle al usuario 5 edades y LUEGO imprimir las 5 edades. Definir un array de 5 posiciones
 y usar la funcion utn_getNumero() para pedir los valores
*/

	int edades[5];
	int i;
	for(i=0;i<5;i++){
		if(!utn_getNumero(&edades[i],"\nIngrese una edad: ","\nEdad invalida!\n",1,100,5)){

		}else{
			printf("\nHubo un error al ingresar la edad!\n");
			break;
		}
	}
	if(i == 5){
		for(i=0;i<5;i++){
			printf("\nEdad n°%d : %d\n",i+1,edades[i]);
		}
	}else{
		printf("\nNo se pudo cargar todas las edades\n");
	}
	return EXIT_SUCCESS;
}
