#ifndef ALUMNO_H_
#define ALUMNO_H_

#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MAX_LEGAJO 9999
#define MIN_LEGAJO 1
#define TRUE 1
#define FALSE 0

typedef struct{
	char nombre[LONG_NOMBRE];
	int legajo;
	int isEmpty;
	int id;
}Alumno;

int alumno_alta(Alumno* pArray,int limite);
int alumno_imprimirTodos(Alumno* pArray,int lenArray);
void alumno_imprimir(Alumno bufferAlumno,int indice);
int alumno_initArray(Alumno* pArray,int lenArray);
int alumno_buscarLibre(Alumno* pArray,int limite);
int alumno_indiceExistente(Alumno* pArray,int limite,int indice);
int alumno_modificar(Alumno* pArray,int limite);
int alumno_baja(Alumno* pArray,int limite);
int alumno_ordenarPorNombre(Alumno* pArray,int limite,int orden);
//FUNCIONES CREADAS 24/09
int alumno_buscarId(Alumno* pArray,int len,int idAlumno);

#endif /* ALUMNO_H_ */

