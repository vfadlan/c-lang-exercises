#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char searchFor[]);
double atof(char s[]);

char pattern[] = "ould";

int main() {
  double sum; 
  char line[MAXLINE];
  int found = 0;

  sum = 0;
  while (getLine(line, MAXLINE) > 0) {
    printf("\t%g\n", sum+=atof(line));
  }

  return found;
}

int getLine(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
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
