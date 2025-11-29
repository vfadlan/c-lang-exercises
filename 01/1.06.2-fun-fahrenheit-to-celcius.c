#include <stdio.h>

float f2c(float f);

/* (E1-15) Rewrite temperature conversion program of Section 1.2 to use a function for conversion */
int main() {
  float lower, upper, step, i;

  lower = -40.0;
  upper = 300.0;
  step = 20.0;

  printf("  Fahrenheit to Celcius\n    Conversion Table\n");
  printf("========================\n"); 

  printf("%8c\t%8c\n", 'F', 'C');

  i = lower;
  while (i <= upper) {
    printf("%8.1f\t%8.1f\n", i, f2c(i));
    i += 20;
  }

  return 0;
}

float f2c(float f) {
  return 5.0 * (f - 32.0) / 9.0;
}
