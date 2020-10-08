#ifndef NAC_H_
#define NAC_H_

#define SIZE_NAC 50
#define QTY_NACIONALIDAD 5
#define TRUE 1
#define FALSE 0

typedef struct{
	char nombre[SIZE_NAC];
	int isEmpty;
	int id;
}Nacionalidad;

int nacionalidad_alta(Nacionalidad* pArray,int limite);
int nacionalidad_imprimirTodos(Nacionalidad* pArray,int lenArray);
void nacionalidad_imprimir(Nacionalidad buffer,int indice);
int nacionalidad_initArray(Nacionalidad* pArray,int lenArray);
int nacionalidad_buscarLibre(Nacionalidad* pArray,int limite);
int nacionalidad_indiceExistente(Nacionalidad* pArray,int limite,int indice);
int nacionalidad_modificar(Nacionalidad* pArray,int limite);
int nacionalidad_baja(Nacionalidad* pArray,int limite);
int nacionalidad_ordenarPorNombre(Nacionalidad* pArray,int limite,int orden);
int nacionalidad_buscarId(Nacionalidad* pArray,int len,int id);


#endif /* NAC_H_ */
