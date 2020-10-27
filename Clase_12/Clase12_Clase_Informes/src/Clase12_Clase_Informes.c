/*
 ============================================================================
 Name        : Clase12_Clase_Informes.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO_LEN 51
#define CUIT_LEN 20
#define NOMBRE_LEN 51
#define DIREC_LEN 61
#define QTY_PANTALLAS 100
#define MIN_PRECIO 1000
#define MAX_PRECIO 9999

#define ARCHIVO_LEN 51
#define CUIT_LEN 30
#define QTY_CONTRATACIONES 1000
#define TRUE 1
#define FALSE 0
#define MIN_IDPANTALLA 100
#define MAX_IDPANTALLA 999
#define MIN_DIAS 1
#define MAX_DIAS 365

#define TRUE 1
#define FALSE 0

#define QTY_CUITS 1000
typedef struct
{
	int id;
	char nombre[NOMBRE_LEN];
	int tipo;
	float precio;
	char direccion[DIREC_LEN];
	int isEmpty;
}Pantalla;

typedef struct
{
	int id;
	int cantidadDeDias;
	char nombreDeArchivo[ARCHIVO_LEN];
	char cuit[CUIT_LEN];
	int idPantalla;
	int isEmpty;
}Contratacion;

typedef struct
{
	char cuit[30];
	int isEmpty;
}Cliente;

void generarInforme(Contratacion* listaDeCont,int lenCon,Pantalla* listaDePan,int lenPan);
static void generarListaDeCuits(Cliente cuits[],int lenCuits,Contratacion listaDeContrataciones[]);
int cli_inicializarArray(Cliente* list,int lenCuit);
static int estaEnMiListaDeCuits(Cliente listaDeCuits[],int lenCuits,char* cuitABuscar);

int main(void) {
	setbuf(stdout,NULL);

	Contratacion listaDeContrataciones[QTY_CONTRATACIONES];
	Cliente cuits[QTY_CUITS];


	return EXIT_SUCCESS;
}
int cli_inicializarArray(Cliente* list,int lenCuit)
{
	int i;
	int retorno = -1;
	if(list != NULL && lenCuit > 0)
	{
		for(i=0;i<lenCuit;i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

void generarInforme(Contratacion* listaDeCont,int lenCon,Pantalla* listaDePan,int lenPan)
{
	//genera lista de clientes
	Cliente cuits[QTY_CUITS];
	generarListaDeCuits(cuits,QTY_CUITS,listaDeCont);
	//pasar la maqueta de algoritmo del informe aca.
}

static void generarListaDeCuits(Cliente cuits[],int lenCuits,Contratacion listaDeContrataciones[])
{
	int indexCon;
	int indexCuits = 0;
	cli_inicializarArray(cuits,1000);
	for(indexCon = 0;indexCon<QTY_CONTRATACIONES;indexCon++)
	{
		if(!estaEnMiListaDeCuits(listaDeContrataciones[indexCon].cuit,cuits,QTY_CUITS))
		{
			strncpy(cuits[indexCuits].cuit,listaDeContrataciones[indexCon].cuit,CUIT_LEN);
			cuits[indexCuits].isEmpty = FALSE;
			indexCuits++;
		}
	}
}


static int estaEnMiListaDeCuits(Cliente listaDeCuits[],int lenCuits,char* cuitABuscar)
{
	int retorno = 0;
	int i;
	if(listaDeCuits != NULL && cuitABuscar != NULL && lenCuits > 0)
	{
		for(i=0;i<lenCuits;i++)
		{
			if(listaDeCuits[i] == TRUE && strncmp(listaDeCuits[i].cuit,cuitABuscar,CUIT_LEN) == 0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
