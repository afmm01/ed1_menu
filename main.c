#include "pilha.h"
#include "fila.h"
#include "file.h"
#include "string.h"

int criaTitulo(char*);
void criaMenu(char*, char*);
void opcoesCliente(PILHA *);
void entregarPrato(PILHA *);
void adicionarPratos(PILHA *);
void alterarPratos(PILHA *);
void opcoesChef(PILHA *);


int main(void) {
  PILHA menu;
  iniciarPilha(&menu);

  readFile(&menu);
  opcoesCliente(&menu);

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

void criaMenu(char* titulo, char* corpo){
  criaTitulo(titulo);
  printf("\n");
  criaTitulo(corpo);
}


// FUNCOES DO MENU CLIENTE

// MENU CLIENTE
void opcoesCliente(PILHA *menu){
  int sn;
  criaTitulo("Siri Cascudo");
  printf("[1] - Fazer pedido\n[2] - Menu do Chef\nO que deseja fazer?\n> ");
  scanf("%d",&sn);
  if(sn==1){
    /* code */
  } else {
    opcoesChef(menu);
  }
}


// FUNCOES DO MENU CHEF
void entregarPrato(PILHA *menu){
  criaTitulo("Entregar Prato");
  printf("Nome: %s\n", menu->topo->reg.nome);
  printf("Descricao: %s\n", menu->topo->reg.descricao);
  printf("Preco: %.2f\n", menu->topo->reg.val);
  printf("Tipo: ");
  switch (menu->topo->reg.tipo){
  case 1 || 2:
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
    scanf("%c", &sOn);
  } while(sOn=='s' || sOn=='S' || sOn== 'N' || sOn=='n');
  if(sOn=='s' || sOn=='S'){
    apagarTopo(menu);
    findAndDelete(menu, menu->topo->reg);
    printf("O prato foi entregue com sucesso!\n");
  }
  printf("Voltando ao menu principal...\n\n");
}

void adicionarPratos(PILHA *menu){
  REGISTRO prato;
  float valor;
  char seguir;
  char nome[30];

  iniciarPilha(menu);

  do {
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
      printf("[1] Principal \n[2] Acompanhamento\n[3] Bebida\n>");
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
  printf("Quais tipos de pratos voce quer alterar?\n");
  do{
    printf("[1] - Prato Principal\n[2] - Acompanhamento\n[3] - Bebida\n> ");
    scanf("%d", &tipo);
  } while(tipo>3 || tipo<1);
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
  if(esse<=qtd) {
    trocarPrato(menu, tipo, esse); 
    overwriteFile(menu);
  }
  else puts("Esse prato nao existe\n");
}


// // MENU CHEF
void opcoesChef(PILHA *menu){
  int sn;
  criaTitulo("Menu Corporativo");
  printf("[1] - Entregar pratos\n[2] - Adicionar pratos\n[3] - Alterar pratos\n[4] - Voltar ao menu do cliente\n");
  printf("=================================\n> ");
  // char opcoes[] = "[1] - Entregar pratos\n[2] - Adicionar pratos\n[3] - Alterar pratos\n[4] - Voltar ao menu do cliente\n";
  // criaMenu("Menu Corporativo", opcoes);
  scanf("%d",&sn);
  switch (sn)
  {
  case 1:
    entregarPrato(menu);
    opcoesChef(menu);
    break;
  case 2:
    adicionarPratos(menu);
    opcoesChef(menu);
    break;
  case 3:
    alterarPratos(menu);
    opcoesChef(menu);
    break;
  case 4:
    opcoesCliente(menu);
    opcoesChef(menu);
    break;
  default:
    printf("Opcao incorreta! Voltando ao menu do cliente\n\n\n");
    opcoesCliente(menu);
    break;
  }
}