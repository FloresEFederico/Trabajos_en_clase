/*
 Pedir numeros hasta que el USUARIO quiera (888) y dar como resultado maximo y minimo
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout,NULL);
	int maximo;
	int minimo;
	int bufferInt;
	int flag = TRUE;
	do{
		printf("Ingrese un numero(Ingrese 888 si quiere romper la iteracion): ");
		scanf("%d",&bufferInt);
		if(flag == TRUE){
			maximo = bufferInt;
			minimo = bufferInt;
			flag = FALSE;
		}else{
			if(bufferInt == 888){
				break;
			}else{
				if(bufferInt > maximo){
					maximo = bufferInt;
				}
				if(bufferInt < minimo){
					minimo = bufferInt;
				}
			}

		}
	}while(TRUE);
	printf("\nEl minimo es: %d\nEl maximo es: %d\n\n",minimo,maximo);

	return EXIT_SUCCESS;
}
