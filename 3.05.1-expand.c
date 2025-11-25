#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char s1[], char s2[]);

// Helper function to safely compare two strings and print the result
void run_test(const char *input, const char *expected) {
    // Determine a sufficiently large buffer for the output string.
    // The maximum possible expansion (a-z0-9A-Z) is about 62 characters, so 300 is safe.
    #define MAX_BUFFER 300
    char output[MAX_BUFFER] = {0}; // Initialize to all zeros (including null terminator)
    
    expand((char*)input, output);

    printf("  Input (s1):   \"%s\"\n", input);
    printf("  Expected (s2): \"%s\"\n", expected);
    printf("  Actual (s2):   \"%s\"\n", output);

    if (strcmp(output, expected) == 0) {
        printf("  Result: PASS\n");
    } else {
        printf("  Result: *** FAIL ***\n");
    }
    printf("--------------------------------------------------\n");
}


int main() {
    printf("--- K&R Exercise 3-3: expand(s1, s2) Test Harness ---\n\n");
    
    // --- Test 1: Basic Alphabetic Range (Lowercase) ---
    printf("TEST 1: Basic Lowercase Range\n");
    run_test("a-f", "abcdef");

    // --- Test 2: Basic Numeric Range ---
    printf("TEST 2: Basic Numeric Range\n");
    run_test("1-5", "12345");

    // --- Test 3: Multiple and Concatenated Ranges ---
    printf("TEST 3: Multiple & Mixed Ranges\n");
    run_test("a-c0-2x-z", "abc012xyz");

    // --- Test 4: Uppercase Range ---
    printf("TEST 4: Uppercase Range\n");
    run_test("A-E", "ABCDE");
    
    // --- Test 5: Invalid/Backward Range (Should NOT Expand) ---
    printf("TEST 5: Invalid/Backward Range\n");
    // Should copy literally, treating the hyphen as a normal character.
    run_test("f-a", "f-a");
    
    // --- Test 6: Hyphen at Start and End (Should NOT Expand) ---
    printf("TEST 6: Leading and Trailing Hyphens\n");
    // The hyphens should be copied literally.
    run_test("-a-z-", "-abcdefghijklmnopqrstuvwxyz-");
    
    // --- Test 7: Mixed Case/Type Range (Should NOT Expand) ---
    printf("TEST 7: Mixed Type Range (Letter-Digit)\n");
    // Should copy literally, as 'a' and '9' are different types.
    run_test("a-9", "a-9");

    // --- Test 8: Complex string with escapes and literal hyphens ---
    printf("TEST 8: Complex String with Literals\n");
    run_test("Hello 1-3 World a-c", "Hello 123 World abc");

    return 0;
}

void expand(char s1[], char s2[]) {
  int i=0, j=0, k=0;
  char c, pc;

  while ((c = s1[i]) != '\0') {    
    if (c == '-' && isalnum(pc) && pc < s1[i+1] && isalnum(s1[i+1])) {
      for (k=pc+1; k < s1[i+1]; k++, j++) {
        s2[j] = k;
      }
    } else {
      s2[j] = c;
      j++;
    }
    pc = c;
    i++;
  }
}
