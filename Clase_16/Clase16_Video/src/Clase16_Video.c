/*
 ================================================================================
FALTA TERMINAR!!!!!!!!!!!
--------------------LLEGUE HASTA EL MIN 45:47--------------------------------


Punteros a funcion: un puntero a funcion es una variable que almacena la
direccion de una funcion, permitiendo invocar dicha funcion a traves del puntero.

void (*pFuncion)(void) = saludar;

Ejemplo:
-----------------------------------------------------------------------------
----------------------------------------------------------------
1	void saludar(void);
2
3	int main(void) {
4		setbuf(stdout,NULL);
5		void (*pFuncion)(void);
6
7		pFuncion = saludar;
8		pFuncion();
9
10		return EXIT_SUCCESS;
11	}
12
13	void saludar(void)
14	{
15		printf("\nHola\n");
16	}
-----------------------------------------------------------------------------
-----------------------------------------------------------------

Puntero a funcion como parametro de otra funcion

Las funciones tambien pueden pasarse como parametros a otras funciones

int calcular(int parametroA,int parametroB, void(*pFuncion)(int,int,int*))

Ejemplo:
-----------------------------------------------------------------------------
----------------------------------------------------------------
1	void sumar(int parametroA,int parametroB,int* pResultado);
2	void restar(int parametroA,int parametroB,int* pResultado);
3	int calcular(int parametroA,int parametroB,void(*pFuncion)(int,int,int*));
4	int main(void) {
5		setbuf(stdout,NULL);
6		int auxiliar;
7
8		auxiliar = calcular(20,39,sumar);
9		printf("\nLa suma es de: %d", auxiliar);
10		auxiliar = calcular(20,10,restar);
11		printf("\nLa resta es de: %d", auxiliar);
12		return EXIT_SUCCESS;
13	}
14
15	void sumar(int parametroA,int parametroB,int* pResultado)
16	{
17		*pResultado = parametroA+parametroB;
18	}
19	void restar(int parametroA,int parametroB,int* pResultado)
20	{
21		*pResultado = parametroA-parametroB;
22	}
23	int calcular(int parametroA,int parametroB,void(*pFuncion)(int,int,int*))
24	{
25		int resultado;
26		pFuncion(parametroA,parametroB,&resultado);
27		return resultado;
28	}
29
-----------------------------------------------------------------------------
-----------------------------------------------------------------

TIP: se le puede definir un tipo a una funcion pasada por parametro
haciendo lo siguiente:
Ej:
	#include <stdio.h>
	#include <stdlib.h>

	typedef int(*tSaludar)(char*,int);

	int saludo(char* mensaje,int numero,tSaludar pFuncionSaludar);

	int main(void) {

		return EXIT_SUCCESS;
	}
	int saludo(char* mensaje,int numero,tSaludar pFuncionSaludar)
	{
		int retorno = -1;
		if(!pFuncionSaludar(mensaje,numero))
		{
			retorno = 0;
		}
		return retorno;
	}


-----------------------------------------------------------------------------
-----------------------------------------------------------------

Segmento de memoria:
Cada vez que se ejecuta cualquier programa, el mismo debera pasar a memoria
Los programas en memoria cuentan con distintos segmentos y por lo tanto
los datos segun su tipo sera almacenados en alguno de estos

-Segmento de codigo: en este segmento se guardan las instrucciones,
en lenguaje maquina, de nuestro programa.

-Memoria Estatica: En este segmento se guardan las variables globales del programa

-Segmento de Pila (Pila Stack): cada vez que se llama a una funcion entra en este segmento con
toda su informacion y alli se guardan:
*los llamados a las funciones
*los parametros de las funciones
*las variables locales
*Otra informacion necesaria para el funcionamiento del programa.

-Segmento de Heap: En este segmento se guardan las variables que han sido creadas
dinamicamente en tiempo de ejecucion.


-----------------------------------------------------------------------------
-----------------------------------------------------------------
MALLOC----------
Como se reserva memoria de manera dinamica?
de la biblioteca <stdlib.h>, nos concentramos en malloc

void* malloc(unsigned int numBytes);

Devuelve un puntero al tipo de datos void (sin tipo). Dicho puntero puede ser
asignado a una variable puntero de cualquier tipo mediante una conversion
forzada de tipo de datos(casting).

La funcion malloc(), devuelve un puntero nulo (NULL) si la reserva de memoria
no puede realizarse, generalmente por falta de memoria disponible


-----------------------------------------------------------------------------
-----------------------------------------------------------------
REALLOC--------------
El redimensionamiento dinamico de memoria intenta cambiar el tamaño de un
bloque de memoria previamente asignado

void* realloc(void* ptr,unsigned int numBytes);

Si el tamaño del bloque original no puede ser redimensionado, entonces realloc()
intentara asignar un nuevo bloque de memoria y copiara el contenido anterior.

-----------------------------------------------------------------------------
-----------------------------------------------------------------
Liberacion dinamica de memoria:
La memoria dinamica reservada es eliminada siempre al terminar la ejecucion
del programa por el propio sistema operativo. Sin embargo, durante la ejecucion
del programa puede ser interesante, e incluso necesario, proceder a liberar
parte de la memoria reservada con anterioridad

void free(void* ptr);

 ================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


typedef int(*tSaludar)(char*,int);

int saludarEsp(char* mensaje,int numero);
int saludarEng(char* mensaje,int numero);
int saludo(char* mensaje,int numero,tSaludar pFuncionSaludar);


int initArray(int* pArray, int limite, int valor);
int imprimirArray(int* pArray, int limite);
int resizeArray(int** pArray, int* limite, int sizeNuevo);
int main(void) {
	setbuf(stdout,NULL);

	/*Uso de funcion con un parametro que es un puntero a una funcion
	if(!saludo("\nHola\n",22,saludarEsp) &&
	   !saludo("\nHello\n",99,saludarEng))
	{
		printf("\nTodo Perfecto\n");
	}

	//USO DE MALLOC
	int* a = NULL;
	int sizeOfa = 20;
	int i;
	a = (int*)malloc(sizeof(int)*sizeOfa);
	if(a != NULL)
	{
		for(i=0;i<sizeOfa;i++)
		{
			*(a+i) = 0;
		printf("\nDireccion de memoria en indice %d: %p",i,(a+i));
		}
	}
	//USO DE REALLOC
	int* pAux;
	int sizeOfRealloc = 200;
	pAux=(int*)realloc(a,sizeof(int)*sizeOfRealloc);
	if(pAux != NULL)
	{
		a = pAux;
		for(i = 0;i<sizeOfRealloc;i++)
		{
			*(a+i) = 1;
			printf("\nDireccion de memoria en indice %d: %p",i,(a+i));
		}

	}
	//LIBERACION DINAMICA DE MEMORIA CON LA FUNCION free
	free(a);
	free(pAux);*/
//-------------------------------------------------------------------------------
	//OTRO EJEMPLO MAS
	int* pArrayEdades = NULL;
	int sizeArrayEdades = 10;

	pArrayEdades = (int*)malloc(sizeof(int)*sizeArrayEdades);
	if(pArrayEdades != NULL)
	{
		if(!initArray(pArrayEdades,sizeArrayEdades,0))
		{
			printf("\nINIT OK\n");
			imprimirArray(pArrayEdades,sizeArrayEdades);
		}
	}
	if(!resizeArray(&pArrayEdades,&sizeArrayEdades,30))
	{
		printf("\nRESIZE OK\n");
		//initArray(pArrayEdades,sizeArrayEdades,1);
		imprimirArray(pArrayEdades,sizeArrayEdades);
	}

	free(pArrayEdades);
	return EXIT_SUCCESS;
}

int initArray(int* pArray, int limite, int valor)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0 && valor >= 0)
	{
		for(i=0;i<limite;i++)
		{
			*(pArray + i) = valor; // pArray[i] = valor;
		}
		retorno = 0;
	}
	return retorno;
}

int imprimirArray(int* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("%d\n",*(pArray+i));
		}
		retorno = 0;
	}
	return retorno;
}

int resizeArray(int** pArray, int* limite, int sizeNuevo)
{
	int retorno = -1;
	int* pAuxEdades = NULL;

	if(pArray != NULL && limite != NULL && sizeNuevo >= 0)
	{
		pAuxEdades = (int*)realloc(*pArray,sizeof(int)*(sizeNuevo));
		if(pAuxEdades != NULL)
		{
			*limite = sizeNuevo;
			*pArray = pAuxEdades;
			pAuxEdades = NULL;
			retorno = 0;
		}else
		{
			printf("\nNo se consiguio nuevo espacio.\n");
		}
	}
	return retorno;
}


int saludarEsp(char* mensaje, int numero)
{
	printf("%sNumero: %d",mensaje,numero);
	return 0;
}

int saludarEng(char* mensaje,int numero)
{
	printf("%sNumber: %d",mensaje,numero);
	return 0;
}

int saludo(char* mensaje,int numero,tSaludar pFuncionSaludar)
{
	int retorno = -1;
	if(mensaje != NULL &&
	   !pFuncionSaludar(mensaje,numero))
	{
		retorno = 0;
	}
	return retorno;
}

