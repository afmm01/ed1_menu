#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"
 
void adicionarPratos();
void opcoes();

int main(void) {
  PILHA menu;
  char nome[30];
  // opcoes(&menu);

  adicionarPratos(&menu);

  mostrarPilha(&menu);

  return 0;
}


void adicionarPratos(PILHA *menu){
  REGISTRO prato;
  float valor;
  char seguir;
  char nome[30];

  iniciarPilha(menu);

  do {
    printf("Digite o nome do prato: ");
    scanf(" %[^\n]", prato.nome);
    // prato.nome = &nome;
    printf("Digite o valor do prato: ");
    scanf("%f", &valor);
    prato.val = valor;
    incluirElemento(menu, prato);
    printf("Adicionar outro prato[S/n] ");
    scanf(" %c", &seguir);
  } while(seguir=='S' || seguir=='s');

}

void opcoes(PILHA *menu){
  char addP;
  printf("Deseja adicionar pratos[S/n]: ");
  scanf("%c",&addP);
  if(addP=='S' || addP == 's'){
    adicionarPratos(menu);
  }
}