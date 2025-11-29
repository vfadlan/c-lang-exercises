#include <stdio.h>

#define MAXLINE       1000
#define PRINT_MIN_LEN 80

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* (E1-17) Print all input lines that are longer than PRINT_MIN_LEN characters */
int main() {
  int len;
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > PRINT_MIN_LEN) {
      printf("%s", line);
    }
  }

  return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i ) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
