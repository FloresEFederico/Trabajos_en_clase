/*
 ============================================================================
 	 	 	 	 |PUNTEROS|

 Stack:Es una de las zonas de memoria.
 Aca se guardan los llamados a la funcion, los parametros de la funcion,
 las variables locales y
 otra inforamcion necesaria para el funcionamiento del Programa.

Operador de Direccion: &
OPerador de Indireccion: *

Segmento de Codigo: aca se guardan las instrucciones, en lenguaje maquina,
de nuestro programa.

Segmento Heap: aca se guardan las variables que han sido creadas dinamicamente
en tiempo de ejecucion.
----------------------
Reserva dinamica de memoria:
MALLOC
void* malloc(unsigned int numBytes);

en caso de no poder devolver memoria, devuelve NULL. De esa manera nos damos
cuenta si no se pudo reservar memoria

uso de malloc: la funcion malloc(), devuelve un puntero NULL
int *a;
a = (int*)malloc(sizeof(int));
if(a!= NULL)
{
	*a = 22;
}

REALLOC
el redimensionamiento dinamico de memoria intenta cambiar el tamaño de un
bloque de memoria previamente asignado.

void* realloc(void* ptr,unsigned int numBytes);

Si el tamaño del bloque original no puede ser redimensionado,
entonces 'realloc()' intentara asignar un nuevo bloque de memoria
y copiara el contenido anterior.

uso de free()

se usa asi: free(a);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void){
	setbuf(stdout,NULL);
	int* a = NULL;
	int i;
	//USO DE MALLOC
	/*a = (int*)malloc(sizeof(int));

	if(a != NULL)
		*a = 22;

	printf("Numero guardado en a: %d\nTamaño de a: %d",*a,sizeof(a));
	*/
	//USO DE MALLOC CON UN ARRAY DE INT
	a = (int*)malloc(sizeof(int)*20);
	if(a!= NULL)
	{
		for(i=0;i<20;i++)
		{
			*(a+i) = i+1;
		}
	}
	for(i=0;i<20;i++)
	{
		printf("Indice: %02d  - Numero: %02d\n",i,*(a+i));
	}

	//USO DE REALLOC
	int* pAux;
	pAux = (int*)realloc(a,sizeof(int)*200);
	if(pAux != NULL)
	{
		a = pAux;
		printf("Nice");
	}
	//USO DE FREE
	free(pAux);
	pAux = NULL;
	free(a);
	return EXIT_SUCCESS;
}
