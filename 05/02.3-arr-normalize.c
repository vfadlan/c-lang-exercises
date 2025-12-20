#include <stdio.h>

void normalize(int *data, int length);
bool test(int *data, int *expected, int length);
int nTest = 1;

int main(void) {
    {
        int data[]     = { 100, 103, 98, 110, 107 };
        int expected[] = {   0,   3, -2,  10,   7 };
        test(data, expected, 5);
    }

    {
        int data[]     = { 42 };
        int expected[] = { 0 };
        test(data, expected, 1);
    }

    {
        int data[]     = { -5, -3, -10, 0 };
        int expected[] = {  0,  2,  -5, 5 };
        test(data, expected, 4);
    }

    {
        int data[]     = { 0, 0, 0, 0 };
        int expected[] = { 0, 0, 0, 0 };
        test(data, expected, 4);
    }

    return 0;
}

void normalize(int *data, int length) {
  for (int i = 1; i < length; i++) {
    *(data + i) = *(data + i) - *data;
  }
  *data = 0;
}

bool test(int *data, int *expected, int length) {
  int i;
  bool res = true;
  printf("TEST CASE %d\nINPUT : ", nTest++);
  for (i=0; i<length; i++) {
    printf("%d ", *(data+i));
  }
  printf("\nEXPCT : ");
  for (i=0; i<length; i++) {
    printf("%d ", *(expected+i));
  }
  normalize(data, length);
  printf("\nYOURS : ");
  for (i=0; i<length; i++) {
    printf("%d ", *(data+i));
    if (*(data+i) != *(expected+i)) {
      res = false;
    }
  }
  printf("\n%s\n\n", (res) ? "PASS" : "FAIL");

  return res;
}
