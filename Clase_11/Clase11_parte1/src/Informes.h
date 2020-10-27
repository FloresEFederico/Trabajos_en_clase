#include "Pantalla.h"
#include "Contratacion.h"
#ifndef INFORMES_H_
#define INFORMES_H_
#define CANTIDAD_CUIT 1000


int informar_consultarFacturacion(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla);
int informar_imprimirContratacionesConImportePorCliente(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla);
int informar_calcularDeudaCliente(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla,char* cuit,float* deuda);
int informar_imprimirMaximoImporte(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla);
int subMenu_informes(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla);
#endif /* INFORMES_H_ */
