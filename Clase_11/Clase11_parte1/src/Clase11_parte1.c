/*
 ============================================================================
 	 	 	 	 	 PARCIAL MODELO PARA HACER!!!


 Pantallas y contrataciones!
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantallas.h"
#include "Contrataciones.h"
/*


*/
int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	Pantalla listaDePantallas[QTY_PANTALLA] = {{100,"PrimerPan",1,1000,"Av.Coco 223",0},
												{101,"SegundaPan",1,1000,"Av.Loco 114",0},
												{102,"TercerPan",2,1500,"CalleFalsa 000",0},
												{103,"CuartaPan",2,1500,"Av.Coco 224",0},
												{104,"QuintaPan",1,1000,"Pedro 113",0}};

	Contratacion listaDeContrataciones[QTY_CONTRATACION] = {{1000,4,"PrimerArchivo","20045169384",100,0},
															{1001,7,"SegundoArchivo","2537837464",100,0},
															{1002,1,"TercerArchivo","20045169384",102,0},
															{1003,5,"CuartoArchivo","27140385455",103,0},
															{1004,4,"QuintoArchivo","20045169384",102,0}};

	//pantalla_initArray(listaDePantallas,QTY_PANTALLA);
	//contratacion_initArray(listaDeContrataciones,QTY_CONTRATACION);
	do
	{
		if(!utn_getNumero(&opcion,"\n--MENU PRINCIPAL--\n"
								  "---------------------\n"
								  "1-Alta de Pantalla.\n"
								  "2-Modificar datos de pantalla.\n"
								  "3-Baja de pantalla.\n"
								  "4-Contratar una publicidad.\n"
								  "5-Modificar condiciones de Publicacion.\n"
								  "6-Cancelar contratacion.\n"
								  "7-NO COMPLETADO!Consulta facturacion.(por ahora imprime array de pantalla)\n"
								  "8-NO COMPLETADO!Listar contrataciones.(por ahora imprime array de contratacion)\n"
								  "9-NO COMPLETADO!Listar Pantallas.\n"
								  "10-NO COMPLETADO!Informar.\n"
								  "11-Salir.\n"
								  "Elija una opcion(1-11): ","\nOpcion Invalida!\n",1,11,3))
		{
			switch(opcion)
			{
			case 1:
				printf("\nALTA DE PANTALLA\n----------------\n");
				if(!pantalla_alta(listaDePantallas,QTY_PANTALLA))
				{
					printf("\nSe ha dado de alta la pantalla exitosamente!\n");
				}else{
					printf("\nHubo un error al hacer el alta de la pantalla!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 2:
				printf("\nMODIFICAR DATOS DE PANTALLA\n----------------------\n");
				if(!pantalla_modificar(listaDePantallas,QTY_PANTALLA))
				{
					printf("\nSe ha modificado los datos de la pantalla exitosamente!\n");
				}else{
					printf("\nHubo un error al modificar los datos de la pantalla!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 3:
				printf("\nBAJA DE PANTALLA\n----------------\n");
				if(!pantalla_baja(listaDePantallas,QTY_PANTALLA))
				{
					printf("\nSe ha dado de baja la pantalla exitosamente!\n");
				}else{
					printf("\nHubo un error al dar de baja la pantalla!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 4:
				printf("\nCONTRATAR UNA PUBLICIDAD\n-----------------------\n");
				if(!contratacion_alta(listaDeContrataciones,QTY_CONTRATACION,listaDePantallas,QTY_PANTALLA))
				{
					printf("\nSe ha contratado la publicidad exitosamente!\n");
				}else{
					printf("\nHubo un error al contratar una publicidad!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 5:
				printf("\nMODIFICAR CONDICIONES DE PUBLICACION\n---------------------------\n");
				if(!contratacion_modificar(listaDeContrataciones,QTY_CONTRATACION,listaDePantallas,QTY_PANTALLA))
				{
					printf("\nSe ha modificado los datos exitosamente!\n");
				}else{
					printf("\nHubo un error al modificar los datos!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 6:
				printf("\nCANCELAR CONTRATACION\n----------------------\n");
				if(!contratacion_baja(listaDeContrataciones,QTY_CONTRATACION))
				{
					printf("\nSe ha cancelado la contratacion exitosamente!\n");
				}else{
					printf("\nHubo un error al cancelar la contratacion!\n");
				}
				printf("\nPresione enter para continuar...\n");
				getchar();
				break;
			case 7:
				pantalla_imprimirTodos(listaDePantallas,QTY_PANTALLA);
				break;
			case 8:
				contratacion_imprimirTodos(listaDeContrataciones,QTY_CONTRATACION);
				break;
			case 9:
				printf("\nFALTA HACER!!!\n");
				break;
			case 10:
				printf("\nFALTA HACER!!!\n");
				break;
			}
		}
	}while(opcion != 11);
	printf("\nHasta luego!\n");
	return EXIT_SUCCESS;
}
