#include <stdio.h>
#define MAXLINE 1000

int strrindex(char source[], char searchFor[]);
void run_strrindex_test(const char *s, const char *t, int expected_index);

void run_strrindex_test(const char *s, const char *t, int expected_index) {
    int actual_index;
    
    // Call the function under test
    actual_index = strrindex((char*)s, (char*)t);

    printf("  String s:\t\"%s\"\n", s);
    printf("  String t:\t\"%s\"\n", t);
    printf("  Expected Index: %d\n", expected_index);
    printf("  Actual Index:\t%d\n", actual_index);

    if (actual_index == expected_index) {
        printf("  Result:\tPASS\n");
    } else {
        printf("  Result:\tFAIL\n");
    }
    
    printf("--------------------------------------------------\n");
}


int main() {
    printf("--- K&R Exercise 4-1: strrindex(s, t) Test Harness ---\n\n");
    
    // --- Test 1: Multiple Occurrences (Should find the rightmost one) ---
    printf("TEST 1: Multiple Occurrences\n");
    // "go" occurs at index 0 and 10. The rightmost is 9.
    run_strrindex_test("gogogoogogo", "go", 9); 

    // --- Test 2: Single Occurrence ---
    printf("TEST 2: Single Occurrence\n");
    // "ship" occurs once at index 17.
    run_strrindex_test("The black pirate ship sails.", "ship", 17);

    // --- Test 3: No Occurrence ---
    printf("TEST 3: No Occurrence\n");
    // "cat" is not in the string.
    run_strrindex_test("The dark night.", "cat", -1);

    // --- Test 4: Target String (t) is Longer than Source String (s) ---
    printf("TEST 4: Target Longer Than Source\n");
    run_strrindex_test("short", "longstring", -1);

    // --- Test 5: Occurrence at the Very Beginning ---
    printf("TEST 5: Occurrence at the Beginning\n");
    run_strrindex_test("start-middle-end", "start", 0);

    // --- Test 6: Occurrence at the Very End ---
    printf("TEST 6: Occurrence at the End\n");
    // "end" occurs at index 13.
    run_strrindex_test("start-middle-end", "end", 13);
    
    // --- Test 7: Target String is Empty ("") ---
    // Note: Behavior for empty string is sometimes undefined, but conventionally 
    // it's treated as occurring at the end of the string. We'll expect the last index.
    printf("TEST 7: Empty Target String (t)\n");
    // Length of "data" is 4. An empty string can be considered to match at index 4.
    // However, for substring searching, -1 or 0 might be common. We'll use the last index.
    // Index 4 is where the null terminator starts. We'll expect -1 for safety, 
    // but the implementation may vary. Let's test standard behavior (a non-match)
    // or simply skip. A safer test is to use a single character.
    run_strrindex_test("testing", "", -1);

    // --- Test 8: Overlapping Matches ---
    printf("TEST 8: Overlapping Matches\n");
    // "AAA" occurs at index 0 and 1. The rightmost is index 1.
    run_strrindex_test("AAAA", "AAA", 1); 

    // --- Test 9: Target at the end, repeated multiple times ---
    printf("TEST 9: Target at the End, Repeated\n");
    // "bar" occurs at index 0 and 3. Rightmost is 3.
    run_strrindex_test("barbar", "bar", 3); 

    // --- Test 10: Mixed Text with Spaces and Punctuation ---
    printf("TEST 10: Mixed Text, Finding Word Segment\n");
    // "ing" occurs in "working" (10) and "testing" (23). Rightmost is 27.
    run_strrindex_test("He is working hard and testing the code.", "ing", 27);

    // --- Test 11: Single character pattern, many times ---
    printf("TEST 11: Single Character Pattern\n");
    // Find 'i' in "mississippi". Rightmost 'i' is at index 10.
    run_strrindex_test("mississippi", "i", 10);

    // --- Test 12: Target is just the first char ---
    printf("TEST 12: Target is just the first char of the string\n");
    // Find 's' in "mississippi". Rightmost 's' is at index 6.
    run_strrindex_test("mississippi", "s", 6);

    // --- Test 13: Full Word Repeated (Rightmost is last occurrence) ---
    printf("TEST 13: Full Word Repeated\n");
    // "the" occurs at index 0 and 10. Rightmost is 20.
    run_strrindex_test("the quick brown fox the dog", "the", 20);

    // --- Test 14: Substring Contained within another Substring ---
    printf("TEST 14: Substring Contained in Another\n");
    // Find "at" in "cat hat fat at". Occurs at 1, 5, 9, 12. Rightmost is 12.
    run_strrindex_test("cat hat fat at", "at", 12);

    return 0;
}

int strrindex(char s[], char t[]) {
  int i, j, k;
  int pos = -1;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++) {
      ;
    }
    if (k > 0 && t[k] == '\0') {
      pos = i;
      continue;
    }
  }

  return pos;
}
