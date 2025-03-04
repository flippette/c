#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
  char a = 10;
  char b = 12;
  char *d = &a;

  *d = 13;
  printf("*d: %d   d: %p   a: %d\n", *d, (void *)d, a);
  if (*d > b)
    printf("New value is greater than b!\n");
  *d = 14;
  printf("d: %d\n", *d);
  *d = 15;
  printf("d is now: %d\n", *d);
  printf("Bye bye!\n");

  return 0;
}
