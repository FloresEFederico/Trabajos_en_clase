/*
 ============================================================================
Ejercicio 7) hacer lo del ejercicio 6 pero sin scanf, sino fgets.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#define QTY_LETRAS 10

int esLetra(char* pArray);

int main(void) {
	setbuf(stdout,NULL);
	char texto[QTY_LETRAS];

	while(1){
		printf("\nIngrese un texto: ");
		fflush(stdin);
		fgets(texto,sizeof(texto),stdin);
		if(texto[strlen(texto)-1] == '\n'){
			texto[strlen(texto)-1] = '\0';
		}
		if(!esLetra(texto)){
			printf("\nEstan en rango!\n");
			printf("\nTexto: %s",texto);
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
