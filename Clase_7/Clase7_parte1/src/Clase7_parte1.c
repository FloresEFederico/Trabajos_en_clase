/*
 ============================================================================
 Name : Clase7_parte1.c

 ============================================================================
 */
///RECORDAR DE RESTARLE UNO AL SIZEOF
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
	setbuf(stdout,NULL);
	char nombre[40] = "juan";
	char nombre2[6] = "JUANA";
	int resultadoCmp;
	//Uso de strncpy:
	// strncpy(nombre,nombre2,sizeof(nombre)-1); //RECORDAR!

	//	printf("%s",nombre);

	//uso de strncmp:
	/*
	 * devuelve numeros negativos, numeros positivos o 0 si son iguales
	 *
	 * TAMBIEN ESTA |||STRNICMP||| que ignora las mayus y minus
	 */

	resultadoCmp = strnicmp(nombre,nombre2,sizeof(nombre));
	printf("\nUSO DEL STRNICMP\n:");
	if(resultadoCmp == 0){
		printf("SON IGUALES!");
	}else if(resultadoCmp > 0){
		printf("El primero es mas grande!");
	}else if(resultadoCmp < 0){
		printf("El primero es mas chico!");
	}
	printf("\n----------------\n");
	/*STRNLEN:
	 * strnlen: me permite pasar la cadena y el limite y te
	 * dice cuantos caracteres tiene adentro
	 */
	printf("\nUSO DEL STRNLEN:");
	printf("\n%d",strnlen(nombre,sizeof(nombre)));
	printf("\n----------------\n");

	/*STRNLEN:
		 * strnlen: me permite pasar la cadena y el limite y te
		 * dice cuantos caracteres tiene adentro
		 */
	printf("\nUSO DEL SPRINTF");
	sprintf(nombre,"\n%.2f hola %d - %s",2.22,10,"HOLA");
	printf("%s",nombre);


	return EXIT_SUCCESS;
}


