#include <stdio.h>
#include "calc.h"

#define BUFFSIZE 100

int BUFFER[BUFFSIZE];
int BUFFP = 0;

int getch(void) {
  return (BUFFP > 0) ? BUFFER[--BUFFP] : getchar();
}

void ungetch(int c) {
  if (BUFFP >= BUFFSIZE) {
    printf("ERROR: Too many char.\n");
  } else {
    BUFFER[BUFFP++] = c;
  }
}