/*
 ============================================================================
 Name        : Maximo_Minimo.c
 Author      : Flores Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout,NULL);
	int maximo;
	int minimo;
	int i;
	int bufferInt;//se le llama buffer porque es un area de intercambio que vamos a tener con el usuario y este es un buffer entero
	//int flag = TRUE;

	for(i=0;i<5;i++){
		printf("Ingrese Numero %d: \n",i+1);
		scanf("%d",&bufferInt);
		if(i == 0){
			maximo = bufferInt;
			minimo = bufferInt;
			//flag = FALSE;
		}else{
			if(bufferInt > maximo){
				maximo = bufferInt;
			}
			if(bufferInt < minimo){
				minimo = bufferInt;
			}
		}
	}
	printf("\nEl valor minimo es: %d y el valor maximo es: %d",minimo,maximo);
	return EXIT_SUCCESS;
}
