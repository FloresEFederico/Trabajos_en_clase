/*
 ============================================================================
 Name        : Clase10_Parte1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//RECORDAR QUE PARA EL TP2 USAR DENTRO DE LA FUNCION ALTA LA FUNCION ESA QUE APARECE ADD del tp2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"
#include "nac.h"

/*
*Ejercicio 7) Realizar un programa con un menu de dos opciones:
*	a) Alta de alumno. - NO PEDIR INCIDE-
*	b) Imprimir lista alumnos
*
*Ejercicio 8) Agregar al tipo de dato el campo ID que represente
*un identificador unico. Modificar el codigo anterior para que
* el ID se genere automaticamente. Se debera cargar el ID
* automaticamente al cargar un alumno, y se debera imprimir
*	al imprimir la lista.
*/


/*
 * cada vez que la llamo me devuelve un ID nuevo
 * que nunca me devolvio antes
 *
 * opcion 1: definir id en el main y pasarla por referencia a la funcion de alta
 * La funcion debe usar el valor que tiene e incrementarlo.
 *
 * Opcion 2: static int id.
 * Declarar en el archivo alumno.c (variable global del archivo)
 *
 * Opcion 3: static int id dentro de la funcion:
 * Es lo mismo que definirla globalmente, pero como la defini dentro
 * de la funcion, solo la funcion esa puede verla y usarla
 *
 * fijarse en Alumno.c que ahi hice la funcion static int generar id
 *
 *
 * 9) Realizar una funcion que reciba el array y un ID, y
 *  me devuelva el indice del item con dicho ID. (buscar por id)
 *
 *  ////////////////////////////TAREA///////////////////////////////
 *  10) Realizar una funcion que reciba el array, un indice, y
 *   le permita al usuario modificar los campos nombre y
 *   legajo del item del array en la posicion especificada por el indice.
 *
 *	11) Agregar una opcion en el menu. "Editar alumno"
 *		 que pida al usuario el ID del mismo  y
 *	 	le permita cambiar el nombre y el legajo.
 *
 *
 *  12) Agregar una opcion en el menu "Borrar Alumno"
 *  	 que pida al usuario el ID del mismo.
 *  --------------------------------------------------------------------------
 *	29/09
 *	VAMOS A PRACTICAR UN AUTOROBO - VAMOS A CREAR UNA NUEVA ENTIDAD
 *	Y LE PASAMOS TODO LO QUE VIMOS HASTA AHORA, ADAPTANDO LAS FUNCIONES
 *	A ESA NUEVA ENTIDAD.
 *
 */


int alumno_imprimirArrayPorIndice(Alumno* arrayAlumno,int limite,int indice);


int main(void) {
	setbuf(stdout,NULL);
	int op;
	Alumno arrayAlumnos[QTY_ALUMNOS];
	Nacionalidad arrayNacionalidades[QTY_NACIONALIDAD];
	alumno_initArray(arrayAlumnos,QTY_ALUMNOS);
	do{
		utn_getNumero(&op,"\n---Menu Alumno--\n\n1-Alta\n"
				"2-Modificar\n"
				"3-Baja\n"
				"4-Imprimir\n"
				"\n---Menu Nacionalidad--\n\n"
				"5-Alta nacionalidad\n"
				"6-Modificar nacionalidad\n"
				"7-Baja nacionalidad\n"
				"8-imprimir nacionalidad\n"
				"9-Salir\n"
				"Elija opcion(1-9): ","\nOpcion invalida!\n",1,9,3);
		switch(op){
		case 1:
			if(!alumno_alta(arrayAlumnos,QTY_ALUMNOS)){
				printf("\nSe realizo el alta con exito!\n");
			}else{
				printf("\nNo se pudo realizar el alta!\n");
			}
			break;
		case 2:
			if(!alumno_modificar(arrayAlumnos,QTY_ALUMNOS)){
				printf("\nSe ha modificado al alumno exitosamente!\n");
			}else{
				printf("\nNo se pudo modificar al alumno\n");
			}
			break;
		case 3:
			if(!alumno_baja(arrayAlumnos,QTY_ALUMNOS)){
				printf("\nSe ha dado de baja al alumno exitosamente!\n");
			}else{
				printf("\nNo se pudo dar de baja al alumno.\n");
			}
			break;
		case 4:
			if(alumno_imprimirTodos(arrayAlumnos,QTY_ALUMNOS))
			{
				printf("\nNo se pudo imprimir a los alumnos.\n");
			}
			break;
		case 5:
			if(!nacionalidad_alta(arrayNacionalidades,QTY_NACIONALIDAD)){
				printf("\nSe realizo el alta con exito!\n");
			}else{
				printf("\nNo se pudo realizar la alta!\n");
			}
			break;
		case 6:
			if(!nacionalidad_modificar(arrayNacionalidades,QTY_NACIONALIDAD)){
				printf("\nSe ha modificado al nacionalidad exitosamente!\n");
			}else{
				printf("\nNo se pudo modificar la nacionalidad\n");
			}
			break;
		case 7:
			if(!nacionalidad_baja(arrayNacionalidades,QTY_NACIONALIDAD)){
				printf("\nSe ha dado de baja al nacionalidad exitosamente!\n");
			}else{
				printf("\nNo se pudo dar de baja la nacionalidad.\n");
			}
			break;
		case 8:
			if(nacionalidad_imprimirTodos(arrayNacionalidades,QTY_NACIONALIDAD))
			{
				printf("\nNo se pudo imprimir a las nacionalidades.\n");
			}
			break;
		}
	}while(op != 9);
	printf("\nHasta Luego!\n");
	return EXIT_SUCCESS;
}

int alumno_imprimirArrayPorIndice(Alumno* arrayAlumno,int limite,int indice){
	int retorno = -1;
	if(arrayAlumno != NULL &&
			indice >= 0 &&
			limite > 0 &&
			indice < QTY_ALUMNOS &&
			arrayAlumno[indice].isEmpty == FALSE)
	{
		printf("\nIndice: %d   - ID: %d   -   Nombre: %-11s  -  Legajo: %d",indice,arrayAlumno[indice].id,arrayAlumno[indice].nombre,arrayAlumno[indice].legajo);
	}
	return retorno;
}


