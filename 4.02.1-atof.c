#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h> // Needed for comparing floating point numbers

// Function definition for the original K&R atof (Section 3.4).
// This version should ONLY handle standard fixed-point numbers (e.g., "123.45").
// The user must provide the body of this function when compiling.
double atof(char s[]);

// Helper function to safely run the test and display the result.
void run_atof_test(const char *input_s, double expected_d) {
    double actual_d;
    
    // Call the function under test
    actual_d = atof((char*)input_s);

    printf("  Input (s):\t\"%s\"\n", input_s);
    printf("  Expected (d):\t%.10f\n", expected_d);
    printf("  Actual (d):\t%.10f\n", actual_d);

    // Using a small tolerance (epsilon) for floating-point comparison.
    const double EPSILON = 1e-9;
    
    // Check if the difference between actual and expected is within EPSILON
    if (fabs(actual_d - expected_d) < EPSILON) {
        printf("  Result:\tPASS\n");
    } else {
        printf("  Result:\tFAIL\n");
    }
    
    printf("--------------------------------------------------\n");
}


int main() {
    printf("--- K&R Section 3.4: Original atof() Test Harness (Fixed Point Only) ---\n\n");
    
    // --- Test 1: Simple Positive Integer ---
    printf("TEST 1: Positive Integer\n");
    run_atof_test("123", 123.0);

    // --- Test 2: Simple Negative Integer ---
    printf("TEST 2: Negative Integer\n");
    run_atof_test("-45", -45.0); 

    // --- Test 3: Positive Fractional Number ---
    printf("TEST 3: Positive Fractional Number\n");
    run_atof_test("67.89", 67.89);

    // --- Test 4: Negative Fractional Number ---
    printf("TEST 4: Negative Fractional Number\n");
    run_atof_test("-0.001", -0.001); 

    // --- Test 5: Number with leading whitespace ---
    printf("TEST 5: Leading Whitespace\n");
    // Original K&R atof is expected to skip leading whitespace.
    run_atof_test("  987.65", 987.65);

    // --- Test 6: Number starting with decimal point ---
    printf("TEST 6: Starting with Decimal Point\n");
    // Should be read as 0.5.
    run_atof_test(".5", 0.5);

    // --- Test 7: Zero and mixed formatting ---
    printf("TEST 7: Zero\n");
    run_atof_test("0.0", 0.0);

    return 0;
}

double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i=0; isspace(s[i]); i++) { continue;} // skip whitespace

  sign = (s[i] == '-') ? -1 : 1; // handle sign
  if (s[i] == '-' || s[i] == '+') { i++; }

  for (val=0.0; isdigit(s[i]); i++) {
    val = val * 10 + (s[i] - '0');
  }

  if (s[i] == '.' || s[i] == ',') { i++; } // handle decimal symbol

  for (power=1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  return sign * val / power;
}
