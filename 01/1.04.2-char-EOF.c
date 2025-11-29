#include <stdio.h>

/* 
  (E1-6) Verify that the expression getchar() != EOF is 0 or 1
  (E1-7) Print the value of EOF
*/
int main() {
  int c = getchar();
  putchar(c);

  printf("\nIs character '%c' != EOF? %d\n", c, (c != EOF));
  printf("Value of EOF: %d\n", EOF);
  return 0;
}
