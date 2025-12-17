#include <stdio.h>

void swap(int x, int y);
void swapp(int *x, int *y);

int main() {
  int x = 2;
  int y = 6;
  printf("%d-%d\n", x, y);
  swap(x,y);
  printf("%d-%d\n", x, y);
  swapp(&x, &y);
  printf("%d-%d\n", x, y);
}

void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void swapp(int *x, int *y) {
  int temp = *x; // temp is whatever the value of x (deref)
  *x = *y;  // result of x dereference is the result of y dereference, i.e. x = y by reference
  *y = temp; // result of y dereference is whataver it was stored in temp
}
