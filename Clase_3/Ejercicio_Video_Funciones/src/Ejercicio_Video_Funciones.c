/*
 Enunciado: 1 programa que pida un numero de usuario, despues pida una operacion(+,-,*,/) y despues que pida otro numero.
 Segun la operacion ingresada, se llamara a una funcion que ejecute la operacion (sumar(),restar(),multiplicar(),dividir())
 y luego mostrar al usuario el resultado. El mostrar resultado NOOOOO puede estar dentro de las funciones que crean para hacer la operacion.
  En la funcion dividir, validar no dividir por 0
 */

#include <stdio.h>
#include <stdlib.h>


int Sumar(int num1, int num2);
int Restar(int num1, int num2);
int Multiplicar(int num1, int num2);
float Dividir(int num1, int num2);

int main(void) {
	setbuf(stdout,NULL);

	int numero1;
	int numero2;
	int opcion;
	int resultadoScan;
	int resultado;
	float resultadoDeDivision;
	int flag = 1;

	do{
		printf("Ingrese un numero: ");
			resultadoScan = scanf("%d", &numero1);
			while(resultadoScan == 0){
				printf("\nNumero invalido! reingrese el numero: ");
				fflush(stdin);
				resultadoScan = scanf("%d", &numero1);
			}
			printf("\n--------------------------------------\n");
			printf("\nMenu de operaciones: \n"
					"1-Sumar.\n"
					"2-Restar.\n"
					"3-Multiplicar.\n"
					"4-Dividir.\n"
					"0-Salir.\n"
					"Elija una opcion: ");
				resultadoScan = scanf("%d", &opcion);
				while((resultadoScan == 0) || (opcion < 0 || opcion > 4)){
					printf("\nOpcion invalida! reingrese la opcion: ");
					fflush(stdin);
					resultadoScan = scanf("%d", &opcion);
				}
				if(opcion != 0){
					printf("Ingrese el Numero2: ");
					resultadoScan = scanf("%d", &numero2);
					while(resultadoScan == 0){
						printf("\nNumero invalido! reingrese el numero: ");
						fflush(stdin);
						resultadoScan = scanf("%d", &numero2);
					}
				}
				switch(opcion){
				case 1:
					resultado = Sumar(numero1,numero2);
					printf("\nEl resultado de la suma es de: %d\n",resultado);
					break;
				case 2:
					resultado = Restar(numero1,numero2);
					printf("\nEl resultado de la resta es de: %d\n",resultado);
					break;
				case 3:
					resultado = Multiplicar(numero1,numero2);
					printf("\nEl resultado de la multiplicacion es de: %d\n",resultado);
					break;
				case 4:
					if(numero2 == 0){
						printf("\nError! No se puede dividir por 0!\n\n");
					}else{
						resultadoDeDivision = Dividir(numero1,numero2);
						printf("\nEl resultado de la division es de: %.2f\n",resultadoDeDivision);
					}
					break;
				}
				printf("\nDesea continuar?\n1-Si\n0-No\nopcion: ");
				fflush(stdin);
				resultadoScan = scanf("%d", &flag);
				while(resultadoScan == 0 || (flag != 0 && flag != 1)){
					printf("\nNumero invalido! reingrese opcion: ");
					fflush(stdin);
					resultadoScan = scanf("%d", &flag);
				}
	}while(flag);
	printf("\nHasta Luego!\n");
		return EXIT_SUCCESS;
}

int Sumar(int num1, int num2){
	int suma;

	suma = num1+num2;

	return suma;
}
int Restar(int num1, int num2){
	int resta;

	resta = num1-num2;

	return resta;
}
int Multiplicar(int num1, int num2){
	int multiplicacion;

	multiplicacion = num1*num2;

	return multiplicacion;
}
float Dividir(int num1, int num2){
	float division;

	division = (float)num1/num2;

	return division;
}
