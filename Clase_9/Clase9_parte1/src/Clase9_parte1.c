/*
 *			|ESTRUCTURAS|
 *
 *typedef : permite redefinir un tipo de dato que ya existe
 * Ejemplo:
 * typedef int juan
 *
 * despues puedo definir en el main juan numero
 * toma a juan como int, GENIAL!
 *
 * eso haremos con la structura
 * las empezamos a definir typedef struct sAlumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define LONG_NOMBRE 50

//ARMADO DE ESTRUCTURAS!
/*
struct sFecha{
	int dia;
	int mes;
	int anio;
};
typedef struct sFecha Fecha;
*/
/*
struct sAlumno{
	char nombre[LONG_NOMBRE];
	char apellido[LONG_NOMBRE];
	long dni;
	Fecha fechaIngreso;//se pueden asignar otras estructuras como campo de otra estructura
};
typedef struct sAlumno Alumno;
*/

//manera compacta de armar una estructura y es la que se va a usar!!!!
typedef struct{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct{
	char nombre[LONG_NOMBRE];
	int legajo;
}Alumno;


int main(void) {
	setbuf(stdout,NULL);
	/*//asi se definen las estructuras
	Alumno arrayAlumnos[1000];

	//ejemplo de uso para asignarle valores a distintos campos de la estructura
	arrayAlumnos[122].dni = 2255666;
	strncpy(arrayAlumnos[122].nombre,"Jose",LONG_NOMBRE); //RECORDAR: que no se puede copiar una cadena con el igual, solo usando el strncpy o el snprintf
	snprintf(arrayAlumnos[122].apellido,LONG_NOMBRE,"Heredia");

	//aca le asigno valor al campo estructura de fecha, usando doble punto.
	arrayAlumnos[122].fechaIngreso.dia = 21;
	*/

	//Pedirle al usuario los datos de tres alumnos e imprimirlos por pantalla
	Alumno arrayAlumnos[5];
	int opcion;
	do{
		printf("MENU:\n\n"
				"1-Cargar Alumnos.\n"
				"2-Imprimir Alumnos.\n"
				"3-Salir\n");
		if(!utn_getNumero(&opcion,"\nElija una opcion(1-3): ","\nOpcion invalida!\n",1,3,5)){
			switch(opcion){
			case 1:

				break;
			case 2:
				break;
			}
		}else{
			printf("\nSe agoto el numero de reintentos.Saliendo del programa\n");
			break;
		}
	}while(opcion != 3);
	return EXIT_SUCCESS;
}

