#include <stdio.h>

/* (E1-9) Skip any double or more blanks. */
int main() {
  int prevChar = 0;
  int c;
  
  while ((c = getchar()) != EOF) {
    if (prevChar == ' ' && c == ' ') {}
    else {
      putchar(c);
    }
    prevChar = c;
  }

  return 0;
}
