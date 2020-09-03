/*
 ============================================================================
 Name        : funciones_video.c
 Author      : Flores Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
	 * Funciones:
	 * -Permite abstraer codigo
	 * -Permite simplificar codigo
	 * -Permite reutilizar codigo
	 * -Facilita mantener el programa
*/
//aca van todos los prototipos de funciones

//_-------------------------------
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
//prototipos de funciones:

int sumarConLimite(int operador1,int operador2); // prototipo

//-----------------------------------------------------
int main(void) {
	setbuf(stdout,NULL);

	int num1;
	int num2;
	int resultado;

	printf("Ingrese valor del primer numero: ");
	scanf("%d", &num1);
	printf("\nIngrese valor del segundo numero: ");
	scanf("%d", &num2);
	resultado = sumarConLimite(num1,num2);
	printf("\n-----------------------------------\n");
	printf("\nEl resultado es: %d", resultado);

	return EXIT_SUCCESS;
}

// funcoines auxiliares de mi programa

//definicion de la funcion sumarConLimite
//1°Tipo 2°Nombre de la funcion 3°Argumentos:a-Tipo,b-Nombre.(Sino Void)
int sumarConLimite(int operador1,int operador2)
{
	// codigo de mi funcion
	int resultado; // variable local de la funcion (una vez que se vuelve al main, esta variable muere)

	resultado = operador1+operador2;
	if(resultado > 100){
		resultado = 100;
	}

	return resultado; //restorna el valor
}
