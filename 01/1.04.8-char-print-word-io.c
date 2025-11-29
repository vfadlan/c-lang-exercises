#include <stdio.h>

/* (E1-12) Prints user input one word per line */
int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      putchar('\n');
    } else {
      putchar(c);
    }
  }

  return 0;
}
