/*
 * Pantalla.h
 *
 *  Created on: 7 oct. 2020
 *      Author: fedef
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define NOMBRE_LEN 51
#define DIREC_LEN 61
#define QTY_PANTALLAS 100
#define MIN_PRECIO 1000
#define MAX_PRECIO 9999
#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char nombre[NOMBRE_LEN];
	int tipo;
	float precio;
	char direccion[DIREC_LEN];
	int isEmpty;
}Pantalla;

int pantalla_imprimir(Pantalla* auxPantalla);
int pantalla_imprimirArray(Pantalla* pArray,int limite);
int pantalla_inicializarArray(Pantalla* pArray,int limite);
int pantalla_getEmptyIndex(Pantalla* pArray,int limite);
int pantalla_altaArray(Pantalla* pArray,int limite);
int pantalla_buscarId(Pantalla* pArray,int limite,int idABuscar);
int pantalla_modificarArray(Pantalla* pArray,int limite);
int pantalla_bajaArray(Pantalla* pArray,int limite);
int pantalla_ordenarPorNombre(Pantalla* pArray,int limite,int orden);

#endif /* PANTALLA_H_ */
