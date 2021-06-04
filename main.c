#include "pilha.h"
#include "file.h"
#include "string.h"

int criaTitulo(char*);
void aperteEnter();
void fazerPedido(PILHA *, FILA *);
void opcoesCliente(PILHA *, FILA *);
void entregarPrato(FILA *);
void adicionarPratos(PILHA *);
void alterarPratos(PILHA *);
void opcoesChef(PILHA *, FILA *);


int main(void) {
  PILHA menu;
  FILA pedido;
  iniciarPilha(&menu);
  iniciarFila(&pedido);

  readFile(&menu);
  opcoesCliente(&menu, &pedido);

  return 0;
}


// Faz um titulo bonitinho *-*
int criaTitulo(char* nome){
  int tamTitulo, espaco;
  tamTitulo = strlen(nome);
  if(tamTitulo > 15){
    espaco = tamTitulo/3;
  } else {
    espaco = tamTitulo;
  }
  tamTitulo+=espaco*2;
  for(int i=0;i<tamTitulo; i++){
    if(i<espaco || i>espaco){
      printf(" ");
    } else {
      printf("%s", nome);
    }
  }
  printf("\n");
  for(int i=0;i<tamTitulo; i++) printf("=");
  printf("\n");
  return 0;
}

void aperteEnter(){
  printf("Pressione ENTER para voltar...");
  getchar();
}

// FUNCOES DO MENU CLIENTE
void fazerPedido(PILHA *menu, FILA *pedido){
  PEDPTR pratos[3];
  float total=0;
  int totItems=0;
  for(int tipo=0;tipo<3;tipo++){
    do{
      pratos[tipo] = apresentarPrato(menu, tipo+1);
    }while(pratos[tipo]==NULL);
    total+=(pratos[tipo]->val*pratos[tipo]->qtd);
    totItems+=pratos[tipo]->qtd;
    enfileira(pedido, *pratos[tipo]);
    printf("Pedido realizado com sucesso!\n");
  }
  limparTela();
  criaTitulo(" Nota Fiscal ");
  mostrarFila(pedido, 28);
  emitirNota("Total", total, totItems, 28);
  printf("=======================================\n");
  aperteEnter();
  getchar();
  opcoesCliente(menu, pedido);
}

// // MENU CLIENTE
void opcoesCliente(PILHA *menu, FILA *pedido){
  int sn;
  limparTela();
  criaTitulo("Siri Cascudo");
  printf("[1] - Fazer pedido\n[2] - Menu do Chef\n[3] - Sair\nO que deseja fazer?\n> ");
  scanf("%d",&sn);
  if(sn==1){
    fazerPedido(menu, pedido);
  } else if(sn==2){
    opcoesChef(menu, pedido);
  } else if(sn==3){
    puts("Ate logo!");
    exit(1);
  } else {
    puts("Opcao inexistente no menu");
    aperteEnter();
    getchar();
    opcoesCliente(menu, pedido);
  }
}

// FUNCOES DO MENU CHEF
void entregarPrato(FILA *pedido){
  criaTitulo("Entregar Prato");
  if(tamanhoFila(pedido)==0) {
    puts("Sem pratos na fila");
    aperteEnter();
    getchar();
    return;
  }
  printf("Nome: %s\n", pedido->inicio->ped.nome);
  printf("Quantidade: %d\n", pedido->inicio->ped.qtd);
  printf("Preco: %.2f\n", pedido->inicio->ped.val);
  printf("Tipo: ");
  switch (pedido->inicio->ped.tipo){
  case 1:
    printf("Prato principal\n");
    break;
  case 2:
    printf("Acompanhamento\n");
    break;  
  default:
    printf("Bebida\n");
    break;
  }
  char sOn;
  do{
    printf("Pronto para entregar? [S/n] ");
    scanf(" %c", &sOn);
  } while(sOn!='s' && sOn!='S' && sOn!= 'N' && sOn!='n');
  if(sOn=='s' || sOn=='S'){
    desenfileira(pedido);
    printf("O prato foi entregue com sucesso!\n");
  }
  printf("Voltando ao menu principal...\n\n");
  aperteEnter();
}

void adicionarPratos(PILHA *menu){
  REGISTRO prato;
  float valor;
  char seguir;
  char nome[30];

  iniciarPilha(menu);

  do {
    criaTitulo("Novo Prato");
    printf("Nome do prato: ");
    scanf(" %[^\n]", prato.nome);
    printf("Descricao do prato: ");
    scanf(" %[^\n]", prato.descricao);
    // prato.nome = &nome;
    printf("Valor do prato: ");
    scanf("%f", &prato.val);
    // prato.val = valor;
    do{
      printf("Qual é o tipo de prato?\n");
      printf("[1] Principal \n[2] Acompanhamento\n[3] Bebida\n> ");
      scanf("%d", &prato.tipo);
    } while(prato.tipo>3 || prato.tipo<1);

    incluirElemento(menu, prato);
    appendToStack(menu, prato);

    printf("Adicionar outro prato[S/n] ");
    scanf(" %c", &seguir);
  } while(seguir=='S' || seguir=='s');
}

void alterarPratos(PILHA *menu){
  int tipo, qtd=0, esse;
  criaTitulo("Alterando Pratos");
  printf("Quais tipos de pratos voce quer alterar?\n");
  do{
    printf("[1] - Prato Principal\n[2] - Acompanhamento\n[3] - Bebida\n> ");
    scanf("%d", &tipo);
  } while(tipo>3 || tipo<1);
  limparTela();
  if(tipo==1){
    criaTitulo("Pratos Principais");
    qtd = mostrarRefeicoes(menu, tipo);
  } else if(tipo==2){
    criaTitulo("Acompanhamento");
    qtd = mostrarRefeicoes(menu, tipo);
  } else {
    criaTitulo("Bebidas");
    qtd = mostrarRefeicoes(menu, tipo);
  }
  printf("Qual prato deseja alterar?\n> ");
  scanf("%d", &esse);
  limparTela();
  if(esse<=qtd) {
    trocarPrato(menu, tipo, esse); 
    overwriteFile(menu);
  }
  else puts("Esse prato nao existe\n");
  aperteEnter();
}


// // MENU CHEF
void opcoesChef(PILHA *menu, FILA *pedido){
  int sn;
  limparTela();
  criaTitulo("Menu Corporativo");
  printf("[1] - Entregar pratos\n[2] - Adicionar pratos\n[3] - Alterar pratos\n[4] - Voltar ao menu do cliente\n");
  printf("=================================\n> ");
  // char opcoes[] = "[1] - Entregar pratos\n[2] - Adicionar pratos\n[3] - Alterar pratos\n[4] - Voltar ao menu do cliente\n";
  // criaMenu("Menu Corporativo", opcoes);
  scanf("%d",&sn);
  limparTela();
  switch (sn)
  {
  case 1:
    entregarPrato(pedido);
    opcoesChef(menu, pedido);
    break;
  case 2:
    adicionarPratos(menu);
    opcoesChef(menu, pedido);
    break;
  case 3:
    alterarPratos(menu);
    opcoesChef(menu, pedido);
    break;
  case 4:
    opcoesCliente(menu, pedido);
    opcoesChef(menu, pedido);
    break;
  default:
    printf("Opcao incorreta! Voltando ao menu do cliente\n\n\n");
    opcoesCliente(menu, pedido);
    break;
  }
}