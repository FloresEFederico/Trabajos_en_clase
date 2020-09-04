/*
 ============================================================================
 Name        : Clase_4.c
 Author      : Flores Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
//---------------------Primera parte prototipos:------------------
void otraFuncion(int* puntero);
//----------------------------------------------------------------


//---------------------Segunda parte prototipos:------------------
//------------------------FIJARSE EL ARCHIVO utn.h-----------------
//-----------------------------------------------------------------


int main(void) {
	setbuf(stdout,NULL);
//---------------------PRIMERA PARTE DE LA CLASE(antes del recreo)-----------------------------------------------
	// '&' : la direccion de mem. de la variable que tiene a la derecha.
	// int* b: indico que la variable va a guardar direcciones de mem.
	// mascara %u : es para mostrar la direccion de memoria en decimal sin signo
	// '*' : accedo a la direccion y leo o escribo
	// *puntero = valor; Escribir
	// variable = *puntero; Leer
/*
	int a = 55;
	int* b;

	b = &a;
	printf("direccion de a: %u\n",b);

	otraFuncion(b); // le paso el puntero de a, que es b
	printf("valor de a: %d",a); //aca tendria que dar 8
*/
//----------------------------------------------------------------------------------------------------------------
//---------------------SEGUNDA PARTE DE LA CLASE(despues del recreo)-----------------------------------------------

	int edad;
	//en la guia llgamos hasta el 2.1 de la guia apunte impus v1.3
	if(!utn_getInt(&edad,"Ingrese edad: ","\nERROR!\n",0,100,3))
	{
		printf("ingresaste edad: %d",edad);
	}else{
		printf("Todo mal loco");
	}

	return EXIT_SUCCESS;
}


//---------------------Primera parte desarrollos:------------------
void otraFuncion(int* puntero){
	*puntero = 8;
}
//-----------------------------------------------------------------


//---------------------Segunda parte desarrollos:------------------
//------------------------FIJARSE EL ARCHIVO utn.c-----------------

//-----------------------------------------------------------------
	//en la guia llgamos hasta el 2.1
