#include <stdio.h>
#include <string.h>
#include <limits.h> // Essential for INT_MIN

// Function definition for itoa. 
// When compiling, the user must link this program with the original K&R itoa implementation.
void itoa(int n, char s[], int mw);
void reverse(char s[], int len);
void run_itoa_test(int input_n, int width, const char *expected_s);

void run_itoa_test(int input_n, int width, const char *expected_s) {
    // A buffer of 50 is more than safe for any standard int and width.
    #define MAX_BUFFER 50 
    char output[MAX_BUFFER] = {0}; // Initialize buffer
    
    // Call the function under test
    itoa(input_n, output, width);

    printf("  Input (n):\t%d\n", input_n);
    printf("  Width (w):\t%d\n", width);
    printf("  Expected (s):\t\"%s\"\n", expected_s);
    printf("  Actual (s):\t\"%s\"\n", output);

    // Using strcmp for correct string content comparison
    if (strcmp(expected_s, output) == 0) {
        printf("  Result:\tPASS\n");
    } else {
        printf("  Result:\tFAIL\n");
    }
    
    printf("--------------------------------------------------\n");
}


int main() {
    printf("--- K&R Exercise 3-6: itoa(n, s, w) Test Harness (Width Padding) ---\n\n");
    
    // --- Test 1: Standard conversion (No padding needed) ---
    printf("TEST 1: Standard Conversion (w is less than length)\n");
    // Length of "12345" is 5.
    run_itoa_test(12345, 3, "12345");

    // --- Test 2: Basic Padding (Positive Number) ---
    printf("TEST 2: Basic Padding (Positive)\n");
    // Length of "42" is 2. Needs 3 spaces of padding for w=5.
    run_itoa_test(42, 5, "   42");

    // --- Test 3: Basic Padding (Negative Number) ---
    printf("TEST 3: Basic Padding (Negative)\n");
    // Length of "-123" is 4. Needs 1 space of padding for w=5.
    run_itoa_test(-123, 5, " -123");

    // --- Test 4: The INT_MIN Case (Must be handled correctly) ---
    // This tests the core 3-6 requirement of handling INT_MIN without overflow.
    // Length of INT_MIN (-2147483648) is 11. Width is 11, so no padding.
    printf("TEST 4: INT_MIN (Correct Overflow Handling)\n");
    run_itoa_test(INT_MIN, 11, "-2147483648");
    
    // --- Test 5: INT_MIN with Padding ---
    printf("TEST 5: INT_MIN with Padding\n");
    // Length is 11. Needs 4 spaces of padding for w=15.
    run_itoa_test(INT_MIN, 15, "    -2147483648");
    
    // --- Test 6: Zero with Padding ---
    printf("TEST 6: Zero with Padding\n");
    // Length is 1. Needs 4 spaces of padding for w=5.
    run_itoa_test(0, 5, "    0");


    return 0;
}

void itoa(int n, char s[], int mw) {
  int i, r, sign;

  sign = n;
  i = 0;

  do {
    r = n%10;
    if (n < 0) r = -r;
    s[i++] = r + '0';
  } while ((n /= 10) != 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  while (i < mw) {
    s[i++] = ' ';
  }

  s[i] = '\0';
  reverse(s, i+1);
}

void reverse(char s[], int len) {
  int i = 0;
  int j = len - 2;
  char tempC;

  while (i < j) {
    tempC = s[i];
    s[i] = s[j];
    s[j] = tempC;
    ++i;
    --j;
  }
}
