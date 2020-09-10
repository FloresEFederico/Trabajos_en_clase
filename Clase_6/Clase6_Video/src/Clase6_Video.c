/*
====================================================================================================================================
				Cadena de caracteres: (STRING)

*sprintf : es como un printf pero puede guardar dentro de un array de caracteres
3 parametros: 1°en que variable quiero guardar le printf, 2° el mensaje o lo que quiero que guarde
3° por si pusiste alguna mascara o queres que imprima algo, eso.
----**Funcion segura de sprintf es snprintf-----***

string: es un array de caracteres. la diferencia es que al ponerle la cantidad de bites queres
que tenga tu string, tener en cuenta que el ultimo caracter es'\0', por ende siempre tener
en cuenta el tamaño del texto. el '\0' indica que el texto termino.

**¿Que pasa si hago un string de 5 bites y le pide que guarde la palabra PEDRO?
Como el '\0' siempre va a lo ultimo de un string y pedro son 5 letras P E D R O, el '\0'
va a ir a parar a un espacio que ya es afuera de esa variable y ese espacio al que va a parar
es un espacio que puede estar siendo utilizado por otra cosa y puede producir un caos
PEDRO = CAOS

Para trabajar con strings necesitaremos incluir la biblioteca "String.h"
esa biblioteca se incluye haciendo #include <string.h>

-funcion strcpy: copia un string de una variable a otra, pero el problema es que no tiene
en cuenta el tamaño de cada string que copia, asique a esta funcion se la considera insegura
-por ende, utilizaremos la funcion strncpy:recibe los mismos parametros que strcpy pero
como tercer parametro, recibe el tamaño limite que se le otorga a la funcion para que copie

- funcion strnlen: esta devuelve el tamaño ocupado por el texto que tiene adentro se le pasa
la variable y el size de la variable. Es como strlen pero mas segura.

- funcion strncat: para concatenar texto, y el tamaño maximo de lo que se va a concatenar
sizeof: devuelve el tamaño fisico de una variable en TOTAL


funciones static: son funciones privadas las cuales se declaran en el punto c. Esto hace
que estas funciones no se pueden utilizar en el main, son funciones pensadas
para que sean usadas dentro de otras funciones y que no tenia pensado en usar en el main.
====================================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	float numero;
	utn_getNumeroFloat(&numero,"numero: ","\nINvalido\n",-10,0,60);
	char nombre[11] = "JUAN"; // este array de nombre es capaz de guardar DIEZ caracteres como MAXIMO! porque la ultima posicion esta dedicada al '\0'
	char auxiliar[30];
	/*
	 * SE le puede dar un valor inicial al string, ejemplos:
	 * char nombre[11] = {"J","U","A","N"};
	 * o
	 * char nombre[11] = "JUAN";
	 */
//--------------------------STRNCPY--------------------------

	strncpy(auxiliar,nombre,sizeof(auxiliar));

	printf("\nNombre mide: %d\n"
			"Auxiliar mide: %d\n",sizeof(nombre),sizeof(auxiliar));

//--------------------------STRNLEN--------------------------
	printf("\n-------------------STRNLEN---------------------------\n\n");

	printf("\nTamaño de la variable nombre con el strlen: %d\n"
			"Tamaño de la variable auxiliar con el strlen: %d\n",strnlen(nombre,sizeof(nombre)),strnlen(auxiliar,sizeof(auxiliar)));

	//--------------------------STRNCAT--------------------------

	strncat(nombre," LALA",sizeof(nombre)-1);


	printf("\n--------------Utilizacion de la funcion 'sprintf'---------------------------\n\n");


	snprintf(auxiliar,sizeof(auxiliar),"\nMI SIZE OF ES: %d\n",sizeof(auxiliar));
	printf("\n%s\n",auxiliar);
	return EXIT_SUCCESS;
}
