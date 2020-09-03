/*
 *----------Funciones!---------
 *Bibliotecas: Todas las funciones que tengan que ver con algo
 *				estaran acomodadas en las bibliotecas
 */
#include <stdio.h> //en algun lugar esta la biblioteca de stdio.c con todas las funciones de stdio.h
#include <stdlib.h>

int sumarEnteros(int operadorA,int operadorB);//Prototipo/Firma
//un prototipo mas profesional no necesita que nombres los parametros
//ya le alcanza con los tipos nomas
//ejemplo: int sumarEnteros(int,int);

int dividirEnteros(int operadorA,int operadorB,float* resultado);


int main(void) {
	setbuf(stdout,NULL);

	float resultado;

	if(!dividirEnteros(14,22,&resultado)){
		printf("El resultado es: %.2f",resultado);
	}else{
		printf("\nHubo un error!\n");
	}

	return EXIT_SUCCESS;
}



int sumarEnteros(int operadorA,int operadorB)//Desarrollo de la funcion
{
	int resultado;
	resultado = operadorA+operadorB;
	return resultado;
}

int dividirEnteros(int operadorA,int operadorB,float* resultado)
{
	int retorno = 1;

	if(operadorB != 0){
		*resultado =(float)operadorA/operadorB;
		retorno = 0;
	}

	return retorno;
}
