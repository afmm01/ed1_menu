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
        qtd++;
        printf("Prato %d -------------------------\n", qtd);
        printf("Nome do prato: ");
        for(int i=0;i<TAM;i++) printf("%c", end->reg.nome[i]);
        printf("\nDescricao: ");
        for(int i=0;i<TAM_DESC;i++) printf("%c", end->reg.descricao[i]);
        printf("\nValor: %.2f", end->reg.val);
        printf("\nTipo: %d\n", end->reg.tipo);
        printf("----------------------------------\n");
      }
      end = end->prox;              
    }
    printf("\n");
    return qtd;
}

void limparTela(){
  printf("\e[1;1H\e[2J");
}
void enfase(char *texto, int tam) {
    int espaco = (tam - strlen(texto)) / 2;
    printf("%*s%s%*s\n", espaco, "", texto, espaco, "");
} 

PEDPTR apresentarPrato(PILHA *p, int tipo){
  PONT end = p->topo;
  PEDIDO ped;
  PEDPTR ped2;
  char type[3][20] = {"Prato Principal", "Acompanhamento", "Bebida"};
  char s[10], j;
  while (end != NULL) {
    if(end->reg.tipo==tipo){
      limparTela();
      enfase(type[tipo-1], 30);
      printf("------------------------------\n");
      enfase(end->reg.nome, 30);
      enfase(end->reg.descricao, 30);
      sprintf(s, "\nR$%.2f", end->reg.val);
      int espaco = (30 - strlen(s)) / 2;
      printf("%*s%s%*s\n", espaco, "", s, espaco, "");
      printf("------------------------------\nEscolha uma opcao:\n");
      printf("C - Comprar %s\nP - Proximo %s\n> ", end->reg.nome, type[tipo-1]);
      scanf(" %c", &j);
      if (j=='c' || j=='C') {
        int qtd;
        do{
          printf("Digite a quantidade a ser adquirida: ");
          scanf("%d", &qtd);
        } while(qtd<1);
        strcpy(ped.nome, end->reg.nome);
        ped.val = end->reg.val;
        ped.qtd = qtd;
        ped.tipo = end->reg.tipo;
        ped2 = &ped;
        return ped2;
      }
    }
    end = end->prox;              
  }
  return NULL;
}

void trocarPrato(PILHA *p, int tipo, int esse) {
  PONT end = p->topo;
  int qtd=0, carac;
  while (end != NULL) {
    if(end->reg.tipo==tipo){
      qtd++;
      if(esse==qtd){
        limparTela();
        printf("Escolha a caracterisitca a ser alterada:\n");
        printf("--------------------------------------\n");
        printf("[1] - Nome do prato: ");
        puts(end->reg.nome);
        printf("[2] - Descricao: ");
        puts(end->reg.descricao);
        printf("[3] - Valor: %.2f", end->reg.val);
        printf("\n[4] - Tipo: %d\n", end->reg.tipo);
        printf("--------------------------------------\n");
        printf("Digite a caracteristica a ser atualizada: ");
        scanf("%d", &carac);
        char nome[TAM];
        char descricao[TAM_DESC];
        float val;
        int tipo;
        switch (carac) {
        case 1:
          printf("Digite o nome atualizado:\n> ");
          scanf(" %[^\n]", nome);
          strcpy(end->reg.nome, nome);
          break;
        case 2:
          printf("Digite a descricao atualizada:\n> ");
          scanf(" %[^\n]", descricao);
          strcpy(end->reg.descricao, descricao);
          break;
        case 3:
          printf("Digite o valor atualizado:\n> ");
          scanf("%f", &val);
          end->reg.val = val;
          break;
        case 4:
          do{
            printf("Digite o tipo atualizado:\n[1] Principal | [2] Acompanhamento | [3] Bebida\n> ");
            scanf("%d", &tipo);
          } while(tipo<1 || tipo >3);
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
  limparTela();
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