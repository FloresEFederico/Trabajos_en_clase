#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantallas.h"

static int generarIdPantallaNuevo(void);


/**
 * \brief Realiza el alta de un Pantalla solo si el indice corresponde a un Empty
 * \param Pantalla* pArray: es el puntero al array de Pantalla
 * \param int limite: es el limite del array
 * \param int indice: es el indice donde se cargara el Pantalla
 * \return (-1) ERROR/ (0) Ok
 */

int pantalla_alta(Pantalla* pArray,int limite)
{
	int retorno = -1;
	int indiceLibre;
	Pantalla bufferPantalla;
	if(pArray != NULL &&  limite > 0){
		indiceLibre = pantalla_buscarLibre(pArray,limite);
		if(indiceLibre != -1 &&
			!utn_getNombre(bufferPantalla.nombre,LONG_NAME,"\nIngrese Nombre de la pantalla: ","\nNombre de pantalla invalido\n",3) &&
			!utn_getNumero(&bufferPantalla.tipo,"\nTipos de pantalla:\n1-Led.\n2-LCD.\nElija que tipo(1-2): ","\nOpcion invalida!\n",1,2,3) &&
			!utn_getDireccion(bufferPantalla.direccion,LONG_DIREC,"\nIngrese la direccion: ","\nDireccion invalida!\n",3) &&
			!utn_getNumeroFloat(&bufferPantalla.precio,"\nIngrese el precio de la publicidad(1000-9999):  ","\nPrecio invalido!\n",MIN_PRECIO,MAX_PRECIO,3)
			)
		{
			bufferPantalla.id = generarIdPantallaNuevo();
			bufferPantalla.isEmpty = FALSE;
			pArray[indiceLibre] = bufferPantalla;
			retorno = 0;
		}
		if(indiceLibre == -1){
			printf("\nNo hay espacios libres!\n");
		}
	}
	return retorno;
}


/**
 * \brief imprime al array de Pantallas que estan cargados
 * \param Pantalla* pArray: es el puntero al array de Pantalla
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int pantalla_imprimirTodos(Pantalla* pArray,int lenArray)
{
	int retorno = -1;
	int i;
	int flag = 0;
	if(pArray != NULL &&  lenArray > 0)
	{
		printf("\n-------------PANTALLAS--------------\n");
		for(i=0;i<lenArray;i++){
			if(pArray[i].isEmpty == FALSE){
				pantalla_imprimir(pArray[i],i);
				flag = 1;
			}
		}
		if(!flag){
			printf("\nNo hay Pantallas que mostrar\n");
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief imprime Pantalla que este cargado
 * \param Pantalla bufferPantalla: Pantalla
 * \param indice: indice del Pantalla
 */
void pantalla_imprimir(Pantalla buffer,int indice)
{
	char strTipo[8];
	if(buffer.tipo == 1)
	{
		strcpy(strTipo,"Led");
	}else{
		strcpy(strTipo,"LCD");
	}
	printf("\nID: %d   -   Nombre: %-11s   -  Tipo: %s   -  precio: %4.2f\nDireccion: %s\n",buffer.id,buffer.nombre,strTipo,buffer.precio,buffer.direccion);
}

/**
 * \brief inicializa al array de Pantalla
 * \param Pantalla* pArray: es el puntero al array de Pantalla
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int pantalla_initArray(Pantalla* pArray,int lenArray)
{
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
 * \brief busca un indice libre(isEmpty == 1) en el array de Pantalla
 * \param Pantalla* pArray: es el puntero al array de Pantalla
 * \param int limite: es el limite del array
 * \return (-1) ERROR / (i) si encontro un indice libre
 */
int pantalla_buscarLibre(Pantalla* pArray,int limite)
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


int pantalla_indiceExistente(Pantalla* pArray,int limite,int indice)
{
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
 * \brief modifica a una  Pantalla solo si el indice corresponde a un No Empty y existe el id.
 * \param Pantalla* pArray: es el puntero al array de Pantalla
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int pantalla_modificar(Pantalla* pArray,int limite)
{
	int retorno = -1;
	int idBuscar;
	int existeId;
	Pantalla auxPantalla;
	if(pArray != NULL && limite > 0){
		pantalla_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija ID de la Pantalla que desea modificar(1000-1999): ","\nID invalido!\n",2000,2999,3);
		existeId = pantalla_buscarId(pArray,limite,idBuscar);
		if(existeId != -1 &&
		   !utn_getCadena(auxPantalla.nombre,LONG_NAME,"\nIngrese Nombre de la pantalla: ","\nNombre de pantalla invalido\n",3) &&
		   !utn_getNumero(&auxPantalla.tipo,"\nTipos de pantalla:\n1-Led.\n2-LCD.\nElija que tipo(1-2): ","\nOpcion invalida!\n",1,2,3) &&
		   !utn_getCadena(auxPantalla.direccion,LONG_DIREC,"\nIngrese la direccion: ","\nDireccion invalida!\n",3) &&
		   !utn_getNumeroFloat(&auxPantalla.precio,"\nIngrese el precio de la publicidad(1000-9999):  ","\nPrecio invalido!\n",MIN_PRECIO,MAX_PRECIO,3)
		  )
		{
			strncpy(pArray[existeId].nombre,auxPantalla.nombre,LONG_NAME);
			pArray[existeId].tipo = auxPantalla.tipo;
			strncpy(pArray[existeId].direccion,auxPantalla.direccion,LONG_NAME);
			pArray[existeId].precio = auxPantalla.precio;
			retorno = 0;
		}
		if(existeId == -1){
			printf("\nEse id no se encontro en ninguna Pantalla\n");
		}
	}
	return retorno;
}

/**
 * \brief da de baja a una Pantalla si el indice corresponde a un no Empty.
 * \param Pantalla* pArray: es el puntero al array de Pantalla
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int pantalla_baja(Pantalla* pArray,int limite)
{
	int retorno = -1;
	int idBuscar;
	int existeId;
	if(pArray != NULL && limite > 0){
		pantalla_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija indice de la Pantalla que desea dar de baja: ","\nIndice invalido!\n",0,QTY_PANTALLA-1,3);
		existeId = pantalla_buscarId(pArray,limite,idBuscar);
		if(existeId != -1){
			pArray[idBuscar].isEmpty = TRUE;
			printf("\nSe ha dado de baja la Pantalla!\n");
			retorno = 0;
		}else{
			printf("\nNo se encontro la Pantalla en ese indice\n");
		}
	}
	return retorno;
}
/**
 * \brief ordena las pantallaes por nombre.
 * \param Pantalla* pArray: es el puntero al array de Pantalla
 * \param int limite: es el limite del array
 * \param int orden: (0) descendente / (1) ascendente
 * \return (-1) ERROR/ (0) Ok
 */
int pantalla_ordenarPorNombre(Pantalla* pArray,int limite,int orden)
{
	int retorno = -1;
	int i;
	int flagSwap;
	Pantalla bufferPantalla;
	if(pArray != NULL && limite > 0 && (orden == 0 || orden == 1)){
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if((orden == 1 && strncmp(pArray[i].nombre,pArray[i+1].nombre,LONG_NAME) > 0)
					||
				   (orden == 0 && strncmp(pArray[i].nombre,pArray[i+1].nombre,LONG_NAME) < 0))
				{
					bufferPantalla = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = bufferPantalla;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

/**
 * \brief le da un valor al id de una Pantalla y lo incrementa en 1
 * \return idPantalla incrementado en 1
 */
static int generarIdPantallaNuevo(void)
{
	static int idPantalla=99;
	idPantalla++;
	return idPantalla;
}

/**
 * \brief busca que el id pasado por parametro (id) exista dentro del array.En caso de existir, lo retorna.
 * \param Pantalla* pArray: es el puntero al array de Pantalla
 * \param int limite: es el limite del array
 * \param int idPantalla el id que se buscara.
 * \return (-1) si no se encontro el id/ (i) si se encontro.
 */
int pantalla_buscarId(Pantalla* pArray,int len,int id)
{
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



