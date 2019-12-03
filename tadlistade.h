#include <stdio.h>

/* Ícaro Gandine Fialho Weiler - 20152bsi0315
    */

/* primeira solução */
/*struct no {
	double info;
	struct no * ante;
	struct no * prox;
}
typedef struct no Tno, * Pno; */
	
/* segunda solução */
typedef struct aluno {

  int matricula; /* chave */

  char nome[81];

  char turma;

  char email[41];

} Taluno;

typedef struct no{
    Taluno info;
    struct no * ante;
    struct no * prox;
} Tno, * Pno ;
	
typedef struct {
	Tno * prim;
	Tno * ulti;
	int tam;
} Tlista, * Plista;



/*Criar **************************************/
/*pré-condição: não existe
  pós-condição: retorna um endereço diferente de NULL
*/
Plista init_lst(void); 


/*Consultar **********************************/

/*pré-condição: lst diferente de NULL
  pós-condição: int >= 0 - consultar e retornar o campo tam
				int < 0 - se não pré-condição*/
int len_lst(Plista lst);


/*pré-condição: lst diferente de NULL
  pós-condição: int 1 - o campo tam > 0 e elem estiver na lista
				int 0 - se não pré-condição ou
				      - tam = 0 ou 
				      - tam > 0 e elem não estiver na lista*/
int in_lst(Plista lst, Taluno elem);

/*pré-condição: lst diferente de NULL
  pós-condição: int 1 - o campo tam = 0 
				int 0 - se não pré-condição ou
				      - tam > 0
int empty_lst(Plista lst);*/

/* pré-condição: lst diferente de NULL
  pós-condição: imprime todos os elementos da lista*/
void print_lst(Plista lst);
  

/*Alterar ************************************/

/*pré-condição: lst diferente de NULL
  pós-condição: se vazia - 
				se não vazia -
*/
void append_lst(Plista lst, Taluno elem);

/*void append_lst(Plista lst, Taluno elem){
	Pno novo = NULL;
	
	if  (lst != NULL){
		novo = (Pno) calloc(1, sizeof(Tno));
		
		//novo = (Pno) malloc(sizeof(Tno));
		//novo->ante = NULL;
		//novo->prox = NULL;
		
		novo->info = elem;
		if (empty_lst(lst)) {
			lst->prim = novo;
		} else {
			novo->ante = lst->ulti;
			lst->ulti->prox = novo;
		}
		lst->ulti = novo;
		lst->tam = lst->tam + 1;
		//lst->tam += 1;
		//lst->tam++;
		//++lst->tam; 
		
	}
} */


/*pré-condição: lst diferente de NULL
  pós-condição: se pos <=0 elem é 
                   inserido na posição 0
				se pos >=n n=tamanho 
				   elem é inserido na posição na
				se 0<pos<n elem é inserido em 
				   uma posição 0<pos<n
*/
void insert_lst(Plista lst, int pos, Taluno elem);



/*Destruir ***********************************/

void del_ult_lst(Plista lst);


/*pré-condição: lst diferente de NULL
  pós-condição: se tam=0 liberar memória do cabeçalho
				se tam>0 liberar a memória de cada nó
                         da lista e por último 
						 liberar a área de memória
						 do cabeçalho da lista.
*/
void del_lst(Plista lst);


void insert_start(Plista lista, Taluno elem);


Plista load_lst (FILE * arq);


void save_lst(Plista lst, FILE * arq);

void del_pos_lst(Plista lst, int pos);

int index_lst(Plista lista, Taluno elem);

void del_info_lst(Plista lst, Taluno elem);

double get_pos_lst(Plista lst, int pos);
