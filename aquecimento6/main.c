#include <stdio.h>
#include "pessoa.h" 
#define TAM 5

int main( int argc, char *argv[ ] ) {
    T_Pessoa * v[TAM];
    int campo, i;
    char * nomeArquivo;
    char * dadosPessoa;

    nomeArquivo=argv[1];

    FILE * P_Arquivo;

    P_Arquivo=fopen(nomeArquivo,"r");

    if (P_Arquivo==NULL) {
        printf("\nErro ao abrir arquivo!\n");
    }

    else {
        printf ("\nArquivo aberto com sucesso!\n");

    }

    while (fgets(dadosPessoa,41,P_Arquivo)!=NULL) {
        switch(campo) {
            case 1:
                strcpy(v[i].nome,dadosPessoa);
                break;
            
            case 2:
                v[i].cpf=dadosPessoa
                break;

            case 3:
                

        }

    }



}