#include <stdio.h>
#include <ctype.h>
#define BUFFSIZE 100

int getch(void);
void ungetch(int);
int getint(int *pn);

int main(void) {
    int n, status;
    int array[100];
    int i = 0;

    while ((status = getint(&n)) != EOF) {
        if (n != 0) {
            array[i++] = n;
        }
    }

    for (int j = 0; j < i; j++) {
        printf("%d\n", array[j]);
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

int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c)) {
      ungetch(c);
      return 0;
    }
  }

  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }
  *pn *= sign;

  if (c != EOF) {
    ungetch(c);
  }
  return c;
}
