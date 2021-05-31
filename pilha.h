#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

#define TAM 30
#define TAM_DESC 200

typedef struct {
    char nome[TAM];
    char descricao[TAM_DESC];
    float val;
    int tipo;

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
void mostrarRefeicoes(PILHA *p, int tipo);
void incluirElemento(PILHA *p, REGISTRO reg);
void apagarTopo(PILHA* p);
int tamanho(PILHA *p);
REGISTRO buscar(PILHA *p, int pos);
PILHA inverter(PILHA *p);
void palindromo(PILHA *p);

#endif