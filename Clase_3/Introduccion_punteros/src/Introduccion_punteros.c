/*
 *  PUNTEROS: Son las variables que tienen la direccion de memoria de otra variable
 */
//funcion size of : para saber cuantos bites ocupa un tipo de variable que le indique

#include <stdio.h>
#include <stdlib.h>

int dividir(int operador1,int operador2,float* direccionDeVariableDeRetorno);

int main(void) {
	setbuf(stdout,NULL);
/*
	int a;
	int b;
	int c;
	float d;

	printf("\n---Funcionamiento del Size of---\n");
	printf("el size de 'a' es: %d\n",sizeof(a));
	printf("el size de 'o' es: %d\n",sizeof(b));
	printf("el size de 'e' es: %d\n",sizeof(c));
	printf("el size de 'x' es: %d\n",sizeof(d));
	printf("\n-------------------------------\n");
	printf("\n---Direccion de memoria de variables---\n");
	printf("La direccion de memoria de 'a' es: %p\n",&a);
	printf("La direccion de memoria de 'b' es: %p\n",&b);
	printf("La direccion de memoria de 'c' es: %p\n",&c);
	printf("La direccion de memoria de 'd' es: %p\n",&d);
*/
	/*--------------------------------------------------------
	 * HACER UNA FUNCION QUE EN VEZ DE DEVOLVER EL VALOR POR
	 * EL VALOR DE RETORNO, ME LO DEVUELVA DIRECTO A LA DIRE
	 * CCION DE MEMORIA DE LA VARIABLE(RESULTADO)
	 */
	int a = 27;
	int b = 2;
	float resultado;
	int retHuboError;

	printf("la direccion de resultado en el main es: %p\n", &resultado);
	retHuboError = dividir(a,b,&resultado);

	if(retHuboError){
		printf("\nNo se pudo dividir\n");
	}else{
		printf("\nresultado: %.2f\n",resultado);
	}

	return EXIT_SUCCESS;
}

int dividir(int operador1,int operador2,float* direccionDeVariableDeRetorno){

	float resul;
	int huboError;

	printf("la direccion de resultado en la funcion es: %p", direccionDeVariableDeRetorno);
	if(operador2 != 0){
		resul = (float)operador1/operador2;
		(*direccionDeVariableDeRetorno) = resul;
	//se le pone un * previo la nombre para que acceda al contenido de esa variable que la variable contiene la direccion de memoria de la variable resultado del main
		huboError = 0;
	}else{
		huboError = 1;
	}

	return huboError;
}
