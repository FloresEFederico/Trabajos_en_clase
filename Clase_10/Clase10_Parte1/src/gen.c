#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "gen.h"

static int generarIdGenericoNuevo(void);


/**
 * \brief Realiza el alta de un Generico solo si el indice corresponde a un Empty
 * \param Generico* pArray: es el puntero al array de Generico
 * \param int limite: es el limite del array
 * \param int indice: es el indice donde se cargara el Generico
 * \return (-1) ERROR/ (0) Ok
 */
int gen_alta(Generico* pArray,int limite){
	int retorno = -1;
	int indiceLibre;
	Generico bufferGenerico;
	if(pArray != NULL &&  limite > 0){
		indiceLibre = gen_buscarLibre(pArray,limite);
		if(indiceLibre != -1 && !utn_getCadena(bufferGenerico.nombre,SIZE_GENNAME,"\nIngrese Nombre de gen: ","\nNombre de gen invalido\n",3)
			){
			bufferGenerico.id = generarIdGenericoNuevo();
			bufferGenerico.isEmpty = FALSE;
			pArray[indiceLibre] = bufferGenerico;
			retorno = 0;
		}
		if(indiceLibre == -1){
			printf("\nNo hay espacios libres!\n");
		}
	}
	return retorno;
}


/**
 * \brief imprime al array de Genericos que estan cargados
 * \param Generico* pArray: es el puntero al array de Generico
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int gen_imprimirTodos(Generico* pArray,int lenArray){
	int retorno = -1;
	int i;
	int flag = 0;
	if(pArray != NULL &&  lenArray > 0){
		for(i=0;i<lenArray;i++){
			if(pArray[i].isEmpty == FALSE){
				gen_imprimir(pArray[i],i);
				flag = 1;
			}
		}
		if(!flag){
			printf("\nNo hay Genericos que mostrar\n");
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief imprime Generico que este cargado
 * \param Generico bufferGenerico: Generico
 * \param indice: indice del Generico
 */
void gen_imprimir(Generico buffer,int indice){
	printf("\nIndice: %d   - ID: %d   -   Nombre: %-11s",indice,buffer.id,buffer.nombre);
}

/**
 * \brief inicializa al array de Generico
 * \param Generico* pArray: es el puntero al array de Generico
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int gen_initArray(Generico* pArray,int lenArray){
	int retorno = -1;
	int i;
	if(pArray != NULL &&  lenArray > 0){
		for(i=0;i<lenArray;i++){
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief busca un indice libre(isEmpty == 1) en el array de Generico
 * \param Generico* pArray: es el puntero al array de Generico
 * \param int limite: es el limite del array
 * \return (-1) ERROR / (i) si encontro un indice libre
 */
int gen_buscarLibre(Generico* pArray,int limite)
{
	int indiceLibre = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == 1)
			{
				indiceLibre = i;
				break;
			}
		}
	}
	return indiceLibre;
}


int gen_indiceExistente(Generico* pArray,int limite,int indice){
	int indiceExistente = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == 0 && i == indice)
			{
				indiceExistente = i;
				break;
			}
		}
	}
	return indiceExistente;
}

/**
 * \brief modifica a una  Generico solo si el indice corresponde a un No Empty y existe el id.
 * \param Generico* pArray: es el puntero al array de Generico
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int gen_modificar(Generico* pArray,int limite){
	int retorno = -1;
	int idBuscar;
	int existeId;
	Generico auxGenerico;
	if(pArray != NULL && limite > 0){
		gen_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija ID de la Generico que desea modificar(1000-1999): ","\nID invalido!\n",2000,2999,3);
		existeId = gen_buscarId(pArray,limite,idBuscar);
		if(existeId != -1 && !utn_getCadena(auxGenerico.nombre,SIZE_GENNAME,"\nIngrese nombre nuevo: ","\nNombre invalido!\n",3))
		{

			strncpy(pArray[existeId].nombre,auxGenerico.nombre,SIZE_GENNAME);
			retorno = 0;
		}
		if(existeId == -1){
			printf("\nEse id no se encontro en ninguna Generico\n");
		}
	}
	return retorno;
}

/**
 * \brief da de baja a una Generico si el indice corresponde a un no Empty.
 * \param Generico* pArray: es el puntero al array de Generico
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int gen_baja(Generico* pArray,int limite){
	int retorno = -1;
	int idBuscar;
	int existeId;
	if(pArray != NULL && limite > 0){
		gen_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija indice de la Generico que desea dar de baja: ","\nIndice invalido!\n",0,QTY_GEN-1,3);
		existeId = gen_buscarId(pArray,limite,idBuscar);
		if(existeId != -1){
			pArray[idBuscar].isEmpty = TRUE;
			printf("\nSe ha dado de baja la Generico!\n");
			retorno = 0;
		}else{
			printf("\nNo se encontro la Generico en ese indice\n");
		}
	}
	return retorno;
}
/**
 * \brief ordena las genes por nombre.
 * \param Generico* pArray: es el puntero al array de Generico
 * \param int limite: es el limite del array
 * \param int orden: (0) descendente / (1) ascendente
 * \return (-1) ERROR/ (0) Ok
 */
int gen_ordenarPorNombre(Generico* pArray,int limite,int orden){
	int retorno = -1;
	int i;
	int flagSwap;
	Generico bufferGenerico;
	if(pArray != NULL && limite > 0 && (orden == 0 || orden == 1)){
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if((orden == 1 && strncmp(pArray[i].nombre,pArray[i+1].nombre,SIZE_GENNAME) > 0)
					||
				   (orden == 0 && strncmp(pArray[i].nombre,pArray[i+1].nombre,SIZE_GENNAME) < 0))
				{
					bufferGenerico = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = bufferGenerico;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

/**
 * \brief le da un valor al id de una Generico y lo incrementa en 1
 * \return idGenerico incrementado en 1
 */
static int generarIdGenericoNuevo(void)
{
	static int idGenerico=1999;
	idGenerico++;
	return idGenerico;
}

/**
 * \brief busca que el id pasado por parametro (id) exista dentro del array.En caso de existir, lo retorna.
 * \param Generico* pArray: es el puntero al array de Generico
 * \param int limite: es el limite del array
 * \param int idGenerico el id que se buscara.
 * \return (-1) si no se encontro el id/ (i) si se encontro.
 */
int gen_buscarId(Generico* pArray,int len,int id){
	int existeId = -1;
	int i;
	if(pArray != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty == FALSE && pArray[i].id == id)
			{
				existeId = i;
				break;
			}
		}
	}
	return existeId;
}


