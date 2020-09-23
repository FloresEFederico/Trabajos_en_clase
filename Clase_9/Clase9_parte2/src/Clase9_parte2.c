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


