#include "fila.h"

void iniciarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileira(FILA* f, int val){
    PONTF novo = (PONTF) malloc(sizeof(ELEMENTOF));
    novo->val = val;
    novo->prox = NULL;
    if(f->inicio==NULL){
        f->inicio = novo;
    } else { 
        f->fim->prox = novo;
    }
    f->fim = novo;
}

int desenfileira(FILA* f){
    if(f->inicio==NULL){
        printf("Erro! A fila esta vazia.\n");
        return 0;
    }
    printf("Valor %d saiu da fila\n", f->inicio->val);
    PONTF apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if(f->inicio == NULL){
        f->fim = NULL;
    }
    return 1;
}

int tamanhoFila(FILA* f) {
  PONTF end = f->inicio;
  int tam = 0;
  while (end != NULL){
    tam++;
    end = end->prox;
  }
  return tam;
}

void mostrarFila(FILA* f){
 PONTF end = f->inicio;
  while (end != NULL){
    printf("[%d]", end->val);
    end = end->prox;
  }
  printf("\n");
}