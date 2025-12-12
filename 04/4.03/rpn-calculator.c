#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

#define NUMBER '0'

int getop(char s[]) {
  int i=0, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {}

  s[1] = '\0';

  if (!isdigit(c) && c != '.') { // operator
    return c;
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

double tofloat(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++) {} // skip whitespace
  
  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-') { i++; }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.') { i++; }

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  
  return sign * val / power;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("ERROR: Stack full.\n");
  }
}

double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("ERROR: Stack empty.\n");
    return 0.0;
  }
}

#define MAXOP 100

int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(tofloat(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        op2 = pop();
        if (op2 != 0) {
          push(pop() / op2);
        } else {
          printf("ERROR: Division by 0.\n");
        }
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("ERROR: Unknown command %s\n.", s);
        break;
    }
  }

  return 0;
}
