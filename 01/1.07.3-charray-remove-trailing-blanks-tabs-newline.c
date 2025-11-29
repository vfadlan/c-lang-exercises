#include <stdio.h>

#define MAXLEN 1000

int charin(char to[], int maxlen);
int printFormat(char to[], int maxlen);

/* (E1-18) Remove trailing blanks, tabs, and skip blank lines. */
int main() {
  char s[MAXLEN];
  if (charin(s, MAXLEN) > 0 ) {
   // printf("%s", s);
     printFormat(s, MAXLEN);
  }
 }

/* charin: get input from user */
int charin(char to[], int maxlen) {
  int c, i;

  for (i=0; i<maxlen-2 && (c=getchar()) != EOF; i++) {
    to[i] = c;
  }

  to[i+1] = '\0';

  return i;
}

/* printFormat given char array to remove trailing blanks, tabs, and new lines. */
int printFormat(char s[], int maxlen) {
  int c, pc, i;

  for (i=0; i<maxlen-1; ++i) {
    c = s[i];
    if (c == pc && (pc == ' ' || pc == '\t' || pc == '\n')) {
      continue;
    }
    putchar(c);
    pc = c;
  }

  return i;
}
