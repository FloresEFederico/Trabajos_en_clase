/*
 ========================================================================================================================
Array Paralelos: Cuando hay una relacion entre los componentes de igual subindice(misma posicion)
de un vector y otro. Por ejemplo si tenemos dos vectores de 5 elementos cada uno:
-En uno se almacenan los nombres de personas
-En el otro se almacenan los apellidos de dichas personas

El vector 'nombres' es paralelo al vector de 'apellidos' si en la componente 0 de
cada vector se almacena informacion relacionada con la misma persona.


 ========================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define ELEMENTOS 5

int pedidoDeLegajoNombreYSalario(int pArrayLegajos[],char pArrayNombres[][30],int sizeNom,float pArraySalarios[],int longitud);

int main(void) {
	setbuf(stdout,NULL);
/*	//Ordenamiento por  un criterio
	int i;
	int j;
	char nombres[ELEMENTOS][50] = {"Pedro","Carlos","Juan","Ernesto","Mario"};
	char apellidos[ELEMENTOS][50] = {"Gomez","Fernandez","Paz","Perez","Lopez"};
	char auxiliar[50];

	for(i = 0;i<ELEMENTOS-1;i++){
		for(j=i+1;j<ELEMENTOS;j++){
			if(strncmp(nombres[i],nombres[j],50) > 1){
				strcpy(auxiliar,nombres[i]);
				strcpy(nombres[i],nombres[j]);
				strcpy(nombres[j],auxiliar);

				strcpy(auxiliar,apellidos[i]);
				strcpy(apellidos[i],apellidos[j]);
				strcpy(apellidos[j],auxiliar);
			}
		}
	}
	printf("\n\nLista ordenada por nombres");
	for(i=0;i<ELEMENTOS;i++){
		printf("\nNombre: %-11s -    Apellido: %-11s ",nombres[i],apellidos[i]);
	}*/
//-------------------------------------------------------------------------------

	//Ordenamiento por  dos criterio:
	int i;
	int j;

	int legajos[ELEMENTOS] = {1,2,3,4,5};
	int auxLegajo;
	float salarios[ELEMENTOS]={3,2,5,1,5};
	float auxSalario;
	char nombres[ELEMENTOS][30]={"Gonzalo","Yamila","Alberto","Daniela","Horacio"};
	char auxNombre[sizeof(nombres)];

	//pedidoDeLegajoNombreYSalario(legajos,nombres,30,salarios,ELEMENTOS);

	for(i = 0;i<ELEMENTOS-1;i++){
		for(j=i+1;j<ELEMENTOS;j++){
			if(salarios[i] < salarios[j]){
				auxLegajo = legajos[i];
				legajos[i] = legajos[j];
				legajos[j] = auxLegajo;
				strcpy(auxNombre,nombres[i]);
				strcpy(nombres[i],nombres[j]);
				strcpy(nombres[j],auxNombre);
				auxSalario = salarios[i];
				salarios[i] = salarios[j];
				salarios[j] = auxSalario;
			}
			if(salarios[i] == salarios[j]){
				if(strncmp(nombres[i],nombres[j],30) > 0){
					auxLegajo = legajos[i];
					legajos[i] = legajos[j];
					legajos[j] = auxLegajo;
					strcpy(auxNombre,nombres[i]);
					strcpy(nombres[i],nombres[j]);
					strcpy(nombres[j],auxNombre);

				 /*Ya se ordeno arriba!
				  * auxSalario = salarios[i];
					salarios[i] = salarios[j];
					salarios[j] = auxSalario;
					Ya se ordeno arriba!*/
				}
			}
		}
	}
	printf("\n\nLegajo\tNombre\t\t\tSalario	");
	for(i=0;i<ELEMENTOS;i++){
		printf("\n%d\t%s\t\t\t%.2f",legajos[i],nombres[i],salarios[i]);
	}

//-------------------------------------------------------------------------------

	return EXIT_SUCCESS;
}

int pedidoDeLegajoNombreYSalario(int pArrayLegajos[],char pArrayNombres[][30],int sizeNom,float pArraySalarios[],int longitud){
	int retorno = -1;
	int i;
	int legajo;
	char nombre[sizeNom];
	float salario;
	if(pArrayLegajos != NULL && pArrayNombres != NULL && pArraySalarios != NULL && longitud > 0){
		for(i = 0;i<longitud;i++){
			printf("\nITERACION N°%d",i+1);
			printf("\n%d° Legajo\n",i+1);
			if(!utn_getNumero(&legajo,"\nIngrese numero de legajo(0-100): ","\nLegajo Invalido",0,100,3)){
				printf("\nLegajo cargado satisfactoriamente!\n");
				printf("\n%d° Nombre\n",i+1);
				if(!utn_getCadena(nombre,sizeNom,"\nIngrese Nombre: ","\nNombre invalido!\n",3)){
					printf("\nNombre cargado satisfactoriamente!\n");
					printf("\n%d° Salario\n",i+1);
					if(!utn_getNumeroFloat(&salario,"\nIngrese salario(10000-50000): ","\nSalario Invalido!\n",10000,50000,3)){
						printf("\nSalario cargado satisfactoriamente!\n");
						pArrayLegajos[i] = legajo;
						pArraySalarios[i] = salario;
						strncpy(pArrayNombres[i],nombre,sizeNom);
						retorno = 0;
						printf("\n------------------\n");
					}else{
						printf("\nsalario no cargado tristemente!\n :(\n");
					}
				}else{
					printf("\nNombre no cargado tristemente!\n :(\n");
				}
			}else{
				printf("\nLegajo no cargado tristemente!\n :(\n");
			}
		}
	}
	return retorno;
}
