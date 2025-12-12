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

void ungets(char s[]) {
  int i, c;
  for (i = 0; (c = s[i]) != '\0'; i++) {}
ungets("HELLO");
int c;
while ((c = getch()) != EOF)
    putchar(c);
  i--;
  for (; i >= 0; i--) {
    ungetch(s[i]);
  }
}

int main() {
  ungets("HELLO");
  int c;
  while ((c = getch()) != EOF) {
      putchar(c);
  }
}
