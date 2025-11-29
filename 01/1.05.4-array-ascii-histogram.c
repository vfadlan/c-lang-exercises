#include <stdio.h>

/* (E1-14) Print a histogram of the frequencies of different character in its input. */
int main() {
  int c, i;
  int asciiFreq[128];

  for (i = 0; i < 128; ++i) {
    asciiFreq[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++asciiFreq[c];
  }

  printf("\n\nASCII Characters Frequency Histogram\n");
  printf("%4s | %4s | %4s | %8s", "code", "char", "freq", "histogram\n");
  for (i = 0; i < 128; ++i) {
    if (asciiFreq[i] > 0) {
      printf("%4d | %4c | %4d | %*c\n", i, i,asciiFreq[i], asciiFreq[i], '|');
    }
  }
}
