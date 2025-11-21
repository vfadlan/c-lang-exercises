#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int arr[23] = { 12,17,19,21,26,30,31,35,42,43,49,53,58,60,64,69,70,75,76,81,84,90,95 };

  printf("43: %d\n", binsearch(43, arr, 23));
  printf("24: %d\n", binsearch(24, arr, 23));
  printf("81: %d\n", binsearch(81, arr, 23));

  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;

    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}
