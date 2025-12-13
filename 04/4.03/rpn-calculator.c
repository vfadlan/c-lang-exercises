#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

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
#define SIN -20
#define COS -21
#define TAN -22
#define EXP -23
#define POW -24

int getop(char s[]) {
  int i=0, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {}

  s[1] = '\0';

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

double deg2rad(double deg) {
  return deg * M_PI / 180;
}

#define MAXOP 100

int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case SIN:
        push(sin(deg2rad(pop())));
        break;
      case COS:
        push(cos(deg2rad(pop())));
        break;
      case TAN:
        push(tan(deg2rad(pop())));
        break;
      case EXP:
        push(exp(pop()));
        break;
      case POW:
        op2 = pop();
        push(pow(pop(), op2));
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
