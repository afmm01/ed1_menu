#include <stdio.h>

FILE* isCreated(char[], char[]);
void appendToStack(PILHA *, REGISTRO);
void readFile(PILHA *);
void deleteLine(char *);
void findAndDelete(PILHA *, REGISTRO);
void overwriteFile(PILHA *);