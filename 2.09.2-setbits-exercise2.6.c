#include <stdio.h>

void printBinary(unsigned int bin, int len);
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main() {
  printf("CASE 1\nx : 10101010\np : 4\nn : 3\ny : 00000111\nex: 10111110\n");
  printf("r : ");
  printBinary(setbits(10101010, 4, 3, 00000111), 8);
  printf("\n\n");

  printf("CASE 2\nx : 11110000\np : 5\nn : 4\ny : 00001111\nex: 11101111\n");
  printf("r : ");
  printBinary(setbits(11110000, 5, 4, 00001111), 8);
  printf("\n\n");

  printf("CASE 3\nx : 00000000\np : 7\nn : 8\ny : 11111111\nex: 11111111\n");
  printf("r : ");
  printBinary(setbits(00000000, 7, 8, 11111111), 8);
  printf("\n\n");

  printf("CASE 4\nx : 11001100\np : 3\nn : 2\ny : 00000011\nex: 11001011\n");
  printf("r : ");
  printBinary(setbits(11001100, 3, 2, 00000011), 8);
  printf("\n\n");

  printf("CASE 5\nx : 10111101\np : 6\nn : 3\ny : 00000000\nex: 10000101\n");
  printf("r : ");
  printBinary(setbits(10111101, 6, 3, 00000000), 8);
  printf("\n\n");

  printf("CASE 6\nx : 101001110\np : 6\nn : 3\ny : 000101110\nex: 101110110\n");
  printf("r : ");
  printBinary(setbits(101001110, 6, 3, 101110110), 9);
  printf("\n\n");

  return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
  unsigned int maskA, maskB, Xp, Xq, maskX, maskY, maskZ;

  maskA = y & ~(~0 << n);
  maskB = maskA << (p+1-n);

  printf("\nMaskB\t:");
  printBinary(maskB, 9);

  maskX = ~(~0 << n) << (p+1-n);
  Xp = x & maskX;
  Xq = Xp | maskB;

  printf("\nXA\t:");
  printBinary(Xp, 9);
  printf("\nmaskX\t:");
  printBinary(maskX, 9);
  printf("\n");

  return Xq;
}

/* printBinary: print given binary by len */
void printBinary(unsigned int bin, int len) {
  int i;
  for (i = len-1; i >= 0; i--) {
    printf("%d", (bin >> i) & 1);
  }
}

