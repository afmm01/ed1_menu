#include "fila.h"

void iniciarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileira(FILA* f, PEDIDO ped){
    PONTF novo = (PONTF) malloc(sizeof(ELEMENTOF));
    novo->ped = ped;
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
        printf("Erro! A fila de pedidos esta vazia.\n");
        return 0;
    }
    printf("Pedido %s foi entregue com sucesso\n", f->inicio->ped.nome);
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

void emitirNota(char *nome, float val, int qtd, int tam) {
    int espaco = (tam - strlen(nome)) / 2;
    printf("%s%*s%*s%d x %.2f\n", nome, espaco, "", espaco, "", qtd, val);
}

void mostrarFila(FILA* f, int tam){
 PONTF end = f->inicio;
  while (end != NULL){
    emitirNota(end->ped.nome, end->ped.val, end->ped.qtd, tam);
    end = end->prox;
  }
  printf("\n");
}