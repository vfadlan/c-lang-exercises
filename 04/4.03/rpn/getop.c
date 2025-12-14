#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[]) {
  int i=0, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {}

  s[1] = '\0';

  if (isalpha(c) && isupper(c)) {
    s[0] = c;
    s[1] = '\0';
    return VAR;
  }

  if (c == '=') {
    return ASG;
  }

  if (!isdigit(c) && c != '.' && !isalpha(c)) { // operator
    return c;
  }

  if (isalpha(c)) {
    while (isalpha(s[++i] = c = getch())) {}
    s[++i] = '\0';
    if (c != EOF) {
      ungetch(c);
    }

    if (!strcmp(s, "sin") || !strcmp(s, "sin\n")) {
      return SIN;
    } else if (!strcmp(s, "cos") || !strcmp(s, "cos\n")) {
      return COS;
    } else if (!strcmp(s, "tan") || !strcmp(s, "tan\n")) {
      return TAN;
    } else if (!strcmp(s, "exp") || !strcmp(s, "exp\n")) {
      return EXP;
    } else if (!strcmp(s, "pow") || !strcmp(s, "pow\n")) {
      return POW;
    }
  }

  if (isdigit(c)) { // num
    while (isdigit(s[++i] = c = getch())) {}
  }

  if (c == '.') {
    while (isdigit(s[++i] = c = getch())) {}
  }

  s[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}