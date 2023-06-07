/* Pietro Castro Prata
Jéssica Tavares da Gama */

#include <stdio.h>
#include <stdlib.h>
#include "contref.h"

int main(int argc, char const *argv[]) {
  int* v = malloc2(sizeof(int));
  *v = 10; 
  int* w = malloc2(sizeof(int));
  dump();   // 2 espaços alocados com 1 referência
  *w = 20; 
  atribui(v,w); //realiza a atribuição de ponteiros em C
  printf("%d\n%d\n", *v, *w);
  dump();   // 1 espaço alocado com duas referências 
  
  printf("%d\n%d\n", *v, *w);
  
  char* c = malloc2(sizeof(char));
  *c = 'Z';  
  dump();   // 2 espaços alocados, 1 com duas referências e 1 com uma *
  
  printf("%c\n", *c);
  
  atribui(w, NULL); 
  dump();   // 2 espaços alocados, os dois com uma referência
  printf("%c\n", *c);
  
  return 0;
}


