/*
 ============================================================================
 Name        : Burbujeos_Insertion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_ELEMENTOS 5

void imprimirArray(int array[],int lengitud);
void burbujeoMalo(int array[],int len);
void bubbleSort(int array[],int len);
void insertion(int array[],int len);

int main(void) {
	setbuf(stdout,NULL);

	int vec[QTY_ELEMENTOS] ={26,43,88,2,46};
	printf("\n--ANTES DE LA FUNCION--\n");
	imprimirArray(vec,QTY_ELEMENTOS);
	printf("\n--DESPUES DE LA FUNCION--\n");
	insertion(vec,QTY_ELEMENTOS);
	imprimirArray(vec,QTY_ELEMENTOS);

	return EXIT_SUCCESS;
}


void imprimirArray(int array[],int lengitud){
	int i;
	for(i=0;i<lengitud;i++){
		printf("POSICION: %d  - VALOR: %d \n",i,array[i]);
	}

}

//AUN MENOS EFICIENTE
void burbujeoMalo(int array[],int len){
	int i;
	int j;
	int bufferAuxiliar;

	for(i=0;i<len-1;i++){
		for(j=i+1;i<len;j++){
			bufferAuxiliar = array[i];
			array[i] = array[j];
			array[j] = bufferAuxiliar;
		}
	}
}
//MENOS EFICIENTE
void bubbleSort(int array[],int len){
	int i;
	int bufferAuxiliar;
	int flagNoEstaOrdenado = 1;

	while(flagNoEstaOrdenado){
		flagNoEstaOrdenado = 0;
		for(i=1;i<len;i++){
			if(array[i] < array[i-1]){
				bufferAuxiliar = array[i];
				array[i] = array[i-1];
				array[i-1] = bufferAuxiliar;
				flagNoEstaOrdenado = 1;
			}
		}
	}
}

//MAYOR EFICIENCIA FUNCION: insertion
void insertion(int array[],int len){
	int i;
	int j;
	int temp;
	for(i=1;i<len;i++){
		temp = array[i];
		j = i - 1;
		while(j >= 0 && temp < array[j]){ 	// temp<array[j] o temp>array[j]
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp; //insercion
	}
}
