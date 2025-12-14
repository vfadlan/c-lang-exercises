#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

double vars[26];
int lastVar = -1;


double deg2rad(double deg);

int main() {
  int type;
  double op2, op1;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case VAR:
        lastVar = s[0] - 'A';
        push(vars[lastVar]);
        break;
      case ASG:
        if (lastVar < 0) {
          printf("ERROR: no variable to assign\n");
        } else {
          vars[lastVar] = pop();
        }
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

double deg2rad(double deg) {
  return deg * M_PI / 180;
}