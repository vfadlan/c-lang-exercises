#include <stdio.h>

void escape(char s[], char t[]);

int main() {
    // Define a sufficiently large buffer for the escaped string.
    // Since '\n' becomes '\' and 'n', the output can be up to twice the length.
    #define MAX_BUFFER 100
    char s[MAX_BUFFER];
    const char *test_case;

    printf("--- K&R Exercise 3-2: escape(s, t) Test Harness ---\n\n");

    // Scenario 1: Basic test with a single newline character.
    // Checks if '\n' is correctly converted to '\\n'.
    test_case = "First line\nSecond line.";
    escape(s, (char*)test_case);
    printf("Scenario 1: Newline (\\n)\n");
    printf("  Original (t): '%s'\n", test_case);
    printf("  Expected Escaped (s): 'First line\\nSecond line.'\n");
    printf("  Actual Escaped (s):  '%s'\n\n", s);

    // Scenario 2: Test multiple different escape characters (tab and newline).
    // Checks complex sequences and handling of adjacent escapes.
    test_case = "Header:\tValue\nNew record.";
    escape(s, (char*)test_case);
    printf("Scenario 2: Mixed Escapes (\\t and \\n)\n");
    printf("  Original (t): '%s'\n", test_case);
    printf("  Expected Escaped (s): 'Header:\\tValue\\nNew record.'\n");
    printf("  Actual Escaped (s):  '%s'\n\n", s);

    // Scenario 3: Edge case test with no special characters.
    // Checks if ordinary characters are copied correctly without modification.
    test_case = "Just plain text.";
    escape(s, (char*)test_case);
    printf("Scenario 3: No Escapes\n");
    printf("  Original (t): '%s'\n", test_case);
    printf("  Expected Escaped (s): 'Just plain text.'\n");
    printf("  Actual Escaped (s):  '%s'\n\n", s);

    // Scenario 4: Edge case with escapes at the very start and end of the string.
    // Checks boundary conditions.
    test_case = "\t\tStart tabs\nEnd newline\n";
    escape(s, (char*)test_case);
    printf("Scenario 4: Boundary Escapes (Start and End)\n");
    printf("  Original (t): '%s'\n", test_case);
    printf("  Expected Escaped (s): '\\t\\tStart tabs\\nEnd newline\\n'\n");
    printf("  Actual Escaped (s):  '%s'\n\n", s);

    return 0;
}

void escape(char s[], char t[]) {
  char c, i = 0, j = 0;

  while ((c = t[i]) != '\0') {
    switch(c) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      default:
        s[j++] = c;
        break;
    }
    i++;
  }

  s[j] = '\0';
}