#ifndef CLIENTES_H_
#define CLIENTES_H_

#define NOMBRE_LEN 51
#define DNI_LEN 20
#define QTY_CLIENTES 100
#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char nombre[NOMBRE_LEN];
	char dni[DNI_LEN];
	float altura;
	int isEmpty;
}Cliente;

int cli_imprimir(Cliente* auxProducto);
int cli_imprimirArray(Cliente* pArray,int limite);
int cli_inicializarArray(Cliente* pArray,int limite);
int cli_getEmptyIndex(Cliente* pArray,int limite);
int cli_altaArray(Cliente* pArray,int limite);
int cli_buscarId(Cliente* pArray,int limite,int idABuscar);
int cli_modificarArray(Cliente* pArray,int limite);
int cli_bajaArray(Cliente* pArray,int limite);
int cli_ordenarPorNombreYAltura(Cliente* pArray,int limite,int orden);

#endif /* CLIENTES_H_ */

