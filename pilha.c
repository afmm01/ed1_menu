#include "pilha.h"

#define TAM 30
 

void iniciarPilha(PILHA *p) {
    p->topo = NULL;
}

void mostrarPilha(PILHA *p) {
    PONT end = p->topo;
    while (end != NULL) {
      printf("--------------------------------------\n");
      printf("Nome do prato: ");
      for(int i=0;i<TAM;i++) printf("%c", end->reg.nome[i]);
      printf("\nValor: %.2f\n", end->reg.val);
      end = end->prox;
    }
    printf("\n");
}

void mostrarRefeicoes(PILHA *p, int tipo) {
    PONT end = p->topo;
    while (end != NULL) {
      if(end->reg.tipo==tipo){
        printf("--------------------------------------\n");
        printf("Nome do prato: ");
        for(int i=0;i<TAM;i++) printf("%c", end->reg.nome[i]);
        printf("\nValor: %.2f\n", end->reg.val);
      }
      end = end->prox;              
    }
    printf("\n");
}

void incluirElemento(PILHA *p, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
}

void apagarTopo(PILHA* p) {
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
}

int tamanho(PILHA *p) {
    PONT end = p->topo;
    int tam=0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

REGISTRO buscar(PILHA *p, int pos) {
    PONT end = p->topo;
    int tam=0;
    while (end != NULL) {
        if(tam==pos) break;
        tam++;
        end = end->prox;
    }
    return end->reg;
}


PILHA inverter(PILHA *p) {
    PILHA q;
    PONT end = p->topo;
    REGISTRO reg;

    iniciarPilha(&q);

    int tam = tamanho(p);
    for(int i=0;i<tam;i++){
        reg = buscar(p, i);
        incluirElemento(&q, reg);
    }
    return q;
}

// void palindromo(PILHA *p){
//     PILHA q;
//     iniciarPilha(&q);
//     q = inverter(p);

//     PONT end1 = p->topo;
//     PONT end2 = q.topo;
//     int igual=0;

//     while (end1!=NULL){
//         if(end1->reg.value == end2->reg.value){
//             igual++;
//         }
//         end1=end1->prox;
//         end2=end2->prox;
//     }
//     printf("A palavra ");
//     mostrarPilha(&q);
//     if(tamanho(p)!=igual){
//         printf(" nao");
//     }
//     printf(" eh um palindromo\n");
// }