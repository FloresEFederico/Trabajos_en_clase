#ifndef GEN_H_
#define GEN_H_

#define SIZE_GENNAME 50
#define QTY_GEN 5
#define TRUE 1
#define FALSE 0

typedef struct{
	char nombre[SIZE_GENNAME];
	int isEmpty;
	int id;
}Generico;

int gen_alta(Generico* pArray,int limite);
int gen_imprimirTodos(Generico* pArray,int lenArray);
void gen_imprimir(Generico buffer,int indice);
int gen_initArray(Generico* pArray,int lenArray);
int gen_buscarLibre(Generico* pArray,int limite);
int gen_indiceExistente(Generico* pArray,int limite,int indice);
int gen_modificar(Generico* pArray,int limite);
int gen_baja(Generico* pArray,int limite);
int gen_ordenarPorNombre(Generico* pArray,int limite,int orden);
int gen_buscarId(Generico* pArray,int len,int id);


#endif /* GEN_H_ */
