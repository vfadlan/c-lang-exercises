#include <stdio.h>

/* Calculate number of characters typed by user */
int main() {
  long numOfChars = 0;

  while (getchar() != EOF) {
    numOfChars++;
  }
  printf("Total number of characters that you typed: %ld\n", numOfChars);

  return 0;
}
