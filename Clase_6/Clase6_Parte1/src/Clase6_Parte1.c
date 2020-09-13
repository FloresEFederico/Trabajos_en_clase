/*
============================================================================
1) agregarle al codigo del martes (usuario que ingresa numeros y se guarda en array)
la funcion de ordenar
2) hacer la funcion para imprimir el array
3) imprimir el array antes de ordenar y despues.
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "calculosArray.h"
#define CANTIDAD_ELEMENTOS 8

int ordenar(int array[],int len);

int main(void) {
	setbuf(stdout,NULL);

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
			if(!utn_getNumero(&opcion,"\nMenu opciones:\n"
					"1-Calcular Maximo.\n"
					"2-Calcular Minimo.\n"
					"3-Calcular Promedio.\n"
					"4-Salir.\nElija opcion: ","\nOpcion Invalida!\n",1,4,5)){
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
			if(opcion != 4){
				if(utn_getCaracter(&seguir,"\nDesea continuar?(s/n): ","\nLetra invalida!\n",'n','s',3)){
					printf("\nError! Cerrando programa\n");
				}
			}
		}while(seguir == 's' && opcion != 4);
		printf("\n-------------------------------\n");
		printf("Numeros antes de ser ordenados!\n");
		imprimirArray(arrayInt,CANTIDAD_ELEMENTOS);
		printf("\n-------------------------------\n");
		printf("Numeros ordenados!!\n");
		ordenar(arrayInt,CANTIDAD_ELEMENTOS);
		imprimirArray(arrayInt,CANTIDAD_ELEMENTOS);
	}

	return EXIT_SUCCESS;
}

int ordenar(int array[],int len){
	int retorno = -1;
	int aux;
	int indice;
	int flagEstaOrdenado = 1;

	if(array != NULL && len > 0){
		while(flagEstaOrdenado){
			flagEstaOrdenado = 0;
			for(indice=0;indice < (len-1);indice++){
				if(array[indice] > array[indice+1]){
					aux = array[indice];
					array[indice] = array[indice+1];
					array[indice+1] = aux;
					flagEstaOrdenado = 1;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
