#include <stdio.h>

/* (E1-13) Print histogram of the lengths of words in its input. */
int main() {
  int c, i, wordLength, nOther;
  int lengthFreq[16];

  for (i = 0; i < 15; ++i) {
    lengthFreq[i] = 0;
  }

  wordLength = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (wordLength <= 15) {
        ++lengthFreq[wordLength];
      } else {
        ++nOther;
      }
      wordLength = 0;
    } else {
      ++wordLength;
    }
  }

  printf("\n\nWord Length Frequency Histogram\n");
  printf("%4s | %4s | %8s", "len", "freq", "histogram\n");
  for (i = 0; i < 15; ++i) {
    printf("%4d | %4d | %*c\n", i, lengthFreq[i], lengthFreq[i], '|');
  }

  return 0;
}
