#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Contrataciones.h"

static int generarIdContratacionNuevo(void);


/**
 * \brief Realiza el alta de un array de Contrataciones solo si el indice corresponde a un Empty
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array de Contratacion
 * \param Pantalla* pArrayPantalla: es el puntero al array de Pantalla
 * \param limitePantalla: es el limite del array de Pantalla
 * \return (-1) ERROR/ (0) Ok
 */


int contratacion_alta(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	int indiceLibre;
	int auxIdPantalla;
	int idPantallaExistente;
	Contratacion bufferContratacion;
	if(pArray != NULL &&  limite > 0)
	{
		indiceLibre = contratacion_buscarLibre(pArray,limite);
		if(indiceLibre != -1 && !pantalla_imprimirTodos(pArrayPantalla,limitePantalla) &&
		   !utn_getNumero(&auxIdPantalla,"\nIngrese id de pantalla a contratar:  ","\nid invalido!\n",MIN_IDPAN,MAX_IDPAN,3))
		{
			idPantallaExistente = pantalla_buscarId(pArrayPantalla,limitePantalla,auxIdPantalla);
			if(idPantallaExistente != -1  &&
			   !utn_getNumero(&bufferContratacion.cantidadDeDias,"\nCantidad de dias(1-100): ","\nCantidad invalida!\n",MIN_DIAS,MAX_DIAS,3) &&
			   !utn_getDireccion(bufferContratacion.nombreArchivo,LONG_ARCHIVO,"\nIngrese Nombre de archivo: ","\nNombre invalido\n",3) &&
			   !utn_getDni(bufferContratacion.cuitCliente,LONG_CUIT,"\nIngrese CUIT del cliente: ","\nCuit invalido!\n",3))

			{
				bufferContratacion.idPantalla = auxIdPantalla;
				bufferContratacion.id = generarIdContratacionNuevo();
				bufferContratacion.isEmpty = FALSE;
				pArray[indiceLibre] = bufferContratacion;
				retorno = 0;
			}
		}
		if(indiceLibre == -1)
		{
			printf("\nNo hay espacios libres!\n");
		}
		if(idPantallaExistente == -1)
		{
			printf("\nEse id de pantalla no existe!\n");
		}
	}
	return retorno;
}


/**
 * \brief imprime al array de Contrataciones que estan cargados
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int contratacion_imprimirTodos(Contratacion* pArray,int lenArray)
{
	int retorno = -1;
	int i;
	int flag = 0;
	if(pArray != NULL &&  lenArray > 0){
		for(i=0;i<lenArray;i++)
		{
			printf("\n-------------CONTRATACIONES--------------\n");
			if(pArray[i].isEmpty == FALSE){
				contratacion_imprimir(pArray[i],i);
				flag = 1;
			}
		}
		if(!flag){
			printf("\nNo hay Contratacions que mostrar\n");
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief imprime Contratacion que este cargado
 * \param Contratacion bufferContratacion: Contratacion
 * \param indice: indice del Contratacion
 */
void contratacion_imprimir(Contratacion buffer,int indice)
{
	printf("\nID: %d   -  cantidad de dias: %d  - Nombre del archivo: %s\nCuit del cliente: %s    -   idPantalla: %d\n\n",buffer.id,buffer.cantidadDeDias,buffer.nombreArchivo,buffer.cuitCliente,buffer.idPantalla);
}

/**
 * \brief inicializa al array de Contratacion
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int contratacion_initArray(Contratacion* pArray,int lenArray)
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
 * \brief busca un indice libre(isEmpty == 1) en el array de Contratacion
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array
 * \return (-1) ERROR / (i) si encontro un indice libre
 */
int contratacion_buscarLibre(Contratacion* pArray,int limite)
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

/**
 * \brief busca un indice existente(isEmpty == 0) en el array de Contratacion
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array
 * \param int indice: el indice a buscar
 * \return (-1) ERROR / (i) si encontro el indice
 */
int contratacion_indiceExistente(Contratacion* pArray,int limite,int indice)
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
 * \brief modifica a una  Contratacion solo si el indice corresponde a un No Empty y existe el id.
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array de Contratacion
 * \param Pantalla* pArrayPantalla: es el puntero al array de Pantalla
 * \param limitePantalla: es el limite del array de Pantalla
 * \return (-1) ERROR/ (0) Ok
 */
int contratacion_modificar(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla)
{
	int retorno = -1;
	char cuitABuscar[LONG_CUIT];
	int existeCuit;
	int idPantallaABuscar;
	int existeIdPantalla;
	int auxCantidadDias;
	if(pArray != NULL && limite > 0)
	{
		if(!utn_getDni(cuitABuscar,LONG_CUIT,"\nIngrese cuit del cliente: ","\nCuit invalido!\n",3))
		{
			existeCuit = contratacion_buscarCuit(pArray,limite,cuitABuscar);
			if(existeCuit != -1 &&
			   !contratacion_mostrarPantallasContratadas(pArray,limite,pArrayPantalla,limitePantalla,cuitABuscar) &&
			   !utn_getNumero(&idPantallaABuscar,"\nIngrese el ID de la pantalla que desea modificar: ","\nID invalido!",MIN_IDPAN,MAX_IDPAN,3))
			{
				existeIdPantalla = pantalla_buscarId(pArrayPantalla,limitePantalla,idPantallaABuscar);
				if(existeIdPantalla != -1 && !utn_getNumero(&auxCantidadDias,"\nIngresar nueva cantidad de dias(1-100): ","\nCantidad invalida!\n",MIN_DIAS,MAX_DIAS,3))
				{
					pArray[existeCuit].cantidadDeDias = auxCantidadDias;
					retorno = 0;
				}
			}
		}

	}
	return retorno;
}

/**
 * \brief da de baja a una Contratacion si el indice corresponde a un no Empty.
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int contratacion_baja(Contratacion* pArray,int limite)
{
	int retorno = -1;
	int idBuscar;
	int existeId;
	if(pArray != NULL && limite > 0){
		contratacion_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija indice de la Contratacion que desea cancelar: ","\nIndice invalido!\n",0,QTY_CONTRATACION-1,3);
		existeId = contratacion_buscarId(pArray,limite,idBuscar);
		if(existeId != -1){
			pArray[idBuscar].isEmpty = TRUE;
			printf("\nSe ha dado de baja la Contratacion!\n");
			retorno = 0;
		}else{
			printf("\nNo se encontro la Contratacion en ese indice\n");
		}
	}
	return retorno;
}
/**
 * \brief ordena las contrataciones por nombre.
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array
 * \param int orden: (0) descendente / (1) ascendente
 * \return (-1) ERROR/ (0) Ok
 */
int contratacion_ordenarPorNombreDeArchivo(Contratacion* pArray,int limite,int orden)
{
	int retorno = -1;
	int i;
	int flagSwap;
	Contratacion bufferContratacion;
	if(pArray != NULL && limite > 0 && (orden == 0 || orden == 1)){
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if((orden == 1 && strncmp(pArray[i].nombreArchivo,pArray[i+1].nombreArchivo,LONG_ARCHIVO) > 0)
					||
				   (orden == 0 && strncmp(pArray[i].nombreArchivo,pArray[i+1].nombreArchivo,LONG_ARCHIVO) < 0))
				{
					bufferContratacion = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = bufferContratacion;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

/**
 * \brief le da un valor al id de una Contratacion y lo incrementa en 1
 * \return idContratacion incrementado en 1
 */
static int generarIdContratacionNuevo(void)
{
	static int idContratacion=999;
	idContratacion++;
	return idContratacion;
}

/**
 * \brief busca que el id pasado por parametro (id) exista dentro del array.En caso de existir, lo retorna.
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array
 * \param int idContratacion el id que se buscara.
 * \return (-1) si no se encontro el id/ (i) si se encontro.
 */
int contratacion_buscarId(Contratacion* pArray,int len,int id)
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

/**
 * \brief busca que el id pasado por parametro (id) exista dentro del array.En caso de existir, lo retorna.
 * \param Contratacion* pArray: es el puntero al array de Contratacion
 * \param int limite: es el limite del array
 * \param char*cuit el cuit que se buscara.
 * \return (-1) si no se encontro el id/ (i) si se encontro.
 */
int contratacion_buscarCuit(Contratacion* pArray,int limite,char* cuit)
{
	int existeCuit = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == FALSE && strncmp(pArray[i].cuitCliente,cuit,LONG_CUIT) == 0)
			{
				existeCuit = i;
				break;
			}
		}
	}
	return existeCuit;
}

int contratacion_mostrarPantallasContratadas(Contratacion* pArray,int limite,Pantalla* pArrayPantalla,int limitePantalla,char* cuit)
{
	int retorno = -1;
	int i;
	int j;
	if(pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0)
	{
		for(i=0;i<limite;i++)
		{
			for(j=0;j<limitePantalla;j++)
			{
				if(pArray[i].isEmpty == FALSE &&
				   pArray[i].idPantalla == pArrayPantalla[j].id &&
				   strncmp(pArray[i].cuitCliente,cuit,LONG_CUIT) == 0)
				{
					pantalla_imprimir(pArrayPantalla[i],i);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

