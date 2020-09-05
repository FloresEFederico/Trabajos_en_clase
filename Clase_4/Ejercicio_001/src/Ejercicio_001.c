/*
 =============================================================================================================
 1) Desarrollar una biblioteca "utn.h" que posea funciones para pedirle al usuario el ingreso de datos:
   -getInt()
   -getFloat()
   -getChar()
--------------------------------------------------------------------------------------------------------------
 2) Diseñar un programa para jugar a adivinar un número entre 0 y 100.
	El juego tiene que dar pistas de si el número introducido por el jugador está por encima o por debajo.
	El juego termina cuando se adivina el número o se decide terminar de jugar ingresando un número negativo.
	Permitir jugar tantas veces como lo desee el jugador y al salir mostrar su mejor puntuación.
	Utilizar la biblioteca del ejercicio anterior!
 =============================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Esta biblioteca la vamos a necesitar para el ejercicio del Numero aleatorio

int getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int getChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

char getNumeroAleatorio(int desde,int hasta,int iniciar);

int main(void) {
	setbuf(stdout,NULL);
	int numeroOculto;
	int numeroIngresado;
	char terminarJuego = 's';
	int juego;

	while(terminarJuego == 's'){
		numeroOculto = getNumeroAleatorio(0,10,1);
		juego = 1;
		while(juego){
			getInt(&numeroIngresado,"\nIngrese un numero(0-10)(-1 para dejar de jugar): ","\nNumero Invalido!",-1,10,3);
			if(numeroIngresado < 0){
				juego = 0;
			}else if(numeroIngresado == numeroOculto){
				printf("\nFelicidades! ganaste!\n");
				juego = 0;
			}else if(numeroIngresado < numeroOculto){
				printf("\nTe falta!\n");
			}else if(numeroIngresado > numeroOculto){
				printf("\nTe pasaste!\n");
			}
		}
		getChar(&terminarJuego,"\nDesea continuar Jugando?\n's' para si\n'n' para no\n: ","\nLetra Invalida!\n",'n','s',9);
	}
	printf("\nESPERO QUE TE HAYAS DIVERTIDO!\n");
	return EXIT_SUCCESS;
}

int getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = -1;
	int resultadoScan;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScan = scanf("%d",&bufferInt);
			if(resultadoScan && bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}else{
				reintentos--;
				printf("%s",mensajeError);
				printf("\n-REINTENTOS: %d\n",reintentos);
			}
		}while(reintentos > 0);
	}

	return retorno;
}
int getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos){
	int retorno = -1;
	int resultadoScan;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScan = scanf("%f",&bufferFloat);
			if(resultadoScan && bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}else{
				reintentos--;
				printf("%s",mensajeError);
				printf("\n-REINTENTOS: %d\n",reintentos);
			}
		}while(reintentos > 0);
	}

	return retorno;
}
int getChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = -1;
	int resultadoScan;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScan = scanf("%c",&bufferChar);
			if(resultadoScan && bufferChar >= minimo && bufferChar <= maximo){
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}else{
				reintentos--;
				printf("%s",mensajeError);
				printf("\n-REINTENTOS: %d\n",reintentos);
			}
		}while(reintentos > 0);
	}
	return retorno;
}

/**
 * \brief Genera un numero aleatorio
 * \param desde numero aleatorio minimo
 * \param hasta numero aleatorio maximo
 * \param iniciar indica si se trata del primer numero solicitado 1 indica que si
 * \return retorna el numero aleatorio generado
 */
char getNumeroAleatorio(int desde,int hasta,int iniciar){
	if(iniciar){
		srand(time(NULL));
	}
	return desde + (rand() % (hasta + 1 - desde));
}
