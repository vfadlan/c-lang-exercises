#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

/* (E1-5) Print Celcius-Fahrenheit Table from 300C-0C Using for Loop */
int main() {
  int celc;

  printf("  Celcius to Fahrenheit\n    Convertion Table\n");
  printf("========================\n"); 
  printf("%8c\t%8c\n", 'C', 'F');

  for  (celc = UPPER; celc >= LOWER; celc -= STEP) {
    printf("%8.1f\t%8.1f\n", (celc * 1.0), (celc * 9.0 / 5.0) + 32);
  }
  return 0;
}
