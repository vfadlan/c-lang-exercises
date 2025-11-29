#include <stdio.h>

void printBinary(unsigned int bin, int len);
unsigned int getbits(unsigned int x, int p, int n);

int main() {
  printf("printBinary Test\n");
  printBinary(0b01001110, 8);
  printf("\n");
  printBinary(0b10011001, 8);
  printf("\n");
  printBinary(0b1011, 4);
  printf("\n");


  printf("\nOperator test\n");
  printf("077\t: ");
  printBinary(077, 16);
  printf("\n");

  printf("~077\t: ");
  printBinary(~(077), 16);
  printf("\n\n");

  printf("073\t: ");
  printBinary(073, 16);
  printf("\n");
  printf("037\t: ");
  printBinary(037, 16);
  printf("\n");

  printf("~073 | 037\t: ");
  printBinary(~073 | 037, 16);
  printf("\n");

  printf("073 ^ 037\t: ");
  printBinary(073 ^ 037, 16);
  printf("\n");

  printf("073 & ~037\t: ");
  printBinary(073 & ~037, 16);
  printf("\n");

  printf("~073 << 4\t: ");
  printBinary(~073 << 4, 16);
  printf("\n");



  printf("\ngetBits(0b101101, 2, 3)\t: ");
  printBinary(getbits(0b101101, 2, 3), 3);

  printf("\ngetBits(0b11101010001111, 7, 5)\t: ");
  printBinary(getbits(0b11101010001111, 7, 5), 5);
  printf("\n");
  return 0;
}

/* getbits: get n bits from position p at x binary */
unsigned int getbits(unsigned int x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}
