/*
========================================================================================================================================================
 arrayInt = una variable que es un conjunto de variables

 carga secuencial = va cargando datos secuencialmente, osea de 0 a 100.
 carga aleatorio = lo dice el nombre, pidiendole al usuario que ponga indice, fijarse si ese indice existe, y eso.
========================================================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculosArray.h"
#include "utn.h"
#define CANTIDAD_ELEMENTOS 4 // define es una sentencia de precompilador


int main(void) {
	setbuf(stdout,NULL);
/* PEDIR 5 arrayInt:
 * -hacer un switch con distintas opciones:
 * op1 - calcular maximo
 * op2 - calcular promedio
 * op2 - calcular minimo
 */
	int variableInt;
	int arrayInt[CANTIDAD_ELEMENTOS];
	int i;
	int flagCargaCorrecta = 0;
	int maximo;
	int minimo;
	float probabilidad;
	char seguir;
	int opcion;

	for(i=0;i<CANTIDAD_ELEMENTOS;i++){
		printf("Indice %d: \n",i);
		if(!utn_getNumero(&variableInt,"Ingrese el numero: ","\nNumero invalido!\n",0,100,3)){
			arrayInt[i] = variableInt;
		}else{
			printf("\nGAME OVER\n");
			flagCargaCorrecta = -1;
			break;
		}
	}
	if(flagCargaCorrecta == 0){
		do{
			if(!utn_getNumero(&opcion,"\nMenu opciones:\n1-Calcular Maximo.\n2-Calcular Minimo.\n3-Calcular Promedio.\n4-Salir.","\nOpcion Invalida!\n",1,4,5)){
				switch(opcion){
				case 1:
					if(!calcularMaximo(arrayInt,CANTIDAD_ELEMENTOS,&maximo)){
						printf("\nEl maximo es: %d",maximo);
					}else{
						printf("\nError");
					}
					break;
				case 2:
					if(!calcularMinimo(arrayInt,CANTIDAD_ELEMENTOS,&minimo)){
						printf("\nEl minimo es: %d",minimo);
					}else{
						printf("\nError");
					}
					break;
				case 3:
					if(!calcularProbabilidad(arrayInt,CANTIDAD_ELEMENTOS,&probabilidad)){
						printf("\nLa probabilidad es: %.2f",probabilidad);
					}else{
						printf("\nError");
					}
					break;
				}
			}
			if(utn_getCaracter(&seguir,"\nDesea continuar?(s/n): ","\nLetra invalida!\n",'n','s',3)){
				printf("\nError! Cerrando programa\n");
			}
		}while(seguir == 's');

		printf("\nHasta Luego!\n");

	}
	return EXIT_SUCCESS;
}
