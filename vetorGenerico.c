#include <stdio.h>
#include <stdlib.h>

int main() {
    void ** vet;
    int tamanho,tipo,i;

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tamanho);
    printf("\nDigite o tipo:\n1- Inteiro\n2-Double\n\n");
    scanf("%i", &tipo);

    if (tipo==1) {
        vet = (int*)malloc(tamanho * sizeof(int));
        for (i=0; i<tamanho; i++) {
            printf("\nDigite um valor (%i/%i): ", i+1,tamanho);
            scanf("%i", (int*)&vet[i]);
        }

        printf("----------------IMPRESSAO DO VETOR----------------\n");

        for (i=0; i<tamanho; i++) {
            printf("%i\n", (int*)vet[i]);
        }

    }

        else if (tipo==2) {
            vet = (double*)malloc(tamanho * sizeof(double));
            for (i=0; i<tamanho; i++) {
                printf("\nDigite um valor (%i/%i): ", i+1,tamanho);
                scanf("%lf", (double*)&vet[i]);
            }

            printf("----------------IMPRESSAO DO VETOR----------------\n");

            for (i=0; i<tamanho; i++) {
                printf("%lf\n", (double*)vet[i]);
            }

        }

            else {
                printf("Tipo invalido\n");
            } 


    
}