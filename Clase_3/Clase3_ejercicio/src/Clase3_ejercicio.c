/*
 pedir al usuario dos numeros flotantes:

 funcion sumar
 funcion restar
 funcion multiplicar
 funcion dividir

 si todas las funciones salieron bien, return 0
 y en caso de que hayan salido mal, return -1

 */

#include <stdio.h>
#include <stdlib.h>

//prototipos de las funciones:
int sumar(float operador1,float operador2,float* result);
int restar(float operador1,float operador2,float* result);
int multiplicar(float operador1,float operador2,float* result);
int dividir(float operador1,float operador2,float* result);

int getFloat(char* mensaje,char* mensajeError,int reintentos,float* pResultado);
//---------------------------------------------------------

int main(void) {
	setbuf(stdout,NULL);

	float num1;
	float num2;
	float resultado;

	if(!getFloat("\nIngrese el primer numero: ","\nNumero invalido! Ingrese el numero nuevamente: ",5,&num1)){
		if(!getFloat("\nIngrese el segundo numero: ","\nNumero invalido! Ingrese el numero nuevamente: ",5,&num2)){
			if(!sumar(num1,num2,&resultado)){
			printf("\nEl resultado de la suma es de: %.2f\n",resultado);
			}else{
				printf("\n la suma salio mal!\n\n");
			}
			if(!restar(num1,num2,&resultado)){
			printf("\nEl resultado de la resta es de: %.2f\n",resultado);
			}else{
				printf("\n la resta salio mal!\n\n");
			}
			if(!multiplicar(num1,num2,&resultado)){
			printf("\nEl resultado de la multiplicacion es de: %.2f\n",resultado);
			}else{
				printf("\n la multiplicacion salio mal!\n\n");
			}
			if(!dividir(num1,num2,&resultado)){
			printf("\nEl resultado de la division es de: %.2f\n",resultado);
			}else{
				printf("\n la division salio mal!\nNo se puede dividir por 0\n\n");
			}
		}else{
			printf("\nERROR! SEGUNDO NUMERO INVALIDO SE CERRO EL PROGRAMA\n\n");
		}
	}else{
		printf("\nERROR! PRIMERO NUMERO INVALIDO SE CERRO EL PROGRAMA\n\n");
	}

	return EXIT_SUCCESS;
}

int sumar(float operador1,float operador2,float* result){
	int retorno = -1;
	*result = operador1+operador2;
	retorno = 0;
	return retorno;
}
int restar(float operador1,float operador2,float* result){
	int retorno = -1;
	*result = operador1-operador2;
	retorno = 0;
	return retorno;
}
int multiplicar(float operador1,float operador2,float* result){
	int retorno = -1;
	*result = operador1*operador2;
	retorno = 0;
	return retorno;
}
int dividir(float operador1,float operador2,float* result){
	int retorno = -1;
	if(operador2 != 0){
	*result = operador1/operador2;
	retorno = 0;
	}
	return retorno;
}

//------------------perdir numero con getFloat---------------------------
int getFloat(char* mensaje,char* mensajeError,int reintentos,float* pResultado){
	int retorno = -1;
	int resultadoScan;
	float bufferFloat;

	printf("%s",mensaje);
	resultadoScan = scanf("%f",&bufferFloat);
	while(!resultadoScan && reintentos > 0){

		printf("\nREINTENTOS: %d \n",reintentos);
		printf("%s",mensajeError);
		fflush(stdin);
		resultadoScan = scanf("%f",&bufferFloat);
		reintentos--;
	}
	if(resultadoScan){
		*pResultado = bufferFloat;
		retorno = 0;
	}

	return retorno;
}
