/*
 ============================================================================
6) Realizar un programa para probar la funcion del punto 5,
permitiendo que el usuario ingrese un texto y
 luego validando si lo ingresado es un nombre válido.
 Usar scanf para tomar el texto.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_LETRAS 30

int esLetra(char* pArray);

int main(void) {
	setbuf(stdout,NULL);
	char texto[QTY_LETRAS];

	while(1){
		printf("\nIngrese un texto: ");
		fflush(stdin);
		scanf("%s",texto);
		if(!esLetra(texto)){
			printf("\nEstan en rango!\n");
		}else{
			printf("\nNo estan en rango!\n");
		}
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
//				\(ouo)
