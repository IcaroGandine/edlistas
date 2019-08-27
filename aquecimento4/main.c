#include <stdio.h>
#include "fracao.h"


int main() {
	TFracao f1,f2,f3;
	
    inicFracao(&f1,1,5);
	inicFracao(&f2,3,2);
	diviFracao(f1,f2,&f3);
	imprimeFracao(f3);
	
	
}

// 1/5 / 3/2

// 1/5 * 2/3  = 2/15