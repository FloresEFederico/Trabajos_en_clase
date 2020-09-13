/*
 ============================================================================
Ejercicio 2:
Crear un programa que permita registrar el valor de la temperatura maxima de cada dia de un mes
Definir un array de floats de 31 posiciones. Cada posicion correspondera a un dia del mes.
Hacer un programa con un menu de dos opciones.
1- imprimir array
		y
2- cargar array

Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
Ambas opciones deben volver al menu principal.
Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 ============================================================================
 */
		//				FALTAN HACER LOS EJERCICIOS 3 y 4
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_MESES 31

int main(void) {
	setbuf(stdout,NULL);

	float temperaturas[CANTIDAD_MESES];
	int opcion;
	int i;

	for(i=0;i<CANTIDAD_MESES;i++){
		temperaturas[i] = 0;
	}
	do{
		printf("MENU DE TEMPERATURA:\n1-Imprimir los dias del mes.\n2-Cargar algun dia del mes\n3-Salir.\n*");
		if(!utn_getNumero(&opcion,"Elija una opcion(1-3): ","\nOpcion ingresada invalida!\n",1,3,3)){
			switch(opcion){
			case 1:
				imprimirArrayCantidadDeDias(temperaturas,CANTIDAD_MESES);
				getchar();
				break;
			case 2:
				if(!utn_getNumero(&i,"\nIngrese un numero de dia(1-31): ","\nNumero invalido!\n",1,31,3)){
					printf("\nDia seleccionado fue: %d,",i);
					i--;
					printf(" se colocara en el indice: %d,",i);

					if(!utn_getNumeroFloat(&temperaturas[i],"\nIngrese el valor de temperatura(5-30): ","\nTemperatura invalida!\n",5,30,3)){
						printf("\nSe ingreso la temperatura satisfactoriamente!\nPresione enter para continuar...\n");
						getchar();

					}else{
						printf("\nSe acabo el numero de intentos para ingresar la temperatura\n");
					}
				}else{
					printf("\nSe acabo el numero de intentos para ingresar el numero de dia\n");
				}
				break;
			}
		}else{
			printf("\nHubo un error al elegir la opcion.\n");
		}
	}while(opcion != 3);


	return EXIT_SUCCESS;
}

