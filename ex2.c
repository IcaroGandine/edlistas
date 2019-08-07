#include <stdio.h>

typedef struct pessoa {
    char nome[31];
    int idade;
    float altura;

}T_pessoa;

T_pessoa * f_criaVetorPreenchido(T_pessoa vetorPessoas[5]) {
    int i;
    

    for (i=0;i<5;i++) {
        printf("Digite o nome para a pessoa (%i/5): \n", i+1);
        scanf("%c", &vetorPessoas[i].nome);
        printf("Digite a idade para a pessoa (%i/5): \n", i+1);
        scanf("%i", &vetorPessoas[i].idade);
        printf("Digite a altura para a pessoa (%i/5): \n", i+1);
        scanf("%f", &vetorPessoas[i].altura);
    }

    return vetorPessoas;
}

int main() {
   T_pessoa  vetorPessoas[5];
   vetorPessoas = f_criaVetorPreenchido(vetorPessoas);
    
}