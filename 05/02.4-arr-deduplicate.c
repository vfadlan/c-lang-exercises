#include <stdio.h>

int dedup_sorted(int *data, int length);
bool test(int*data, int *expected, int length, int unique);
int nTest = 1;

int main(void) {
    {
        int data[]     = { 1, 1, 2, 2, 2, 5, 7, 7, 9 };
        int expected[] = { 1, 2, 5, 7, 9 };
        test(data, expected, 9, 5);
    }

    {
        int data[]     = { 1, 1, 1, 1 };
        int expected[] = { 1 };
        test(data, expected, 4, 1);
    }

    {
        int data[]     = { 1, 2, 3, 4 };
        int expected[] = { 1, 2, 3, 4 };
        test(data, expected, 4, 4);
    }

    {
        int data[]     = { 5 };
        int expected[] = { 5 };
        test(data, expected, 1, 1);
    }

    return 0;
}
int dedup_sorted(int *data, int length) {
  int i, j = 0;

  *(data + j++) = *data;
  for (i=1; i<length; i++) {
    if (*(data + i) != *(data + j - 1)) {
      *(data + j++) = *(data + i);
    }
  }

  return j;
}

bool test(int *data, int *expected, int length, int unique) {
    int i;
    bool res = true;

    printf("TEST CASE %d\nINPUT : ", nTest++);
    for (i = 0; i < length; i++) {
        printf("%d ", *(data + i));
    }

    int q = dedup_sorted(data, length);

    printf("\nEXPCT : ");
    for (i = 0; i < unique; i++) {
        printf("%d ", *(expected + i));
    }
    printf("(len=%d)", unique);

    printf("\nYOURS : ");
    for (i = 0; i < q; i++) {
        printf("%d ", *(data + i));
    }
    printf("(len=%d)", q);

    if (q != unique) {
        res = false;
    }

    for (i = 0; i < unique && i < q; i++) {
        if (*(data + i) != *(expected + i)) {
            res = false;
        }
    }

    printf("\n%s\n\n", res ? "PASS" : "FAIL");
    return res;
}

