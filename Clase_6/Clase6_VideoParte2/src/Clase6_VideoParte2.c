/*
 ============================================================================
 	 	 	 	 	 DESARROLLO DE UN MENU
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcionMenu;
	int respuesta;
	int flagError = 0;

	do{
		respuesta = utn_getNumero(&opcionMenu,"Seleccione una opcion\n\n1-Leer.\n2-Mostrar.\n3-Salir.\nElija opcion: ","\nNo es una opcion valida\n",1,3,3);
		if(!respuesta){
			switch(opcionMenu){
			case 1:
				printf("\nEntre al caso 1: Leer\n");
				break;
			case 2:
				printf("\nEntre al caso 2: Mostrar\n");
				break;
			default:
				printf("\nGoo baa!\n");
				break;
			}
		}else{
			printf("\nHubo un error al ingresar una opcion\n");
			flagError = 1;
			break;
		}
	}while(opcionMenu != 3);
	if(flagError){
		printf("\nSi llegaste aca, es porque ingresaste todas las opciones mal\n");
	}

	return EXIT_SUCCESS;
}
