#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Function definition for the extended atof (K&R 4-2).
// This function should handle scientific notation (e.g., "1.23e-4").
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
    printf("--- K&R Exercise 4-2: Extended atof() Test Harness (10 Tests) ---\n\n");
    
    // --- Test 1: Positive Exponent ---
    printf("TEST 1: Positive Exponent (e3)\n");
    // 1.2 * 10^3 = 1200.0
    run_atof_test("1.2e3", 1200.0); 

    // --- Test 2: Negative Exponent ---
    printf("TEST 2: Negative Exponent (e-4)\n");
    // 9.9 * 10^-4 = 0.00099
    run_atof_test("9.9e-4", 0.00099);

    // --- Test 3: Large Number with Uppercase E and Decimal Point ---
    printf("TEST 3: Uppercase E and large positive power\n");
    // 6.022 * 10^23 (Avogadro's Number - approximation)
    run_atof_test("6.022E23", 6.022e23);

    // --- Test 4: Negative Mantissa, Large Negative Exponent ---
    printf("TEST 4: Negative Mantissa and Negative Exponent\n");
    // -5.0 * 10^-6 = -0.000005
    run_atof_test("-5.0e-6", -0.000005); 

    // --- Test 5: No Decimal Point on Mantissa, Explicit Plus Sign in Exponent ---
    printf("TEST 5: No Decimal Point, Explicit Plus Exponent\n");
    // 3 * 10^+4 = 30000.0
    run_atof_test("3e+4", 30000.0);

    // --- Test 6: Zero Exponent (e0 or E0) ---
    printf("TEST 6: Exponent of Zero (E0)\n");
    // Should return the mantissa value unchanged: 198.4.
    run_atof_test("198.4E0", 198.4);

    // --- Test 7: Mantissa starts with decimal point, negative exponent ---
    printf("TEST 7: Starts with Decimal Point, Negative Exponent\n");
    // .5e-2 = 0.005
    run_atof_test(".5e-2", 0.005);

    // --- Test 8: Large Negative Exponent without sign on Mantissa ---
    printf("TEST 8: Large Negative Exponent\n");
    // 1.0 * 10^-10 = 0.0000000001
    run_atof_test("1.0e-10", 1e-10);
    
    // --- Test 9: Whitespace and Exponent (Checking parsing robustness) ---
    printf("TEST 9: Whitespace Before Exponent\n");
    // " 12 E 3" - should only read "12" then stop at the space before 'E'. 
    // If spaces are handled correctly after the number starts, this is complex.
    // Assuming K&R style stops parsing after non-digit/non-e/non-dot.
    // If the loop continues, the space before E might cause issues. 
    // If implemented strictly, only leading spaces are skipped. It should parse "12".
    run_atof_test(" 12e-1", 1.2); 

    // --- Test 10: Only Integer Mantissa and Sign ---
    printf("TEST 10: Only Integer Mantissa and Negative Exponent\n");
    // -25e-1 = -2.5
    run_atof_test("-25e-1", -2.5); 


    return 0;
}

double atof(char s[]) {
  double val, power, exp, res;
  int i, sign, expSign;

  for (i=0; isspace(s[i]); i++) { continue; } // skip whitespace

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

  res = sign * val / power;

  if (s[i] == 'e' || s[i] == 'E') { i++; } // handle exponent
  expSign = (s[i] == '-') ? -1 : 1; // handle exponent sign
  if (s[i] == '-' || s[i] == '+') { i++; }

  for (exp=0.0; isdigit(s[i]); i++) {
    exp = 10.0 * exp + (s[i] - '0');
  }

  printf("%.5f %d %.5f\n", res, expSign, exp);
  res *= pow(10, expSign * exp);

  return res;
}
