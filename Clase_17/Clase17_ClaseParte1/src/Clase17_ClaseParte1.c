#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct{
	int id;
	char name[32];
}Cliente;

Cliente* cli_newConParametros(int id, char* name);

int main(void) {
	setbuf(stdout,NULL);

	return EXIT_SUCCESS;
}

Cliente* cli_newConParametros(int id, char* name)
{
	Cliente* pc;
	if(id >= 0 &&  name != NULL)
	{
		pc = (Cliente*)malloc(sizeof(Cliente));
		if(pc != NULL)
		{
			pc->id = id;
			strncpy(pc->name,name,sizeof(pc->name)-1);
		}
	}
	return pc;
}
