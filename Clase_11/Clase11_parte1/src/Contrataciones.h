#include "Pantallas.h"
#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_


#define LONG_ARCHIVO 50
#define LONG_CUIT 20
#define LONG_DIREC 100
#define QTY_CONTRATACION 5
#define TRUE 1
#define FALSE 0
#define MIN_IDPAN 100
#define MAX_IDPAN 1000
#define MIN_DIAS 1
#define MAX_DIAS 100

typedef struct{
	int id;
	int cantidadDeDias;
	char nombreArchivo[LONG_ARCHIVO];
	char cuitCliente[LONG_CUIT];
	int idPantalla;
	int isEmpty;
}Contratacion;

int contratacion_alta(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla);
int contratacion_imprimirTodos(Contratacion* pArray,int lenArray);
void contratacion_imprimir(Contratacion buffer,int indice);
int contratacion_initArray(Contratacion* pArray,int lenArray);
int contratacion_buscarLibre(Contratacion* pArray,int limite);
int contratacion_indiceExistente(Contratacion* pArray,int limite,int indice);
int contratacion_modificar(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla);
int contratacion_baja(Contratacion* pArray,int limite);
int contratacion_ordenarPorNombreDeArchivo(Contratacion* pArray,int limite,int orden);
int contratacion_buscarId(Contratacion* pArray,int len,int id);

int contratacion_buscarCuit(Contratacion* pArray,int limite,char* cuit);
int contratacion_mostrarPantallasContratadas(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla,char* cuit);
#endif /* CONTRATACIONES_H_ */
