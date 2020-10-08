/*
 ============================================================================
 Name        : Clase10_video.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"



int main(void) {
	setbuf(stdout,NULL);
	Cliente listaDeClientes[QTY_CLIENTES];
	int opcion;
	int estadoDeOrden;
	cli_inicializarArray(listaDeClientes,QTY_CLIENTES);
	do
	{
		if(!utn_getNumero(&opcion,"\n--MENU PRINCIPAL--\n"
								  "1-Cargar un Cliente.\n"
								  "2-Modificar un Cliente.\n"
								  "3-Eliminar un Cliente.\n"
								  "4-Ordenar lista de CLientes por Nombre y Altura.\n"
								  "5-Imprimir lista de Clientes.\n"
								  "6-Salir\nElija una opcion(1-6): ","\nOpcion invalida!\n",1,6,3)
			)
		{
			switch(opcion)
			{
			case 1:
				if(!cli_altaArray(listaDeClientes,QTY_CLIENTES))
				{
					printf("\nSe realizo el alta con exito!\n");
				}else
				{
					printf("\nNo se realizo el alta!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 2:
				if(!cli_modificarArray(listaDeClientes,QTY_CLIENTES))
				{
					printf("\nSe realizo la modificacion con exito!\n");
				}else
				{
					printf("\nNo se modifico ningun dato!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 3:
				if(!cli_bajaArray(listaDeClientes,QTY_CLIENTES))
				{
					printf("\nSe realizo la baja con exito!\n");
				}else
				{
					printf("\nNo se dio de baja a ningun CLiente!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 4:
				if(!utn_getNumero(&estadoDeOrden,"\n¿En que orden desea ordenar?\n0-Ascendente.\n1-Descendente.\nElija una opcion(0-1): ","\nOpcion invalida!\n",0,1,3) &&
				   !cli_ordenarPorNombreYAltura(listaDeClientes,QTY_CLIENTES,estadoDeOrden))
				{
					if(!estadoDeOrden)
					{
						printf("\nSe ha ordenado a los clientes de manera Ascendente!\n");
					}else{
						printf("\nSe ha ordenado a los clientes de manera Descendente!\n");
					}
				}else
				{
					printf("\nNo se pudo ordenar los Clientes!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 5:
				if(!cli_imprimirArray(listaDeClientes,QTY_CLIENTES))
				{
					printf("--------------------------------\n");
				}else
				{
					printf("\nNo hay clientes que mostrar.\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			}
		}
	}while(opcion != 6);
	printf("\nHasta luego!\n");

	return EXIT_SUCCESS;
}
