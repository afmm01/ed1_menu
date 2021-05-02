#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

#define TAM 30

typedef struct {
    char nome[TAM];
    float val;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT topo;
} PILHA;


void iniciarPilha(PILHA *p);
void mostrarPilha(PILHA *p);
void incluirElemento(PILHA *p, REGISTRO reg);
void apagarTopo(PILHA* p);
int tamanho(PILHA *p);
REGISTRO buscar(PILHA *p, int pos);
PILHA inverter(PILHA *p);
void palindromo(PILHA *p);

#endif