#include <stdio.h>

bool equal(int *a, int *b, int n);
bool test_swap(int *data, int length, int p_index,  int k, int *expected);
void swap_window(int *base, int *p, int k);

int main(void) {
    {
        int data[]     = { 1, 2, 3, 4, 5, 6 };
        int expected[] = { 1, 2, 5, 4, 3, 6 };
        test_swap(data, 6, 4, 3, expected);
    }

    {
        int data[]     = { 10, 20, 30, 40 };
        int expected[] = { 40, 30, 20, 10 };
        test_swap(data, 4, 3, 4, expected);
    }

    {
        int data[]     = { 7, 8, 9 };
        int expected[] = { 7, 8, 9 };
        test_swap(data, 3, 2, 1, expected);
    }

    return 0;
}

void swap_window(int *base, int *p, int k) {
  int *e = p - (k - 1);
  int t;
  while (e < p) {
    t = *p;
    *p = *e;
    *e = t;
    p--;e++;
  }
}

bool equal(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) != *(b + i))
            return false;
    }
    return true;
}

bool test_swap(int *data, int length,
               int p_index, int k,
               int *expected) {
    static int test_id = 1;
    bool res;

    printf("TEST %d\nINPUT : ", test_id++);
    for (int i = 0; i < length; i++)
        printf("%d ", *(data + i));

    swap_window(data, data + p_index, k);

    printf("\nEXPCT : ");
    for (int i = 0; i < length; i++)
        printf("%d ", *(expected + i));

    printf("\nYOURS : ");
    for (int i = 0; i < length; i++)
        printf("%d ", *(data + i));

    res = equal(data, expected, length);
    printf("\n%s\n\n", res ? "PASS" : "FAIL");

    return res;
}
