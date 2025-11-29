#include <stdio.h>

/* Count number of lines from user input */
int main() {
  int lineCount = 1;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++lineCount;
    }
  }

  printf("\nNumber of line is: %d\n", lineCount);

  return 0;
}
