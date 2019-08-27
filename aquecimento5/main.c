#include <stdio.h>
#include "fracao.h"
#include "vetorfracao.h"


int main() {
	TFracao * vet;
	vet = alocaVetFrac(5);
	
	preencheVetFrac(vet,5);

	imprimeVetFrac(vet,5);
}

