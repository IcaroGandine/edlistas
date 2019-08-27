#include "fracao.h"
#include <stdlib.h>
#include <stdio.h>

TFracao * alocaVetFrac(int tam) {
    TFracao * vetFrac; 

    vetFrac = malloc(tam * sizeof(TFracao));

    return vetFrac;
}

void preencheVetFrac(TFracao * vet, int tam) {
    int i=0, d, n;
    TFracao f;

    for (i=0;i<tam;i++) {
        printf("Digite o numerador para a fracao %i / %i: " , i+1, tam);
        scanf("%i", &n);
        printf("\nDigite o denominador para a fracao %i / %i: ", i+1, tam);
        scanf("%i", &d);

        inicFracao(&f,n,d);
        vet[i]=f;
    }

}

void imprimeVetFrac(TFracao * vet, int tam) {
    int i=0;
    for (i=0;i<tam;i++) {
        imprimeFracao(vet[i]);
    }

}