#ifndef PANTALLAS_H_
#define PANTALLAS_H_

#define LONG_NAME 50
#define LONG_DIREC 100
#define QTY_PANTALLA 5
#define MIN_PRECIO 1000
#define MAX_PRECIO 9999
#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char nombre[LONG_NAME];
	int tipo;
	float precio;
	char direccion[LONG_DIREC];
	int isEmpty;
}Pantalla;

int pantalla_alta(Pantalla* pArray,int limite);
int pantalla_imprimirTodos(Pantalla* pArray,int lenArray);
void pantalla_imprimir(Pantalla buffer,int indice);
int pantalla_initArray(Pantalla* pArray,int lenArray);
int pantalla_buscarLibre(Pantalla* pArray,int limite);
int pantalla_indiceExistente(Pantalla* pArray,int limite,int indice);
int pantalla_modificar(Pantalla* pArray,int limite);
int pantalla_baja(Pantalla* pArray,int limite);
int pantalla_ordenarPorNombre(Pantalla* pArray,int limite,int orden);
int pantalla_buscarId(Pantalla* pArray,int len,int id);

int pantalla_altaForzada(Pantalla* pArray,int limite,char* nombre,int tipo,float precio,char* direccion);
#endif /* PANTALLAS_H_ */
