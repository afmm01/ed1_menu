#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30

typedef struct {
    char nome[TAM];
    float val;
    int qtd;
    int tipo;
} PEDIDO, *PEDPTR;

typedef struct auxf {
    PEDIDO ped;
    struct auxf* prox;
} ELEMENTOF, *PONTF;


typedef struct {
    PONTF inicio;
    PONTF fim;
} FILA;


void iniciarFila(FILA*);
void enfileira(FILA*, PEDIDO);
int desenfileira(FILA*);
void adicionarNaFila(FILA *);
int tamanhoFila(FILA*);
FILA ordernar(FILA *, FILA *);
void emitirNota(char *nome, float val, int qtd, int tam);
void mostrarFila(FILA* f, int tam);