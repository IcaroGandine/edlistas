#include <stdio.h>
#include <string.h>
#include "fracao.h"

void inicFracao(TFracao * f, int n, int d) {
	
	f->n=n;
	f->d=d;

}

void imprimeFracao(TFracao f) {
	printf ("%i/%i\n", f.n,f.d);
}


void simplificaFracao(TFracao * f ) {
	int n1,n2,resto;
	n1=f->n;
	n2=f->d;
	
    resto=n1%n2;
    while(resto!=0) {
		n1=n2;
		n2=resto;
		resto=n1%n2;         
	}
    
	f->n=f->n/n2;
	f->d=f->d/n2;
	
}

void somaFracao(TFracao f1, TFracao f2, TFracao * f3) {
	int novoD = 1, multiplicador=1;
	
	novoD = f1.d * f2.d;
	
	multiplicador = novoD/f1.d;
	f1.n=(f1.n) * multiplicador;
	
	multiplicador = novoD/f2.d;
	f2.n=(f2.n) * multiplicador;
	
	f3->n=(f1.n) + (f2.n);
	
	f3->d = novoD;
	
	simplificaFracao(f3);
	
}


void multFracao(TFracao f1, TFracao f2, TFracao * f3) {
	f3->n = f1.n * f2.n;
	f3->d = f1.d * f2.d;
	
	simplificaFracao(f3);
}

void diviFracao(TFracao f1, TFracao f2, TFracao * f3) {
	f3->n = f1.n * f2.d;
	f3->d = f1.d * f2.n;
	
	simplificaFracao(f3);
}


