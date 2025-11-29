#include <stdio.h>
#include <stdint.h>

uint8_t invert(uint8_t x, int p, int n);
void printBinary(unsigned int bin, int len);

int main() {
  uint8_t scenarios[10][4] = {
    {170, 3, 1, 162},
    {170, 5, 3, 146},
    {255, 7, 8, 0},
    {0,   7, 8, 255},
    {85,  2, 3, 82},
    {85,  7, 4, 165},
    {13,  3, 4, 2},
    {240, 0, 0, 240},
    {128, 7, 1, 0},
    {128, 0, 1, 129}
  };

  printf("Exercise 2-7 Invert Bits\n");
  printf("x\t\tp\tn\texpect\t\tres\t\tcheck\n");
  for (int i = 0; i < 10; i++)
  {
    uint8_t res = invert(scenarios[i][0], scenarios[i][1], scenarios[i][2]);
    
    printBinary(scenarios[i][0], 8);
    printf("\t%d\t%d\t", scenarios[i][1], scenarios[i][2]);
    printBinary(scenarios[i][3], 8);
    printf("\t");
    printBinary(res, 8);
    printf("\t%s\n", (res==scenarios[i][3]) ? "PASS" : "FAIL");
  }
  

  return 0;
}

/* invert: invert n amount of binary of x from position p */
uint8_t invert(uint8_t x, int p, int n) {
  uint8_t mask = ~(~0 << n);
  return x ^ (mask << p+1-n);
}

/* printBinary: print given binary by len */
void printBinary(unsigned int bin, int len) {
  int i;
  for (i = len-1; i >= 0; i--) {
    printf("%d", (bin >> i) & 1);
  }
}