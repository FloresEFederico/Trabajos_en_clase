/*
 ============================================================================
 Name        : Hola.c
 Author      : FedeFlowers
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {

	/* JS
	 * var numero1;
	 * var numero2;
	 * var resultado
	 */

	/* C
	 * int (son para numeros enteros)
	 * float(son para numeros con coma)
	 * char(para caracteres)
	*/

	int numero1;
	int numero2;
	int resultado;
	int resultadoScan;

	/* JS *//*
	numero1 = parseInt(prompt("Numero1?"));
	numero2 = parseInt(prompt("Numero2?"));
	*/

	/* C */
	/*
	 * printf significa Print file
	 * y scanf lee un archivo scan file, lo que hay que indicarle es a donde queres mandarlo
	 *
	 */
	/*
	 * modificadores que se usan en C:
	 * int es %d
	 * float es %f
	 * char es %c
	 * estos se llaman "mascaras"
	 */

	//printf("Numero 1?");


	/*
	 * scanf tiene dos parametros:
	 * el primero donde se pone la mascara para saber de que tipo
	 * el segundo es DONDE quiero que me deje eso que me consiguio, se le pasa la direccion de memoria de la variable
	 * y la direccion de memoria lleva un "&" adelante
	 */

	printf("Numero 1?");
	fflush(stdin);
	resultadoScan = scanf("%d",&numero1);
	while(resultadoScan == 0)
	{
		printf(" ERROR Numero 1?");
		scanf("%d",&numero1);

	}
	printf("Numero 2?");
	scanf("%d",&numero2);

	resultado = numero1 + numero2;

	//printf("Resultado del Scan: %d\nNumero 1 es: %d\n", resultadoScan,numero1);

	printf("la suma es: %d",resultado);
	return EXIT_SUCCESS;
}

