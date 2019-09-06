#include <stdio.h>
#include <string.h>
#include "pessoa.h"

void f_preencheVetor(T_Pessoa v[], int tam) {
    int i=0;
    for (i=0;i<tam;i++) {
        printf("Pessoa %i de %i\n", i+1, tam);
        printf("Digite a idade: \n");
        scanf("%i", &(v[i].idade));

        printf("Digite o nome: \n");
        scanf(" %[^\n]", (v[i].nome));

        printf("Digite a altura: \n");
        scanf("%f", &(v[i].altura));

        printf("\n\n");
    }   

}

void f_imprimeVetor(T_Pessoa v[], int tam) {
    int i=0;
    for (i=0;i<tam;i++) {
       printf ("PESSOA %i:\n", i+1);
       printf ("Idade: %i\n", v[i].idade);
       printf ("Nome: %s\n", v[i].nome);
       printf ("Altura: %f\n", v[i].altura);
       printf ("--------------------------------\n\n");
    }

}

void f_ordenaVetorIdade(T_Pessoa v[], int tam) {
    int i=0,j=0;
    T_Pessoa aux;

    for(i=0;i<tam;i++) {

        for(j=i+1;j<tam;j++) {

            if (v[i].idade > v[j].idade) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void f_ordenaVetorAltura(T_Pessoa v[], int tam) {
    int i=0,j=0;
    T_Pessoa aux;

    for(i=0;i<tam;i++) {

        for(j=i+1;j<tam;j++) {

            if (v[i].altura > v[j].altura) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void f_ordenaVetorNome(T_Pessoa v[], int tam) {
    int i=0,j=0;
    T_Pessoa aux;

    for(i=0;i<tam;i++) {

        for(j=i+1;j<tam;j++) {

            if (strcmp(v[i].nome,v[j].nome)>0) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
