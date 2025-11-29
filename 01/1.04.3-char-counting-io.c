#include <stdio.h>

/*  Count number of characters inputed by user */
int main() {
  long numOfChars = 0;

  while (getchar() != EOF) {
    numOfChars++;
  }
  printf("Total number of characters that you typed: %ld", numOfChars);
  
  return 0;
}
