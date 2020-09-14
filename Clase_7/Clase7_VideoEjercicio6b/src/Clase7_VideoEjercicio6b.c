/*
 ========================================================================================
Ejercicio 6b:
Dado el texto almacenado en el array de char"texto". Realizar una funcion que
 reciba un array de char y su longitud, y devuelva por referencia la cantidad
 de palabras encontradas y probarla con dicho texto.
 ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarPalabras(char cadena[],int len,int* pPalabras);


int main(void) {
	setbuf(stdout,NULL);
	char texto[] = "hola me llamo federico";
	int palabras;

	if(!contarPalabras(texto,sizeof(texto),&palabras)){
		printf("Cantidad de palabras contadas: %d",palabras);
	}
	return EXIT_SUCCESS;
}

int contarPalabras(char cadena[],int len,int* pPalabras){
	int retorno = -1;
	int i;
	int contadorDePalabras = 0;
	if(cadena != NULL && pPalabras != NULL && len > 0){
		for(i=0;i<len && cadena[i] != '\0';i++){
			if(cadena[i+1] == ' ' || cadena[i+1] == '\0'){
				contadorDePalabras++;
			}
		}
		*pPalabras = contadorDePalabras;
		retorno = 0;
	}
	return retorno;
}

