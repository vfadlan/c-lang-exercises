#include <stdio.h>

/* (E1-4) Print Celcius-Fahrenheit Table from -20C-300C Using While Loop */
int main() {
  float celcius, fahr;
  float lower, upper, step;

  lower = -20.0;
  upper = 300.0;
  step = 20.0;

  printf("  Celcius to Fahrenheit\n    Convertion Table\n");
  printf("========================\n"); 

  printf("%8c\t%8c\n", 'C', 'F');

  celcius = lower;

  while (celcius <= upper) {
    fahr = (celcius * 9.0 / 5.0) + 32;
    printf("%8.1f\t%8.1f\n", celcius, fahr);
    celcius += step;
  }
  return 0;
}
