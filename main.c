/* Ícaro Gandine Fialho Weiler - 20152bsi0315
    */


#include "tadlistade.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	Plista lista;
	char * nome;

	lista = init_lst();

	insert_ord_lst(lista, "jorge");
    /*
	insert_ord_lst(lista, "ana");
	insert_ord_lst(lista, "celso ");
	insert_ord_lst(lista, "moises do berrante");
	*/
	
	print_lst(lista);

	printf("\n");

	nome = get_pos_lst(lista,10);

	printf("%s", nome);
	

}