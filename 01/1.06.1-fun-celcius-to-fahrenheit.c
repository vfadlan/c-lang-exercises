#include <stdio.h>

int c2f(int c);

/* (E1-15) Rewrite temperature conversion program of Section 1.2 to use a function for conversion */
int main() {
  int lower, upper, step, i;

  lower = -40;
  upper = 300;
  step = 20;

  printf("  Celcius to Fahrenheit\n    Conversion Table\n");
  printf("========================\n"); 

  printf("%8c\t%8c\n", 'C', 'F');

  i = lower;
  while (i <= upper) {
    printf("%8d\t%8d\n", i, c2f(i));
    i += 20;
  }

  return 0;
}

int c2f(int c) {
  return (c * 9 / 5) + 32;
}
