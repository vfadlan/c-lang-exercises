#include <stdio.h>

/* (E1-8) Count number of blanks, tabs, and new lines from user input. */
int main() {
  int blanks, tabs, newLines = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++blanks;
    } else if (c == '\t') {
      ++tabs;
    } else if (c == '\n') {
      ++newLines;
    }
  }

  printf("\n\n");
  printf("Format Counters.\nBlanks\t\t%d\nTabs\t\t%d\nNew Lines\t%d\n", blanks, tabs, newLines);

  return 0;
}
