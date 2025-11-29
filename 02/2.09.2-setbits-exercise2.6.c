#include <stdio.h>
#include <stdint.h>

void printBinary(unsigned int bin, int len);
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main() {
  printf("Exercise 2-6 Test Scenarios\n");
  uint8_t scenarios[10][5] = {
    {0b10100111, 4, 3, 0b00010110, 0b10111011},
    {0b11111111, 5, 3, 0b00000000, 0b11000111},
    {0b10101010, 3, 2, 0b00001111, 0b10101110},
    {0b01010101, 7, 3, 0b11110000, 0b00010101},
    {0b00001111, 5, 2, 0b11111111, 0b00111111},
    {0b00110011, 3, 3, 0b11111111, 0b00111111},
    {0b11000011, 7, 1, 0b00000000, 0b01000011},
    {0b10011001, 4, 4, 0b00111100, 0b10011001},
    {0b00000000, 7, 8, 0b10101010, 0b10101010},
    {0b11110000, 3, 3, 0b01010101, 0b11111010},
  };

  printf("x\t\tp\tn\ty\t\texpect\t\tres\t\tcheck\n");
  for (int i = 0; i < 9; i++)
  {
    uint8_t res = setbits(scenarios[i][0], scenarios[i][1], scenarios[i][2], scenarios[i][3]);
    printBinary(scenarios[i][0], 8);
    printf("\t%d\t%d\t", scenarios[i][1], scenarios[i][2]);
    printBinary(scenarios[i][3], 8);
    printf("\t");
    printBinary(scenarios[i][4], 8);
    printf("\t");
    printBinary(res, 8);
    printf("\t%s\n", (res==scenarios[i][4]) ? "PASS" : "FAIL");
  }
  

  return 0;
}

unsigned int setbits_incorrect(unsigned int x, int p, int n, unsigned int y) {
  unsigned int fillA, fillB, maskX, clearedX;

  fillA = y & ~(~0 << n);
  fillB = fillA << p-1;

  maskX = ~(~1 << (n - 1));
  clearedX = x & ~(maskX << (p+1-n));

  return clearedX | fillB;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
  unsigned int mask, clearedX, localizedY;

  mask = ~(~0 << n);
  localizedY = (y & mask) << (p+1-n);
  clearedX = x & ~(mask << (p+1-n));

  return clearedX | localizedY;
}

/* printBinary: print given binary by len */
void printBinary(unsigned int bin, int len) {
  int i;
  for (i = len-1; i >= 0; i--) {
    printf("%d", (bin >> i) & 1);
  }
}

