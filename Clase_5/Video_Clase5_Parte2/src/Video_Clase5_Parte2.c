/*
 ============================================================================
					|ARRAY- Parte 2|
Lo que vamos a ver ahora es como pasar los arrays como argumento

 funcion ImprimirArray = recibe el array y muestra por un printf
 lo muestra.Recibe como parametro un int porque el dato que le
 pasaremos es un int.

 recordar:
 //void nombreFuncion(int* e)//nombreFuncion(&variable)
 // esto es pasaje por referencia
 //void nombreFuncion(int e) esto es pasaje por valor
 * pasar un array como parametro en una funcion,
 * siempre se pasa por referencia.
 *-------------------------------------------------------------
 * REGLA DE ORO: EL NOMBRE DEL ARRAY ES LA DIRECCION DE MEMORIA
 * DONDE COMIENZA EL ARRAY!
 * quiere decir: cuando llamo una funcion que reciba como
 * parametro un array y yo le pongo el array del main ahi
 * no es necesario que vaya con corchetes porque asi sola
 * sin corchetes, esta pasando la direccion de memoria de
 * ese array.
 *
 * A LAS FUNCIONES AL RECIBIR UN ARRAY, TMB SE RECIBE UN TAMAÑO!
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define SIZEARRAY 5

void imprimirArray(int array[],int len);
//void imprimirArray(int* array) tmb se puede hacer asi.
//porque el array no deja de ser una direccion de memoria
//int len se utiliza para reemplazar el define de la funcion y queda mas generica- LENGTH

int main(void) {
	setbuf(stdout,NULL);
	int edades[SIZEARRAY];
	int i;
	for(i=0;i<SIZEARRAY;i++){
		if(utn_getNumero(&edades[i],"\nEdades? ","\nEdad Invalida!\n",5,100,5)){
			printf("\nTodo mal!\n");
			break;
		}
	}
	imprimirArray(edades,SIZEARRAY);
	return EXIT_SUCCESS;
}

/*utilizando un array se puede tanto leer como escribir, no es
necesario ponerle el & o el *.
el array se diferencia en eso con una variable.
si yo pongo array[2] = 4, cuando vuelva al main
edades[2](array en la funcion) valdra 4.
Recibir un array siempre es por referencia: puedo leer o escribir
un array[] asi es como pasar la direccion de memoria
NO SE HACE UNA COPIA, ES LA MISMA VARIABLE QUE MAIN
*/

//void imprimirArray(int* array) tmb se puede hacer asi. porque el array no deja de ser una direccion de memoria
void imprimirArray(int array[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d ",array[i]);
	}
}

