#include <stdio.h>
#include <string.h>
#include <limits.h> // Essential for INT_MIN

// Function definition for itoa. 
// When compiling, the user must link this program with the original K&R itoa implementation.
void itoa(int n, char s[]);
void reverse(char s[], int len);

// Helper function to convert the integer and display the result.
void demonstrate_itoa_behavior(int input_n) {
    // A standard integer requires up to 11 digits (including sign) + null.
    #define MAX_BUFFER 20 
    char output[MAX_BUFFER] = {0}; // Initialize buffer
    
    // Call the function under test
    itoa(input_n, output);

    printf("  Input (n):    %d\n", input_n);
    printf("  Actual (s):   \"%s\"\n", output);
    printf("--------------------------------------------------\n");
}


int main() {
    printf("--- K&R Original itoa() Behavior Demonstration ---\n");
    printf("Focus: Observing output, especially for the largest negative number (INT_MIN).\n\n");
    
    // --- Test 1: Positive Number (Simple Case) ---
    printf("TEST 1: Positive Integer\n");
    demonstrate_itoa_behavior(12345);

    // --- Test 2: Negative Number (Simple Case) ---
    // The original itoa handles this fine by taking the absolute value.
    printf("TEST 2: Negative Integer\n");
    demonstrate_itoa_behavior(-6789);

    // --- Test 3: Zero ---
    printf("TEST 3: Zero\n");
    demonstrate_itoa_behavior(0);

    // --- Test 4: The Flawed Case (Largest Negative Number - INT_MIN) ---
    // The original K&R code fails here because abs(INT_MIN) is still INT_MIN.
    printf("TEST 4: INT_MIN (Largest Negative Number)\n");
    demonstrate_itoa_behavior(INT_MIN);
    
    // --- Test 5: Largest Positive Number (INT_MAX) ---
    printf("TEST 5: INT_MAX (Largest Positive Number)\n");
    demonstrate_itoa_behavior(INT_MAX);

    return 0;
}

void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }

  i = 0;

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

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
