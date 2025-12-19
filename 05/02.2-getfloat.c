#include <stdio.h>
#include <ctype.h>
#define BUFFSIZE 100

int getch(void);
void ungetch(int);
int getfloat(float *pn);

int main(void) {
  float n;
  int status;
  float array[100];
  int i = 0;
  while ((status = getfloat(&n)) != EOF) {
    if (n != 0) {
      array[i++] = n;
    }
  }

  for (int j = 0; j < i; j++) {
    printf("%.8f\n", array[j]);
  }

  return 0;
}

char buf[BUFFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFFSIZE) {
    printf("ERROR: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

int getfloat(float *pn) {
  int c, sign;
  float power;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c) && c != '.') {
      ungetch(c);
      return 0;
    }
  }

  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
  }
  if (c == '.') {
    c = getch();
  }
  for (power = 1.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }

  *pn = sign * *pn / power;

  if (c != EOF) {
    ungetch(c);
  }
  return c;
}
