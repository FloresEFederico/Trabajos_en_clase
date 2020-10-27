#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#include "Contratacion.h"
#include "informes.h"



int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	Pantalla listaDePantallas[QTY_PANTALLAS];
	Contratacion listaDeContrataciones[QTY_CONTRATACIONES];

	pantalla_inicializarArray(listaDePantallas,QTY_PANTALLAS);
	contratacion_inicializarArray(listaDeContrataciones,QTY_CONTRATACIONES);
	do
	{
		if(!utn_getNumero(&opcion,"\n---MENU PRINCIPAL---\n"
								  "1-Alta de Pantalla.\n"
								  "2-Modificar datos de Pantalla.\n"
								  "3-Baja de Pantalla.\n"
								  "4-Contratar una Publicidad.\n"
								  "5-Modificar condiciones de Publicacion.\n"
								  "6-Cancelar contratacion.\n"
								  "7-Consulta Facturacion.\n"
								  "8-Listar Contrataciones.\n"
								  "9-Listar Pantallas.\n"
								  "10-Infomar.\n"
								  "11-Salir.\nElija una opcion(1-11): ","\nOpcion invalida!\n",1,11,3))
		{
			switch(opcion)
			{
			case 1:
				printf("\nALTA DE PANTALLA\n");
				if(!pantalla_altaArray(listaDePantallas,QTY_PANTALLAS))
				{
					printf("\nSe ha dado de alta exitosamente!\n");
				}else
				{
					printf("\nHubo un error al hacer el alta!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 2:
				printf("\nMODIFICAR DATOS DE PANTALLA\n");
				if(!pantalla_modificarArray(listaDePantallas,QTY_PANTALLAS))
				{
					printf("\nSe ha modificado la pantalla exitosamente!\n");
				}else
				{
					printf("\nHubo un error al hacer la modificacion!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 3:
				printf("\nBAJA DE PANTALLA\n");
				if(!pantalla_bajaArray(listaDePantallas,QTY_PANTALLAS))
				{
					printf("\nSe ha dado de baja exitosamente!\n");
				}else
				{
					printf("\nHubo un error al hacer la baja!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 4:
				printf("\nCONTRATAR UNA PUBLICIDAD\n");
				if(!contratacion_altaArray(listaDeContrataciones,QTY_CONTRATACIONES,listaDePantallas,QTY_PANTALLAS))
				{
					printf("\nSe ha contratado una publicidad exitosamente!\n");
				}else
				{
					printf("\nHubo un error al hacer la contratacion!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 5:
				printf("\nMODIFICAR CONDICIONES DE PUBLICACION\n");
				if(!contratacion_modificarArray(listaDeContrataciones,QTY_CONTRATACIONES,listaDePantallas,QTY_PANTALLAS))
				{
					printf("\nSe ha modificado la publicidad exitosamente!\n");
				}else
				{
					printf("\nHubo un error al modificar la publicidad!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 6:
				printf("\nCANCELAR CONTRATACION\n");
				if(!contratacion_bajaArray(listaDeContrataciones,QTY_CONTRATACIONES,listaDePantallas,QTY_PANTALLAS))
				{
					printf("\nSe ha cancelado la contratacion exitosamente!\n");
				}else
				{
					printf("\nHubo un error al cancelar la contratacion!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 7:
				printf("\nCONSULTA FACTURACION\n");
				if(!informar_consultarFacturacion(listaDeContrataciones,QTY_CONTRATACIONES,listaDePantallas,QTY_PANTALLAS))
				{
					printf("---------------------\n");
				}else
				{
					printf("\nHubo un error al consultar la facturacion\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 8:
				printf("\nLISTAR CONTRATACIONES\n");
				if(!contratacion_imprimirArray(listaDeContrataciones,QTY_CONTRATACIONES))
				{
					printf("---------------------\n");
				}else
				{
					printf("\nHubo un error al imprimir las contrataciones\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 9:
				printf("\nLISTAR PANTALLAS\n");
				if(!pantalla_imprimirArray(listaDePantallas,QTY_PANTALLAS))
				{
					printf("---------------------\n");
				}else
				{
					printf("\nHubo un error al imprimir las pantallas\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 10:
				if(!subMenu_informes(listaDeContrataciones,QTY_CONTRATACIONES,listaDePantallas,QTY_PANTALLAS))
				{
					printf("\nVolviendo al menu principal\n");
				}else
				{
					printf("\nHubo un error en el subMenu de informes\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			}
		}
	}while(opcion != 11);

	return EXIT_SUCCESS;
}
