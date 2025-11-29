#include <stdio.h>

#define MAXLINE 1000

int inputLine(char s[], int maxlen);
void reverse(char s[], int len);

int main() {
  int len;
  char s[MAXLINE];

  while ((len=inputLine(s, MAXLINE)) > 0) {
    reverse(s, len);
    printf("%s", s);
  }
}

int inputLine(char s[], int maxlen) {
  int c, i;

  for (i=0; i<maxlen-1 && (c=getchar()) != EOF && c!= '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void reverse(char s[], int len) {
  int i = 0;
  int j = j - 2;
  char tempC;

  while (i < j) {
    tempC = s[i];
    s[i] = s[j];
    s[j] = tempC;
    ++i;
    --j;
  }
}
