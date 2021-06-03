#include <stdio.h>

FILE* isCreated(char[], char[]);
void appendToStack(PILHA *, REGISTRO);
void readFile(PILHA *p);
void deleteLine(char *regLine);
void findAndDelete(PILHA *p, REGISTRO reg);