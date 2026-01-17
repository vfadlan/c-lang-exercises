#include <stdio.h>

int stringend(char *s, char *t);

int main()
{
  printf("stranded | ed | %d\n", stringend("stranded", "ed"));
  printf("exhausted| ed | %d\n", stringend("exhausted", "ed"));
  printf("Capek | ek | %d\n", stringend("Capek", "ek"));
  printf("Hebat | ek | %d\n", stringend("Hebat", "ek"));
  printf("Raksasa | et | %d\n", stringend("Raksasa", "et"));
}

int stringend(char *s, char *t)
{
  int lens = 0;
  int lent = 0;
  while (*s++)
    lens++;
  while (*t++)
    lent++;
  *s--;
  *t--;
  while ((*s--) == (*t--) && lent)
    lent--;
  return (lent == 0) ? 1 : 0;
 }