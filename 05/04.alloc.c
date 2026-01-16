#define ALLOC_SIZE 1000

static char allocbuf[ALLOC_SIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
  if (allocbuf + ALLOC_SIZE - allocp >= n) { // first ever element + total element - last used element >= n (fits)
    allocp += n;
    return allocp - n;
  } else {
    return 0;
  }
}

void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOC_SIZE) { // within bounds
    allocp = p;
  }
}