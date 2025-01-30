#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
  for (int a = 8; a >= 0; a -= 2) {
    printf("value of a is now %d\n", a);
  }
  return 0;
}
