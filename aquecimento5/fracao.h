#ifndef FRACAO_H
#define FRACAO_H

typedef struct Fracao {
    int n;
    int d;
}TFracao;

void inicFracao(TFracao * f, int n, int d); // testado

void imprimeFracao(TFracao f); // testado

void simplificaFracao(TFracao * f ); // testado

void somaFracao(TFracao f1, TFracao f2, TFracao * f3); // testado

void multFracao(TFracao f1, TFracao f2, TFracao * f3); // testado

void diviFracao(TFracao f1, TFracao f2, TFracao * f3); // testado

#endif