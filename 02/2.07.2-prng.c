#include <stdio.h>

unsigned long next = 1;

int rand(void);
void srand(unsigned int seed);

int main() {
  int i, seed, ranum = 24;

  printf("i\tseed\tranum\n");

  for (i = 1; i <= 10; i++) {
    srand(ranum);
    seed = ranum;
    ranum = rand();

    printf("%d\t%d\t%d\n", i, seed, ranum);
  }

  return 0;
}

int rand(void) {
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}
