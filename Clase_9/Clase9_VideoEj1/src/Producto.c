#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"

static int generarIdProductoNuevo(void);

//-----------------PARA EL EJERCICIO 2 DE CLASE 9-------------------------------------
int producto_PrecioDescuento(Producto* pResult);//utilizada en alta

/**
 * \brief Realiza el alta de un Producto solo si el indice corresponde a un Empty
 * \param Producto* pArray: es el puntero al array de Producto
 * \param int limite: es el limite del array
 * \param int indice: es el indice donde se cargara el Producto
 * \return (-1) ERROR/ (0) Ok
 */
int producto_alta(Producto* pArray,int limite){
	int retorno = -1;
	int indiceLibre;
	Producto bufferProducto;
	if(pArray != NULL &&  limite > 0){
		indiceLibre = producto_buscarLibre(pArray,limite);
		if(indiceLibre != -1 &&
			!utn_getNombre(bufferProducto.nombre,LONG_NAME,"\nIngrese Nombre de producto: ","\nNombre de producto invalido\n",3) &&
			!utn_getCadena(bufferProducto.descripcion,LONG_DESCRIPCION,"\nIngrese la descripcion de producto: ","\nDescripcion invalida!\n",3) &&
			!utn_getNumeroFloat(&bufferProducto.precio,"\nIngrese el precio del producto(1000-7000): ","\nPrecio invalido!\n",MIN_PRECIO,MAX_PRECIO,3) &&
			!producto_PrecioDescuento(&bufferProducto)
			){
			bufferProducto.id = generarIdProductoNuevo();
			bufferProducto.isEmpty = FALSE;
			pArray[indiceLibre] = bufferProducto;
			retorno = 0;
		}
		if(indiceLibre == -1){
			printf("\nNo hay espacios libres!\n");
		}
	}
	return retorno;
}

/**
 * \brief imprime al array de Productos que estan cargados
 * \param Producto* pArray: es el puntero al array de Producto
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int producto_imprimirTodos(Producto* pArray,int lenArray){
	int retorno = -1;
	int i;
	int flag = 0;
	if(pArray != NULL &&  lenArray > 0){
		for(i=0;i<lenArray;i++){
			if(pArray[i].isEmpty == FALSE){
				producto_imprimir(pArray[i],i);
				flag = 1;
			}
		}
		if(!flag){
			printf("\nNo hay Productos que mostrar\n");
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief imprime Producto que este cargado
 * \param Producto bufferProducto: Producto
 * \param indice: indice del Producto
 */
void producto_imprimir(Producto buffer,int indice){
	printf("\nId: %d   - Precio: %.2f   -   Nombre: %-11s\nDescripcion del producto: %s\n\n",buffer.id,buffer.precio,buffer.nombre,buffer.descripcion);
}

/**
 * \brief inicializa al array de Producto
 * \param Producto* pArray: es el puntero al array de Producto
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int producto_initArray(Producto* pArray,int lenArray){
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
 * \brief busca un indice libre(isEmpty == 1) en el array de Producto
 * \param Producto* pArray: es el puntero al array de Producto
 * \param int limite: es el limite del array
 * \return (-1) ERROR / (i) si encontro un indice libre
 */
int producto_buscarLibre(Producto* pArray,int limite)
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


int producto_indiceExistente(Producto* pArray,int limite,int indice){
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


int producto_indiceLibre(Producto* pArray,int limite,int indice){
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == 1 && i == indice)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief modifica a una  Producto solo si el indice corresponde a un No Empty y existe el id.
 * \param Producto* pArray: es el puntero al array de Producto
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int producto_modificar(Producto* pArray,int limite){
	int retorno = -1;
	int idBuscar;
	int existeId;
	Producto auxProducto;
	if(pArray != NULL && limite > 0){
		producto_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija ID de la Producto que desea modificar(1000-1999): ","\nID invalido!\n",2000,2999,3);
		existeId = producto_buscarId(pArray,limite,idBuscar);
		if(existeId != -1 && !utn_getCadena(auxProducto.nombre,LONG_NAME,"\nIngrese nombre nuevo: ","\nNombre invalido!\n",3))
		{

			strncpy(pArray[existeId].nombre,auxProducto.nombre,LONG_NAME);
			retorno = 0;
		}
		if(existeId == -1){
			printf("\nEse id no se encontro en ninguna Producto\n");
		}
	}
	return retorno;
}

/**
 * \brief da de baja a una Producto si el indice corresponde a un no Empty.
 * \param Producto* pArray: es el puntero al array de Producto
 * \param int limite: es el limite del array
 * \return (-1) ERROR/ (0) Ok
 */
int producto_baja(Producto* pArray,int limite){
	int retorno = -1;
	int idBuscar;
	int existeId;
	if(pArray != NULL && limite > 0){
		producto_imprimirTodos(pArray,limite);
		utn_getNumero(&idBuscar,"\nElija indice de la Producto que desea dar de baja: ","\nIndice invalido!\n",0,QTY_PRODUCTOS-1,3);
		existeId = producto_buscarId(pArray,limite,idBuscar);
		if(existeId != -1){
			pArray[idBuscar].isEmpty = TRUE;
			printf("\nSe ha dado de baja la Producto!\n");
			retorno = 0;
		}else{
			printf("\nNo se encontro la Producto en ese indice\n");
		}
	}
	return retorno;
}
/**
 * \brief ordena las productoes por nombre.
 * \param Producto* pArray: es el puntero al array de Producto
 * \param int limite: es el limite del array
 * \param int orden: (0) descendente / (1) ascendente
 * \return (-1) ERROR/ (0) Ok
 */
int producto_ordenarPorNombre(Producto* pArray,int limite,int orden){
	int retorno = -1;
	int i;
	int flagSwap;
	Producto bufferProducto;
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
					bufferProducto = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = bufferProducto;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

/**
 * \brief le da un valor al id de una Producto y lo incrementa en 1
 * \return idProducto incrementado en 1
 */
static int generarIdProductoNuevo(void)
{
	static int idProducto=1999;
	idProducto++;
	return idProducto;
}

/**
 * \brief busca que el id pasado por parametro (id) exista dentro del array.En caso de existir, lo retorna.
 * \param Producto* pArray: es el puntero al array de Producto
 * \param int limite: es el limite del array
 * \param int idProducto el id que se buscara.
 * \return (-1) si no se encontro el id/ (i) si se encontro.
 */
int producto_buscarId(Producto* pArray,int len,int id){
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

//-----------------PARA EL EJERCICIO 2 DE CLASE 9-------------------------------------

int producto_PrecioDescuento(Producto* pResult)
{
	int retorno = -1;
	char respuesta;
	float descuento;
	float precioConDescuento;
	if(!utn_getCaracter(&respuesta,"\nDesea aplicar un descuento del 25% al producto?\n(s/n): ","\nRespuesta invalida!\n",'n','s',3))
	{
		if(respuesta == 's')
		{
			descuento = pResult->precio * 0.25;
			printf("\ndescuento: %.2f\n",descuento);
			precioConDescuento = pResult->precio - descuento;
			printf("\nPrecio final con descuento: %.2f\n",precioConDescuento);
			pResult->precio = precioConDescuento;
		}else
		{
			printf("\nNo se le desconto el descuento\n");
		}
		retorno = 0;
	}
	return retorno;
}

int producto_cargarProductoPorIndice(Producto* pArray,int len,int indiceElegido)
{
	int retorno = -1;
	int estaLibre = producto_indiceLibre(pArray,len,indiceElegido);
	Producto bufferProducto;
	if(pArray != NULL && len > 0 && estaLibre != -1)
	{
		if( !utn_getNombre(bufferProducto.nombre,LONG_NAME,"\nIngrese Nombre de producto: ","\nNombre de producto invalido\n",3) &&
			!utn_getCadena(bufferProducto.descripcion,LONG_DESCRIPCION,"\nIngrese la descripcion de producto: ","\nDescripcion invalida!\n",3) &&
			!utn_getNumeroFloat(&bufferProducto.precio,"\nIngrese el precio del producto(1000-7000): ","\nPrecio invalido!\n",MIN_PRECIO,MAX_PRECIO,3) &&
			!producto_PrecioDescuento(&bufferProducto)
			){
			bufferProducto.id = generarIdProductoNuevo();
			bufferProducto.isEmpty = FALSE;
			pArray[indiceElegido] = bufferProducto;
			retorno = 0;
		}
	}

		return retorno;
}

