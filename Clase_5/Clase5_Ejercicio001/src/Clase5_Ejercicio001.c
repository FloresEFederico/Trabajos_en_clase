/*
 =============================================================================================================================
 Ejercicio: Solicitar al usuario 5 números, almacenar estos en un array de enteros,  permitir
 listarlos por pantalla indicando el máximo, el mínimo y el promedio.
 Permitir Modificar el valor de cualquiera de los números cargados indicando el índice del mismo y
 su nuevo valor.
 =============================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_ELEMENTOS 5



int main(void) {
	setbuf(stdout,NULL);
	int numeros[QTY_ELEMENTOS];
	int i;
	int indice;
	int flag = 0;
	int maximo;
	int minimo;
	int acumulador = 0;
	float promedio;
	char modificar;
	int bufferAux;

	for(i=0;i<QTY_ELEMENTOS;i++){
		numeros[i] = 0;
	}

	for(i=0;i<QTY_ELEMENTOS;i++){

		printf("\nIndice: %d\n",i);
		if(!utn_getNumero(&numeros[i],"\nIngrese numero(0-100): ","\nNumero invalido!\n",0,100,3)){
			if(!flag){
				maximo = numeros[i];
				minimo = numeros[i];
				flag = 1;
			}
			if(maximo < numeros[i]){
				maximo = numeros[i];
			}
			if(minimo > numeros[i]){
				minimo = numeros[i];
			}
		}else{
			printf("\nHubo un error al cargar el numero!\n");
		}
	}
	imprimirArray(numeros,QTY_ELEMENTOS);

	do{
		if(!utn_getCaracter(&modificar,"\nDesea modificar algun numero?(s/n): ","\nLetra invalida!\n",'n','s',5)){
			if(modificar == 's'){
				if(!utn_getNumero(&indice,"\nIngrese el indice que desea modificar(0-4): ","\nindice invalido!\n",0,4,3)){
					printf("\nINDICE: %d  -  VALOR: %d \n",indice,numeros[indice]);
					if(!utn_getNumero(&bufferAux,"\nPor cual valor lo desea cambiar: ","\nValor invalido!\n",0,100,3)){
						numeros[indice] = bufferAux;
						printf("\nModificacion Realizada! Se ha cambiado el valor del numero.\n");
						if(maximo < numeros[indice]){
							maximo = numeros[indice];
							printf("\nha habido un cambio en el maximo!\n");
						}
						if(minimo > numeros[indice]){
							minimo = numeros[indice];
							printf("\nha habido un cambio en el minimo!\n");
						}
					}else{
						printf("\nNo se pudo modificar el numero!");
					}
				}
			}
		}else{
			printf("\nHubo un error al elegir la letra!\n");
		}
	}while(modificar == 's');
	for(i=0;i<QTY_ELEMENTOS;i++){
		acumulador+=numeros[i];
	}
	promedio = (float)acumulador/QTY_ELEMENTOS;
	imprimirArray(numeros,QTY_ELEMENTOS);
	printf("\n\n------------------------------------------------------------\n\n");
	printf("MAXIMO: %d\n"
			"MINIMO: %d\n"
			"PROMEDIO: %.2f",maximo,minimo,promedio);
	return EXIT_SUCCESS;
}


