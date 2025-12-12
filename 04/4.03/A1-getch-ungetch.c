#include <stdio.h>

#define BUFFSIZE 100

int buffer[BUFFSIZE];
int buffp = 0;

int getch(void) {
  return (buffp > 0) ? buffer[--buffp] : getchar();
}

int ungetch(int c) {
  if (c >= BUFFSIZE) {
    printf("Too many characters\n");
  } else {
    buffer[buffp++] = c;
  }
}

int getop(char s[]) {
  int c;

  while ((s[0] = c = getchar()) == ' ' || c == '\t') {printf("\n");}
  s[1]= '\0';
  
  return c;
}

int main() {
  char s[1000];
  int i, c;
  while ((c = getop(s)) != EOF && c != '\n') {
    putchar(c);
  }

  printf("INSIDE s[1000]:\n");
  for (i = 0; s[i] != '\0' && i < 1000; i++) { // it's either EOF or \n followed by \0, look up on line 32.
    printf("'");
    putchar(s[i]);
    printf("', ");
  }
}
