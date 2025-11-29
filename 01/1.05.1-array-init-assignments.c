#include <stdio.h>

/* Fills arrray */
int main() {
  int i;
  int ndigit[10];

  for (i=0; i < 10; ++i) {
    ndigit[i] = 0;
  }

  for (i=0; i < 10; ++i) {
    printf("%d : %d\n", i, ndigit[i]);
  }

  return 0;
}
