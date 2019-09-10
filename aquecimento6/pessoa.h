#include <stdio.h>
#include <string.h>

typedef struct Endereco {
    char rua[41];
    int numero;
    long int cep;
}T_End;

typedef struct Pessoa {
    char nome[31];
    char cpf[12];
    int idade;
    T_End endereco;
}T_Pessoa;

void f_preencheVetor(T_Pessoa v[], int tam); // preenche um vetor de structs lendo os dados do teclado

void f_imprimeVetor(T_Pessoa v[], int tam); // imprime o vetor de structs

void f_ordenaVetorIdade(T_Pessoa v[], int tam); // ordena o vetor por idade

void f_ordenaVetorAltura(T_Pessoa v[], int tam); // ordena o  vetor por altura

void f_ordenaVetorNome(T_Pessoa v[], int tam); // ordena o vetor por nome 