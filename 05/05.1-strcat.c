#include <stdio.h>

void stringcat(char *s, char *t);

int main()
{
  char s[20] = "Abcdefg";
  char t[6] = "JKLMN";
  stringcat(s, t);
  printf(s);
}

void stringcat(char *s, char *t)
{
  char *p = s;
  while (*s++)
    ;
  *s--;
  while (*s++ = *t++)
    ;
}