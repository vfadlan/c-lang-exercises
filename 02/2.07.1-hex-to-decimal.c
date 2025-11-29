#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define LIM 1000

int getLine(char s[], int lim);
bool format(char s[], int len);
long hex2dec(char s[], int len);

int main() { 
  int len;
  long dec;
  char s[LIM];

  while ((len = getLine(s, LIM)) > 0) {
    if(format(s, len)) {
      dec = hex2dec(s, len);
      if (dec >= 0) {
         printf("dec: %ld\n\n", dec);
      } else {
        printf("HEX Input is too large.\nConversion Abort.\n\n");
      }
    }
  }

  return 0;
}

int getLine(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i ) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

bool format(char s[], int lim) {
  int c, i;
  for (i=0; i < lim; i++) {
    s[i] = toupper(s[i]);

    if (
      !(
      (s[i] >= '0' && s[i] <= '9') || 
      (s[i] >= 'A' && s[i] <= 'F') || 
      (s[i] == 'X') || 
      (s[i] == '\n') || 
      (s[i] == '\0')
    )) {
      printf("Illegal character. %c is not a HEX.\nConversion Abort.\n\n", s[i]);
      return false;
    }

    if (s[i] == '\0') {
      break;
    }
  }

  return true;
}

long hex2dec(char s[], int len) {
  int i = 0;
  unsigned long dec = 0, h;
  printf("Hexval: ");

  for (i = 0; i <= len && s[i] != '\n' && s[i] != '\0'; ++i) {
    if (s[i] >= '0' && s[i] <= '9') {
      h = s[i] - '0';
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      h = s[i] - 'A' + 10;
    } else if (s[i] == '\0' || s[i] == '\n' || s[i] == 'X') {
      h = 0;
    } else {
      break;
    }
    printf("%c:%ld ", s[i], h);
    dec = (dec * 16) + h;
  }

  printf("\n");

  return dec;
}
