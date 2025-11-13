#include <stdio.h>
#include <stdint.h>

int bitcount(uint8_t x);
void printBinary(unsigned int bin, int len);

int main() {
  uint8_t scenarios[10][2] = {
    {1, 1},
    {3, 2},
    {0, 0},
    {255, 8},
    {128, 1},
    {85, 4},
    {170, 4},
    {63, 6},
    {192, 2},
    {15, 4}
  };

  printf("Exercise 2-9 Count Bits\n");
  printf("x\t\texpect\tres\n");
  for (int i = 0; i < 10; i++)
  {
    int res = bitcount(scenarios[i][0]);
    
    printBinary(scenarios[i][0], 8);
    printf("\t%d\t%d\n", scenarios[i][1], res);
  }

  return 0;
}

/* bitcount: count number of 1s inside a two's complement binary */
int bitcount(uint8_t x) {
  int b;

  for (b = 0; x!= 0; x &= (x-1)) {
    b++;
  }

  return b;
}

/* printBinary: print given binary by len */
void printBinary(unsigned int bin, int len) {
  int i;
  for (i = len-1; i >= 0; i--) {
    printf("%d", (bin >> i) & 1);
  }
}