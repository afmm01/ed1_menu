#include "fila.h"
#include "pilha.h"
#include <string.h>

void createFile(){
    FILE *fptr;
    fptr = fopen("pilha.csv", "w");
    // fptr = fopen("pilha.bin", "wb");
}

void writeStack(PILHA *p) {
    FILE *fptr;
    // fptr = fopen("teste.bin", "ab+");
    fptr = fopen("teste.csv", "a+");
    PONT end = p->topo;
    while (end != NULL) {
      for(int i=0;i<TAM;i++) fprintf(fptr, "%c", end->reg.nome[i]);
      fprintf(fptr, ",%.2f\n", end->reg.val);
      end = end->prox;
    }
    fprintf(fptr, "\n");
}

void appendToStack(PILHA *p, REGISTRO reg) {
    FILE *fptr;
    fptr = fopen("teste.csv", "ab+");
    for(int i=0;i<strlen(reg.nome);i++) {
      fprintf(fptr, "%c", reg.nome[i]);
    }
    fprintf(fptr, ",%.2f\n", reg.val);

    fclose(fptr);
}

void readTheFile(){
  REGISTRO reg;
  FILE *fptr;
  char *line, split[7][TAM];
  int cont=0, i, j, k;
  size_t len; 
  ssize_t read;   // conta o tamanho da linha (%zu)

  fptr = fopen("teste.csv", "r");
  if(fptr == NULL){     // Sai do programa se o arquivo nao tiver conteudo
    puts("File does not exists.");
    exit(1);
  }
  
  cont=0;
  while ((read = getline(&line, &len, fptr)) != -1) {
    // printf("Retrieved line of length %zu:\n", read);
    

    i=0; j=0; k=0;
    for(int i=0;i<read;i++){
      if(line[i]== ',' || line[i]=='\0'){
        split[cont][j]='\0';
        cont++;
        j=0;
        printf(" - cont: %d\n", cont);
      } else {
        split[cont][j] = line[i];
        printf("%c", split[cont][j]);
        j++;
      }
    }
    k++;
    if(k>0){

    }
    // for(int i=0;i < cont;i++) printf(" %s\n",split[i]);
    printf("\n");
  }
  // for(int i=0;i < cont;i++) printf(" %s\n",split[i]);
  printf(" %s\n",split[2]);

  fclose(fptr);
}

// void addFIleToStack(){}