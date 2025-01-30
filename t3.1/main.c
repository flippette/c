#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
  int32_t a = 1;
  int32_t b = 6;
  a += 1;
  b += 1;
  a = a + b;
  printf("a: %d", a);
  return 0;
}
