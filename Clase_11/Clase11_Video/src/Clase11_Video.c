#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	char dni[12];
	char direccion[100];
	while(1)
	{
		if(!utn_getDni(dni,sizeof(dni),"Ingrese DNI: ","\nDNI invalido!\n",3) &&
				!utn_getDireccion(direccion,sizeof(direccion),"\nIngrese direccion: ","\nDireccion invalida!\n",3))
		{
			printf("\nDNI: %s\n"
					"Direccion: %s\n",dni,direccion);
		}else
		{
			printf("\nERROR\n");
		}
	}
	return EXIT_SUCCESS;
}
