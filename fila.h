#include <stdio.h>
#include <stdlib.h>

typedef struct auxf {
    int val;
    struct auxf* prox;
} ELEMENTOF, *PONTF;


typedef struct {
    PONTF inicio;
    PONTF fim;
} FILA;


void iniciarFila(FILA* f);
void enfileira(FILA* f, int val);
int desenfileira(FILA* f);
void adicionarNaFila(FILA *f);
int tamanhoFila(FILA* f);
FILA ordernar(FILA *f1, FILA *f2);
void mostrarFila(FILA* f);