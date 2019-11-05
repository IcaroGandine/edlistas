#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlistade.h"

/* Ícaro Gandine Fialho Weiler - 20152bsi0315
    */

Plista init_lst(void) {
	
	Plista lista;
	
	lista = (Plista) malloc (sizeof(Tlista));
	
	lista->prim=NULL;
	lista->ulti=NULL;
	lista->tam=0;
	
	return lista;
}


 void print_lst(Plista lista) {
	
	if (lista!=NULL) {
	Tno * no_aux;
	for (no_aux=lista->prim; no_aux!=NULL; no_aux=no_aux->prox) {
		printf("%s\n",no_aux->info);
	}		
	}
}

int empty_lst(Plista lista) {
	if (lista->tam==0) {
		return 1;
	}
	
	else {
		return 0;
	}

}


void append_lst(Plista lst, char nome[50]){
	Pno novo = NULL;
	
	if  (lst != NULL){
		novo = (Pno) malloc(sizeof(Tno));
		novo->ante = NULL;
		novo->prox = NULL;
		
		//novo->info = nome;
		strcpy(novo->info,nome);
		
		if (empty_lst(lst)) {
			lst->prim = novo;
		} else {
			novo->ante = lst->ulti;
			lst->ulti->prox = novo;
		}
		lst->ulti = novo;
		
		lst->tam++;
		
	}
} 

int len_lst(Plista lista) {
	if (lista != NULL) {
		return lista->tam; 
	}
	
	else {
		return -1;
	}
	
}

int in_lst(Plista lista, char * nome) {
	
	Tno * no_aux;
	int pos=0;
	
	if (lista!= NULL) {
	for (no_aux=lista->prim;no_aux!=NULL; no_aux=no_aux->prox) {
		if (no_aux->info==nome) return 1;
		
		pos++;
	}
	
	return 0;

	}
	else return 0;
}


void del_ult_lst(Plista lst){
	Pno aux;
	
	if ((lst != NULL) && (lst->tam > 0)) {
	  aux = lst->ulti;
	  if (lst->tam == 1) {
		lst->prim = NULL;
		lst->ulti = NULL;
	  } else {
	    aux->ante->prox = NULL;
		lst->ulti= aux->ante;
	  }
	  free(aux);
	  lst->tam = lst->tam - 1;
	}
	
}

void del_lst(Plista lst) {
	if (lst != NULL) {
		while (len_lst(lst) > 0)  {
			del_ult_lst(lst);
		}
		free(lst);
	}
} 

/*

void insert_lst(Plista lst, int pos, double elem) {
	if (lst != NULL) {
	
		int i;
		Pno novo, aux;
		
		if (pos<=0) {
			insert_start(lst, elem);
		}

			else if (pos>lista->tam) {
				append_lst(lst, elem);
			}
		
				else {
					for (i=0; i<lst->tam; i++) {
						
					}
					
				}
	
	}

}

*/

void insert_start(Plista lista, char * nome) {
	
	Pno novo; 
	novo = (Pno) malloc(sizeof(Tno));
	novo->ante = NULL;
	//novo->info = nome;
	strcpy(novo->info,nome);
	novo->prox = lista->prim;
	
	if (lista->tam==0) {
		lista->prim = novo;
		lista->ulti = novo;
		lista->tam++;
	}
	
	else {
		lista->prim->ante = novo;
		lista->prim = novo;
		lista->tam++;
		
	}
}

Plista load_lst (FILE * arq) {
	if (arq!=NULL) {
		char nome[50];
		Plista lista;
		lista = init_lst();
		
		while (!feof(arq)) {
			fscanf(arq,"%s",nome);
			append_lst(lista,nome);
			
		}
		
		return lista;
	}

}

void save_lst(Plista lst, FILE * arq) {
	if ((arq!=NULL)&&(lst!=NULL)&&(!empty_lst(lst))) {
		
		char nome [50];
		Pno no_aux = lst->prim;
		while (no_aux!=NULL) {
			//nome = no_aux->info;
			strcpy(nome, no_aux->info);
			fprintf(arq,"%s\n",nome);
			no_aux = no_aux->prox;
		} 
	}
}

void del_pos_lst(Plista lst, int pos) {
 
	
	if (pos<=0) {
		
		Pno aux;
		aux = lst->prim;
		lst->prim = lst->prim->prox;
		free(aux);
		lst->tam--;
	}

	else if (pos >= (lst->tam-1)) {
		del_ult_lst(lst);
	}

		else {
			int i;
			Pno atual = lst->prim;
			Pno proximo,anterior;

			for (i=0; i<pos; i++) {
				atual = atual->prox;
			}

			proximo=atual->prox;
			anterior = atual->ante;

			anterior->prox = proximo;
			proximo->ante = anterior;

			free(atual);
			lst->tam--;
		}

}

int index_lst(Plista lista, char * nome) {
	Pno aux = lista->prim;
	int pos = 0;
	while (aux!=NULL) {
		if (aux->info == nome) return pos;
		pos++;
		aux = aux->prox;
	}

	return -1; 
}

void del_info_lst(Plista lst, char * nome) {
	int pos;

	pos = index_lst(lst,nome);

	if (pos >= 0 ) {
		del_pos_lst(lst,pos);
	}
}

char * get_pos_lst(Plista lst, int pos) {
	int i;
	if (pos>(lst->tam)-1) {
		printf ("Posicao nao existente \n");
		return;
	}
	Pno aux = lst->prim;

	for (i=0; i<pos; i++) {
		aux = aux->prox;
	}

	return aux->info;
}

void insert_ord_lst(Plista lst, char * nome) {
	Pno aux = lst->prim;
	Pno anterior,novo;
	
	
	
	if (strcmp(nome,lst->ulti->info)>0) {
		append_lst(lst,nome);
	}
	
		else if((strcmp(nome,lst->prim->info)<0) || (lst->tam == 0)) {
			insert_start(lst,nome);
		}
		
			else {
				
				novo = (Pno) malloc(sizeof(Tno));
				while (strcmp(nome,aux->info)>0) {
					aux = aux->prox;
				}
				anterior = aux->ante;
				
				novo->prox = aux;
				novo->ante = anterior;
				
				aux->ante = novo;
				anterior->prox = novo;
				
			}
	
	
}