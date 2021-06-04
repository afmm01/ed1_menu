#include "pilha.h"
#include <string.h>

char fileName[] = "teste.csv";

// Cria arquivo se esse nao existir e adiciona primeira linha
FILE* isCreated(char name[], char type[]){
  FILE *fptr;
  
  fptr = fopen(name, "r");
  if(fptr == NULL){
    fptr = fopen(name, type);
    fprintf(fptr, "Prato,Descricao,Preco,Tipo\n");
  }
  // fclose(fptr);
  return fptr;
}


void appendToStack(PILHA *p, REGISTRO reg) {
  FILE *fptr;
  fptr = fopen(fileName, "a");

  fprintf(fptr, "\n");
  for(int i=0;i<strlen(reg.nome);i++) fprintf(fptr, "%c", reg.nome[i]);
  fprintf(fptr,",");
  for(int i=0;i<strlen(reg.descricao);i++) fprintf(fptr, "%c", reg.descricao[i]);
  fprintf(fptr, ",%.2f", reg.val);
  fprintf(fptr, ",%d", reg.tipo);

  fclose(fptr);
}

void readFile(PILHA *p){
  REGISTRO reg[100];
  FILE *fptr;
  char *line, split[7][TAM], *token;
  int cont=0, i=0, y, z=0;
  float x;
  size_t len; 
  ssize_t read;   // conta o tamanho da linha (%zu)

  fptr = isCreated(fileName, "r");
  
  while ((read = getline(&line, &len, fptr)) != -1) {
    token = strtok(line, ","); // pega o primeiro token

    while( token != NULL ) { // pega os outros tokens
      strcpy(split[i], token); // copia a palavra de token para o vetor split[]
      token = strtok(NULL, ",");
      if(i>3){
        if(i%4==0){
          strcpy(reg[z].nome, split[i]);
        } else if((i-1)%4==0){
          strcpy(reg[z].descricao, split[i]);
        } else if((i-2)%4==0){
          x = atof(split[i]); // converte string em float
          reg[z].val = x;
        } else {
          y = atoi(split[i]); // converte string em int
          reg[z].tipo = y;
          incluirElemento(p, reg[z]);
          z++;
        }
      }
      i++;
    }
  }
  fclose(fptr);
}

void deleteLine(char *regLine){
  FILE *fptr = fopen(fileName, "r");
  if (fptr == NULL) {
      printf("Cannot open file.\n");
      return ;
  }
  else { // Checa o numero de linhas no arquivo
    char ch;
    int count = 0;
    do {
    ch = fgetc(fptr);
    if (ch == '\n') count++;
    } while (ch != EOF);
    rewind(fptr);

    char temp[count+1][100];
    int i;
    // Escaneia cada linha do arquivo
    for (i = 0; i <= count; i++) 
      fscanf(fptr, "%1023[^\n]\n", temp[i]);
    fclose(fptr);

    fptr = fopen(fileName, "w");
    for(i=0;i<=count;i++)
      if(strcmp(temp[i], regLine)!=0) fprintf(fptr, "%s\n", temp[i]);

    fclose(fptr);
  }
}

void findAndDelete(REGISTRO reg){
  char regLine[250] = "";
  strcat(regLine, "\n");
  strcat(regLine, reg.nome);
  strcat(regLine, ",");
  strcat(regLine, reg.descricao);
  strcat(regLine, ",");
  char val[10]; sprintf(val, "%.2f", reg.val);
  strcat(regLine, val);
  strcat(regLine, ",");
  char tipo[2]; sprintf(tipo, "%d", reg.tipo);
  strcat(regLine, tipo);

  deleteLine(regLine);
}

void overwriteFile(PILHA *p){
  FILE *fptr;
  
  fptr = fopen(fileName, "w");
  fprintf(fptr, "Prato,Descricao,Preco,Tipo\n");

  PONT end = p->topo;
  while(end!=NULL){
    for(int i=0;i<strlen(end->reg.nome);i++) fprintf(fptr, "%c", end->reg.nome[i]);
    fprintf(fptr,",");
    for(int i=0;i<strlen(end->reg.descricao);i++) fprintf(fptr, "%c", end->reg.descricao[i]);
    fprintf(fptr, ",%.2f", end->reg.val);
    fprintf(fptr, ",%d\n", end->reg.tipo);
    end = end->prox;
  }

  fclose(fptr);
}