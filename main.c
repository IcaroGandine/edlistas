/* Ícaro Gandine Fialho Weiler - 20152bsi0315
    */


#include "tadlistade.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	Plista lista;
	Taluno aluno1;
	Taluno aluno2;

	aluno1.matricula = 1010;
	aluno2.matricula = 2020;
	
	lista = init_lst();

	append_lst(lista, aluno1);
    append_lst(lista, aluno2);

	print_lst(lista);

	printf("\n");

	
	
	

}