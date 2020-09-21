/*
 ============================================================================
Ejercicio N°1: Realizar una agenda para guardar los datos de hasta 200 personas de las cuales
 se toman los siguientes datos (utilizar una estructura para representar a la persona.):

-Nombre
-Apellido
-Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM)
   de una agenda.

b- Mostrar un listado ordenado por Apellido

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Persona.h"
#define QTY_PERSONAS 200

int main(void) { setbuf(stdout,NULL);

	Persona agendaDePersonas[QTY_PERSONAS];
	int opcion;

	initArrayPersonas(agendaDePersonas,QTY_PERSONAS);
	do{
		menuAgenda(&opcion);
		switch(opcion){
		case 1:
			printf("\nMENU ALTA\n");
			if(!altaPersona(agendaDePersonas,QTY_PERSONAS)){
				printf("\nSe ha dado de alta a la persona con exito!\n\nPresione enter para continuar...\n");
				getchar();
			}else{
				printf("\nHubo Un error al dar el alta de la persona!\n");
			}
			break;
		case 2:
			printf("\nMENU BAJA\n");
			if(!bajaPersona(agendaDePersonas,QTY_PERSONAS)){

			}else{
				printf("\nHubo Un error al dar de baja a la persona!\n");
			}
			break;
		case 3:
			printf("\nMENU MODIFICACION\n");
			if(!modificarPersona(agendaDePersonas,QTY_PERSONAS)){
				printf("\nSe ha modificado a la persona con exito!\n\nPresione enter para continuar...\n");
				getchar();
			}else{
				printf("\nHubo Un error al modificar a la persona!\n");
			}
			break;
		case 4:
			printf("\nMENU IMPRIMIR\n");
			if(!imprimeArrayPersona(agendaDePersonas,QTY_PERSONAS)){
				printf("\nPresione enter para continuar...\n");
				getchar();
			}else{
				printf("\nHubo un error al imprimir el menu!\n");
			}
			break;
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
