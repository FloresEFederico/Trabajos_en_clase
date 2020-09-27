/*
 * hacer alumno_modificar y alumno_buscarLibre(arrayAlumnos,QTY_ALUMNOS)
 * y alumno_baja y alumno_ordenarPorNombre
 *
 * agregamos un par de cases en el switch:
 * - case 2: alumno_modificar
 * - case 3: alumno_baja
 * - case 4: alumno_ordenarPorNombre
 * -Imprimir pasa al case 5
 * -
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"

/*
 * Clase 10:
 * Ejercicio 5)Realizar una funcion que reciba el array y un indice,
 * e imprima los datos del item de esa posicion, si es que tiene datos validos.
 *
 * Ejercicio 6)Realizar una funcion que me devuelva el indice de un item vacio
 * (sin cargar). Devuelve la posicion libre o -1;
 *
 *Ejercicio 7) Realizar un programa con un menu de dos opciones:
 *	a) Alta de alumno. - NO PEDIR INCIDE-
 *	b) Imprimir lista alumnos
 */
//CLASE 10

//Ejercicio 5
int alumno_imprimirArrayPorIndice(Alumno* arrayAlumno,int indice);


int main(void) {
	setbuf(stdout,NULL);
	int op;
	Alumno arrayAlumnos[QTY_ALUMNOS];

	alumno_initArray(arrayAlumnos,QTY_ALUMNOS);

	do{
		utn_getNumero(&op,"\n1-Alta\n2-Modificar\n3-Baja\n4-Ordenar por nombre\n5-Mostrar\n6-Salir\nElija opcion(1-6): ","\nOpcion invalida!\n",1,6,3);
		switch(op){
		case 1:
			alumno_alta(arrayAlumnos,QTY_ALUMNOS);
			break;
		case 2:
			alumno_modificar(arrayAlumnos,QTY_ALUMNOS);
			break;
		case 3:
			alumno_baja(arrayAlumnos,QTY_ALUMNOS);
			break;
		case 4:
			alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
			break;
		case 5:
			alumno_imprimirTodos(arrayAlumnos,QTY_ALUMNOS);
			break;
		}
	}while(op != 6);
	printf("\nHasta Luego!\n");
	return EXIT_SUCCESS;
}

//FUNCION DE CLASE 10!
//Ejercicio 5
int alumno_imprimirArrayPorIndice(Alumno* arrayAlumno,int limite,int indice){
	int retorno = -1;
	int i;
	if(arrayAlumno != NULL &&
			indice >= 0 &&
			limite > 0 &&
			indice < QTY_ALUMNOS &&
			arrayAlumno[indice].isEmpty == FALSE)
	{
		printf("\nIndice: %d   -   Nombre: %-11s  -  Legajo: %d",indice,arrayAlumno[indice].nombre,arrayAlumno[indice].legajo);
	}
	return retorno;
}


