#include "pilha.h"
#include "string.h"

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
      printf("\nDescricao: ");
      for(int i=0;i<TAM_DESC;i++) printf("%c", end->reg.descricao[i]);
      printf("\nValor: %.2f", end->reg.val);
      printf("\nTipo: %d\n", end->reg.tipo);
      end = end->prox;
    }
    printf("\n");
}

int mostrarRefeicoes(PILHA *p, int tipo) {
    PONT end = p->topo;
    int qtd=0;
    while (end != NULL) {
      if(end->reg.tipo==tipo){
        printf("--------------------------------------\n");
        printf("Nome do prato: ");
        for(int i=0;i<TAM;i++) printf("%c", end->reg.nome[i]);
        printf("\nDescricao: ");
        for(int i=0;i<TAM_DESC;i++) printf("%c", end->reg.descricao[i]);
        printf("\nValor: %.2f", end->reg.val);
        printf("\nTipo: %d\n", end->reg.tipo);
        qtd++;
      }
      end = end->prox;              
    }
    printf("\n");
    return qtd;
}

void trocarPrato(PILHA *p, int tipo, int esse) {
  PONT end = p->topo;
  int qtd=0, carac;
  while (end != NULL) {
    if(end->reg.tipo==tipo){
      qtd++;
      if(esse==qtd){
        printf("Escolha a caracterisitca a ser alterada:\n");
        printf("--------------------------------------\n");
        printf("[1] - Nome do prato: ");
        for(int i=0;i<TAM;i++) printf("%c", end->reg.nome[i]);
        printf("\n[2] - Descricao: ");
        for(int i=0;i<TAM_DESC;i++) printf("%c", end->reg.descricao[i]);
        printf("\n[3] - Valor: %.2f", end->reg.val);
        printf("\n[4] - Tipo: %d\n", end->reg.tipo);
        scanf("%d", &carac);
        printf("Digite a caracteristica atualizada: ");
        char nome[TAM];
        char descricao[TAM_DESC];
        float val;
        int tipo;
        switch (carac) {
        case 1:
          scanf("%[^\n]", nome);
          strcpy(end->reg.nome, nome);
          break;
        case 2:
          scanf("%[^\n]", descricao);
          strcpy(end->reg.descricao, descricao);
          break;
        case 3:
          scanf("%f", &val);
          end->reg.val = val;
          break;
        case 4:
          scanf("%d", &tipo);
          end->reg.tipo = tipo;
          break;   
        default:
          puts("Opcao nao corresponde a nenhuma caracteristica");
          break;
        }
      }
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