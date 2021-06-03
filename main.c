#include "pilha.h"
#include "fila.h"
#include "file.h"
#include "string.h"

void adicionarPratos();
void opcoesChef();
int criaTitulo(char*);
void entregarPrato(PILHA *menu);

int main(void) {
  PILHA menu;
  iniciarPilha(&menu);
  // criaTitulo("Siri Cascudo");

  // opcoesChef(&menu);

  // adicionarPratos(&menu);
  // readFile(&menu);
  // countLines();
  readFile(&menu);
  findAndDelete(&menu, menu.topo->reg);


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




// FUNCOES DO MENU CLIENTE



// FUNCOES DO MENU CHEF
void entregarPrato(PILHA *menu){

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
  int tipo;
  printf("Quais pratos voce quer alterar?\n");
  do{
    printf("[1] - Prato Principal\n[2] - Acompanhamento\n[3] - Bebida\n>");
    scanf("%d", &tipo);
  } while(tipo>3 || tipo<1);
  if(tipo==1){
    criaTitulo("Pratos Principais");
    mostrarRefeicoes(menu, tipo);
  } else if(tipo==2){
    criaTitulo("Acompanhamento");
    mostrarRefeicoes(menu, tipo);
  } else {
    criaTitulo("Bebidas");
    mostrarRefeicoes(menu, tipo);
  }
}

// void entregarPrato(PILHA *menu){
//   criaTitulo("Entregar Prato");
//   printf("Nome: %s\n", &menu->topo->reg.nome);
//   printf("Descricao: %s\n", &menu->topo->reg.descricao);
//   printf("Preco: %.2f\n", &menu->topo->reg.val);
//   printf("Tipo: ");
//   switch (menu->topo->reg.tipo){
//   case 1 || 2:
//     printf("Prato principal\n");
//     break;
//   case 2:
//     printf("Acompanhamento\n");
//     break;  
//   default:
//     printf("Bebida\n");
//     break;
//   }
//   char sOn;
//   do{
//     printf("Pronto para entregar? [S/n] ");
//     scanf("%c", &sOn);
//   } while(sOn=='s' || sOn=='S' || sOn== 'N' || sOn=='n');
//   if(sOn=='s' || sOn=='S'){
//     apagarTopo(&menu);
//     deleteLine(&menu, menu->topo->reg);
//     printf("O prato foi entregue com sucesso!\n");
//   }
//   printf("Voltando ao menu principal...\n\n");
//   opcoesChef(menu);
// }

// // MENU CHEF
// void opcoesChef(PILHA *menu){
//   int sn;
//   // printf("[1] - Entregar pratos\n[2] - Adicionar pratos\n[3] - Alterar pratos\n[4] - Remover pratos\n");
//   char opcoes[] = "[1] - Entregar prato\n[2] - Adicionar pratos\n[3] - Alterar pratos\n[4] - Remover pratos\n";
//   criaMenu("Menu Corporativo", opcoes);
//   scanf("%d",&sn);
//   switch (sn)
//   {
//   case 1:
//     /* code */entregarPrato(menu);
//     break;
//   case 2:
//     adicionarPratos(menu);
//     break;
//   case 3:
//     /* code */
//     break;
//   case 4:
//     /* code */
//     break;
//  
//   default:
//     break;
//   }
// }