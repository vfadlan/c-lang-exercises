#include <stdio.h>

/* 1.6 Array Digit Frequency Example */
int main() {
  int c, nc, nw, nother, i;
  int nDigit[10];

  for (i = 0; i < 10; i++) {
    nDigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    nc++;
    if (c >= '0' && c <= '9') {
      ++nDigit[c - '0'];
    } else if (c == ' ' || c == '\t' || c == '\n') {
      nw++;
    } else {
      nother++;
    }
  }

  printf("\n\nNew Characters\t: %d\n", nc);
  printf("New Whitespace\t: %d\n", nw);
  printf("New Others\t: %d\n", nother);
  printf("New Digits:\n");
  printf("%3c %3c\n", 'D', 'F');

  for (i = 0; i < 10; i++) {
    printf("%3d %3d\n", i, nDigit[i]);
  }

  return 0;
}
