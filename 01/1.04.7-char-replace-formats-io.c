#include <stdio.h>

/* (E1-10) replace tab with \t, backspace with \b, and \ with \\ */
int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\b' || c == 127) {
      putchar('\\');
      putchar('b');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(c);
    }
  }

  return 0;
}
