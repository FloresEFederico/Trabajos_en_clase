/*
 ============================================================================
HACER FUNCION getNOMBRE	con scanf %s y verificar que sean letras y eso
 ============================================================================
 */

//SCANF NO VA MAS ...... SE USA MYGETS
//HOY VIMOS: STRNLEN; STRNCPY; STRNCMP - STRNICMP; SNPRINTF
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getNombre(char* pResultado,int limite,char* mensaje,char* mensajeError,int reintentos);
static int getString(char* buffer,int longitud);
static int esUnNombreValido(char* buffer,int limite);
static int myGets(char* buffer,int longitud);

int main(void){
	setbuf(stdout,NULL);
	char nombre[5];

	while(1){
		if(!utn_getNombre(nombre,sizeof(nombre),"\nIngrese nombre: ","\nNombre invalido!\n",3)){
			printf("\nNombre es: %s\n",nombre);
		}else{
			printf("\nERROR\n");
		}
	}
	return EXIT_SUCCESS;
}

/**
 * \brief Solicita un nombre al usuario
 * \param pResultado:
 * \param limite:
 * \param mensaje:
 * \param mensajeError:
 * \param reintentos:
 *
 * \return
 */

int utn_getNombre(char* pResultado,int limite,char* mensaje,char* mensajeError,int reintentos){
	int retorno = -1;
	char bufferString[256];


	if(pResultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		reintentos >= 0 &&
		limite > 0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			if(getString(bufferString,sizeof(bufferString)) &&
			   strnlen(bufferString,sizeof(bufferString)) <= limite
			   )
			{
				strncpy(pResultado,bufferString,limite-1);
				retorno = 0;
				break;
			}else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos > 0);
	}
	return retorno;
}

static int getString(char* buffer,int longitud){
	int retorno = 0;
	int resultadoGets;
	char auxString[64];
	if(buffer != NULL && longitud > 0)
	{
		fflush(stdin);
		resultadoGets = myGets(auxString,sizeof(auxString));
		if(resultadoGets && esUnNombreValido(auxString,sizeof(auxString))){
			strncpy(buffer,auxString,longitud);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * \brief esUnNombreValido: verifica una cadena recibida como parametro para determinar
 * 							si es un nombre valido.
 * \param pResultado: cadena a analizar
 * \param limite: indica la cantidad de letras maxima de la cadena
 * \return (0) va a indicar que no es un nombre valido y (!0) va a indicar que es un nombre valido
 */
static int esUnNombreValido(char* buffer,int limite){
	int respuesta = 1; // TODO OK
	int i;
	if(buffer != NULL && limite > 0){
		for(i=0; i <= limite && buffer[i] != '\0';i++){
			if((buffer[i] < 'a' || buffer[i] > 'z') &&
			   (buffer[i] < 'A' || buffer[i] > 'Z') &&
			    buffer[i] != ' ')
			{
				respuesta = 0;
				break;
			}
		}
	}
	return respuesta;
}


static int myGets(char* buffer,int longitud){
	int retorno = 0;
	if(buffer != NULL && longitud > 0){
		fflush(stdin);
		fgets(buffer,longitud,stdin);
		if(buffer[strlen(buffer) - 1] == '\n'){
			buffer[strlen(buffer) - 1] = '\0';
		}
		retorno = 1;
	}
	return retorno;
}
