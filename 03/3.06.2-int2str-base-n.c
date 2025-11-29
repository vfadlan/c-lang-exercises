#include <stdio.h>
#include <string.h>
#include <limits.h> // Essential for INT_MIN

// Function definition for itoa. 
// When compiling, the user must link this program with the original K&R itoa implementation.
void itob(int n, char s[], int b);
void reverse(char s[], int len);
void run_itob_test(int input_n, int base, const char *expected_s);

void run_itob_test(int input_n, int base, const char *expected_s) {
    // A buffer of 34 is sufficient for INT_MIN in base 2.
    #define MAX_BUFFER 50 
    char output[MAX_BUFFER] = {0}; // Initialize buffer
    
    // Call the function under test
    itob(input_n, output, base);

    printf("  Input (n)\t: %d\n", input_n);
    printf("  Base (b)\t: %d\n", base);
    printf("  Expected (s)\t: \"%s\"\n", expected_s);
    printf("  Actual (s)\t: \"%s\"\n", output);
    printf("  Result\t: %s\n", strcmp(expected_s, output) ? "FAIL" : "PASS");
    printf("--------------------------------------------------\n");
}


int main() {
    printf("--- K&R Exercise 3-5: itob(n, s, b) Test Harness ---\n\n");
    
    // --- Test 1: Basic Decimal (Base 10) ---
    printf("TEST 1: Standard Base 10\n");
    run_itob_test(12345, 10, "12345");

    // --- Test 2: Binary (Base 2) ---
    printf("TEST 2: Binary (Base 2) - Positive\n");
    // 25 decimal = 11001 binary
    run_itob_test(25, 2, "11001");

    // --- Test 3: Octal (Base 8) ---
    printf("TEST 3: Octal (Base 8) - Negative\n");
    // -63 decimal = -77 octal
    run_itob_test(-63, 8, "-77");

    // --- Test 4: Hexadecimal (Base 16) ---
    printf("TEST 4: Hexadecimal (Base 16) - Uses Letters\n");
    // 255 decimal = FF hexadecimal
    run_itob_test(255, 16, "FF");

    // --- Test 5: Custom Base (Base 36) ---
    printf("TEST 5: Custom Base 36 - Uses all digits and letters\n");
    // 1000 decimal = RM in base 36 (R is 27, M is 22. 27*36 + 22 = 1000)
    run_itob_test(1000, 36, "RS");
    
    // --- Test 6: Zero (Base 16) ---
    printf("TEST 6: Zero Input\n");
    run_itob_test(0, 16, "0");

    // --- Test 7: INT_MIN in Base 16 (Crucial Negative Case) ---
    printf("TEST 7: INT_MIN in Hexadecimal (Base 16)\n");
    // INT_MIN (32-bit): -2147483648, which is -80000000 in hex
    run_itob_test(INT_MIN, 16, "-80000000");

    return 0;
}

void itob(int n, char s[], int b) {
  int i, r, sign;

  i = 0;

  sign = n;

  do {
    r = n % b;
    if (n < 0) r = -r;
    if (r < 10) {
     s[i++] = r + '0';
    } else if (r >= 10) {
      s[i++] = r + 'A' - 10;
    }
  } while ((n /= b) != 0);

  if (sign < 0) {
    s[i++] = '-';
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
