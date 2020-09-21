/*
 ============================================================================
5) Hacer una funcion que reciba el array del punto 4,
	y verifique que las letras dentro del mismo esten en el rango de 'a' a 'z'
	o de 'A' a 'Z'.
 	Si estan dentro del rango la funcion deberá devolver por valor
 	(usando el return) un 0, de lo contrario devolverá -1.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_LETRAS 8

int esLetra(char* pArray);

int main(void) {
	setbuf(stdout,NULL);
	char nombre[QTY_LETRAS]={'p','e','p','e','1','2','3','\0'};

	if(!esLetra(nombre)){
		printf("\nEstan en rango!\n");
	}else{
		printf("\nNo estan en rango!\n");
	}

	return EXIT_SUCCESS;
}

int esLetra(char* pArray){
	int retorno = 0;
	int i;
	if(pArray != NULL){
		for(i=0;pArray[i] != '\0';i++){
			if((pArray[i] < 'A' || pArray[i] > 'Z') // estoy fuera del rango?
								&& 							//Y ADEMAS!!
			   (pArray[i] < 'a' || pArray[i] > 'z') // estoy fuera de este?
			   ){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}
