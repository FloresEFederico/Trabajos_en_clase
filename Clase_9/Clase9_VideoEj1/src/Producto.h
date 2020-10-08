#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#define LONG_NAME 51
#define LONG_DESCRIPCION 100
#define QTY_PRODUCTOS 10
#define MIN_PRECIO 1000
#define MAX_PRECIO 7000
#define TRUE 1
#define FALSE 0
typedef struct
{
	int id;
	char nombre[LONG_NAME];
	char descripcion[LONG_DESCRIPCION];
	float precio;
	int isEmpty;
}Producto;

int producto_alta(Producto* pArray,int limite);
int producto_imprimirTodos(Producto* pArray,int lenArray);
void producto_imprimir(Producto buffer,int indice);
int producto_initArray(Producto* pArray,int lenArray);
int producto_buscarLibre(Producto* pArray,int limite);
int producto_indiceExistente(Producto* pArray,int limite,int indice);
int producto_indiceLibre(Producto* pArray,int limite,int indice);
int producto_modificar(Producto* pArray,int limite);
int producto_baja(Producto* pArray,int limite);
int producto_ordenarPorNombre(Producto* pArray,int limite,int orden);
int producto_buscarId(Producto* pArray,int len,int id);


//----------HECHO para ejercicio 4
int producto_cargarProductoPorIndice(Producto* pArray,int len,int indiceElegido);


#endif /* PRODUCTO_H_ */
