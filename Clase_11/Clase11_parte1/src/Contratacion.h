#include "Pantalla.h"
#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define ARCHIVO_LEN 51
#define CUIT_LEN 30
#define QTY_CONTRATACIONES 1000
#define TRUE 1
#define FALSE 0
#define MIN_IDPANTALLA 100
#define MAX_IDPANTALLA 999
#define MIN_DIAS 1
#define MAX_DIAS 365

typedef struct
{
	int id;
	int cantidadDeDias;
	char nombreDeArchivo[ARCHIVO_LEN];
	char cuit[CUIT_LEN];
	int idPantalla;
	int isEmpty;
}Contratacion;

int contratacion_imprimir(Contratacion* auxContratacion);
int contratacion_imprimirArray(Contratacion* pArray,int limite);
int contratacion_inicializarArray(Contratacion* pArray,int limite);
int contratacion_getEmptyIndex(Contratacion* pArray,int limite);
int contratacion_altaArray(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla);
int contratacion_buscarId(Contratacion* pArray,int limite,int idABuscar);
int contratacion_modificarArray(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla);
int contratacion_bajaArray(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla);
int contratacion_ordenarPorNombre(Contratacion* pArray,int limite,int orden);

//-------------------------------------------------------------
int contratacion_buscarCuit(Contratacion* pArray,int limite,char* cuitABuscar);
int contratacion_mostrarPantallasContratadas(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla,char* cuit);


#endif /* CONTRATACION_H_ */
