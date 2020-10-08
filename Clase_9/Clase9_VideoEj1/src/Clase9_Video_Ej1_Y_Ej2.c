/*
 ============================================================================
 Ejercicio 1:
Definir un nuevo tipo de dato que represente un producto.
El producto tiene un nombre, una descripcion y un precio
hacer un programa que le pida al usuario los datos del producto
y los cargue en una variable del tipo Producto definida
en la funcion main
Imprimir los campos de la variable producto para chequear que
esten cargadas correctamente

Ejercicio 2:
Tomar el programa del ejercicio anterior y agregarle lo siguiente:
1) una vez que el usuario ingreso los datos, preguntarle si quiere aplicar
un descuento del 25% al precio del producto.
Si acepta, calcular el nuevo precio.

2)Hacer una funcion que reciba la variable producto definida y que imprima
sus valores.

Ejercicio 3:
definir un array de 100 productos y realizar una funcion que inicialice el
array indicando que los items no estan cargados con informacion valida.

Ejercicio 4:
tomar el ejercicio 3 y realizar una funcion que reciba el array, un indice
y le permita al usuario cargar los datos en el item de la posicion
especificada por el indice
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"


int main(void) {
	setbuf(stdout,NULL);
	Producto listaDeProductos[QTY_PRODUCTOS];
	int opcion;
	int indiceDeAlta = 0;
	producto_initArray(listaDeProductos,QTY_PRODUCTOS);
	do
	{
		if(!utn_getNumero(&opcion,"\nMenu de Productos--\n1-Carga de datos.\n2-Imprimir productos.\n3-Salir\nElija opcion(1-3): ","\nOpcion invalida!\n",1,3,3))
		{
			switch(opcion)
			{
			case 1:
				printf("\n--Menu de Carga--\n-----------------\n");
				if(!producto_cargarProductoPorIndice(listaDeProductos,QTY_PRODUCTOS,indiceDeAlta)){
					printf("\nTODO PERFECTO!\n");
				}else{
					printf("\nHubo un error al hacer el alta del producto\n");
				}
				break;
			case 2:
				printf("\n--Menu Imprimir--\n-----------------\n");
				if(!producto_imprimirTodos(listaDeProductos,QTY_PRODUCTOS)){
					printf("\nTODO PERFECTO!\n");
				}else{
					printf("\nHubo un error al imprimir los productos\n");
				}
				break;
			}
		}
	}while(opcion != 3);

	return EXIT_SUCCESS;
}

