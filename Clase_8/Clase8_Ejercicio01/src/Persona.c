/*
 * Persona.c
 *
 *  Created on: 16 sep. 2020
 *      Author: fedef
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "utn.h"


int initArrayPersonas(Persona* pArray,int sizePer){
	int retorno = -1;
	int i;
	if(pArray != NULL && sizePer > 0){
		for(i=0;i<sizePer;i++){
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarIndiceLibre(Persona* pArray,int sizePer){
	int retorno = -1;
	int i;
	if(pArray != NULL && sizePer > 0){
		for(i=0;i<sizePer;i++){
			if(pArray[i].isEmpty == 1){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int buscarLegajo(Persona* pArray,int sizePer,int legajoABuscar){
	int retorno = -1;
	int i;
	if(pArray != NULL && sizePer > 0){
		for(i=0;i<sizePer;i++){
			if(pArray[i].isEmpty == 0 && pArray[i].legajo == legajoABuscar){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



int validarLegajoNoExistente(Persona* pArray,int sizePer,int legajoABuscar){
	int retorno = 0;
	int i;
	if(pArray != NULL && sizePer > 0){
		for(i=0;i<sizePer;i++){
			if(pArray[i].isEmpty == 0 && pArray[i].legajo == legajoABuscar){
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int imprimeArrayPersona(Persona* pArray,int sizePer){
	int retorno = -1;
	int i;
	int flag = 0;
	if(pArray != NULL && sizePer > 0){
		for(i=0;i<sizePer;i++){
			if(pArray[i].isEmpty == 0){
				imprimePersona(pArray[i],i);
				flag = 1;
			}
		}
		if(flag == 0){
			printf("\n\nNo Hay persona en la agenda!\n\n");
		}
		retorno = 0;
	}
	return retorno;
}

void imprimePersona(Persona pPersona,int indice){
	printf("\nIndice: [%d] - Legajo: %d - Nombre: %s  -  Apellido: %s \n",indice,pPersona.legajo,pPersona.nombre,pPersona.apellido);
}


int menuAgenda(int* opcion){
	int retorno = -1;

	if(opcion != NULL)
	{
		printf("\n-MENU AGENDA-\n"
				"---------------\n\n"
				"1-Alta\n"
				"2-Baja\n"
				"3-Modificaciones\n"
				"4-MostrarCargados\n"
				"5-Salir.\n");
		if(!utn_getNumero(opcion,"Elija una opcion(1-5): ","\nOpcion Invalida!\n",1,5,3))
		{
			retorno = 0;
		}else
		{
			printf("\nNo se ingreso una opcion valida!\nSaliendo del programa\n");
			*opcion = 5;
		}
	}
	return retorno;
}

int altaPersona(Persona* pArray,int sizePer){
	int retorno = -1;
	int indiceLibre;
	int auxiliarLegajo;
	int existeLegajo;
	Persona auxiliarPersona;

	if(pArray != NULL && sizePer > 0){
		indiceLibre = buscarIndiceLibre(pArray,sizePer);
		if(indiceLibre == -1){
			printf("\nNo hay mas espacio en la agenda\n");
		}else{
			if(!utn_getNumero(&auxiliarLegajo,"\nIngrese un legajo(0-200): ","\nLegajo invalido!\n",0,200,3)){
				existeLegajo = validarLegajoNoExistente(pArray,sizePer,auxiliarLegajo);
				if(existeLegajo){
					printf("\nEse legajo ya existe! Volviendo al menu principal!\n");
				}else{
					auxiliarPersona.legajo = auxiliarLegajo;
					if(!utn_getCadena(auxiliarPersona.nombre,sizeof(auxiliarPersona.nombre),"\nIngrese Nombre: ","\nNombre Invalido!\n",3) &&
					   !utn_getCadena(auxiliarPersona.apellido,sizeof(auxiliarPersona.apellido),"\nIngrese Apellido: ","\nApellido Invalido!\n",3)
					   ){
						auxiliarPersona.isEmpty = 0;
						pArray[indiceLibre] = auxiliarPersona;
						retorno = 0;
					}else{
						printf("\nHubo un error al ingresar los datos!\n");
					}
				}
			}
		}
	}
	return retorno;
}

int bajaPersona(Persona* pArray,int sizePer){
	int retorno = -1;
	int auxiliarLegajo;
	int existe;
	char respuesta;
	if(pArray != NULL && sizePer > 0){
		imprimeArrayPersona(pArray,sizePer);
		if(!utn_getNumero(&auxiliarLegajo,"\nIngrese el legajo de la persona que desea dar de baja: ","\nLegajo invalido!\n",0,200,3)){
			existe = buscarLegajo(pArray,sizePer,auxiliarLegajo);
			if(existe != -1){
				imprimePersona(pArray[existe],existe);
				if(!utn_getCaracter(&respuesta,"\nDesea Eliminarlo? (s/n): ","\nLetra invalida!\n",'n','s',3)){
					if(respuesta == 's'){
						pArray[existe].isEmpty = 1;
						printf("\nSe ha dado de baja a la persona con exito!\n");
					}else{
						printf("\nSe ha cancelado la baja!\n");
					}
						fflush(stdin);
						retorno = 0;
				}else{
					printf("\nHubo un error al ingresar una letra\n");
				}
			}else{
				printf("\nEse legajo no existe! Volviendo al menu principal!\n");
			}
		}
	}
	return retorno;
}

int modificarPersona(Persona* pArray,int sizePer){
	int retorno = -1;
	int auxiliarLegajo;
	int existe;
	Persona auxiliarPersona;

	if(pArray != NULL && sizePer > 0){
		imprimeArrayPersona(pArray,sizePer);
		if(!utn_getNumero(&auxiliarLegajo,"\nIngrese el legajo de la persona que desea modificar: ","\nLegajo invalido!\n",0,200,3)){
			existe = buscarLegajo(pArray,sizePer,auxiliarLegajo);
			if(existe != -1){
				auxiliarPersona.legajo = existe;
				imprimePersona(pArray[existe],existe);
				if(!utn_getCadena(auxiliarPersona.nombre,sizeof(auxiliarPersona.nombre),"\nIngrese Nombre: ","\nNombre Invalido!\n",3) &&
				   !utn_getCadena(auxiliarPersona.apellido,sizeof(auxiliarPersona.apellido),"\nIngrese Apellido: ","\nApellido Invalido!\n",3)
				   ){
					auxiliarPersona.isEmpty = 0;
					pArray[existe] = auxiliarPersona;
					retorno = 0;
				}else{
					printf("\nHubo un error al ingresar los datos!\n");
				}
			}else{
				printf("\nEse legajo no existe! Volviendo al menu principal!\n");
			}
		}
	}
	return retorno;
}


