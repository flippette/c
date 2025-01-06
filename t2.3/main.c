#include <stdint.h>
#include <stdio.h>

int32_t square(int32_t n) { return n * n; }
int32_t powerthree(int32_t n) { return n * n * n; }

int32_t main(void) {
  int32_t val = square(3);            // val becomes 9
  int32_t val2 = square(val * 2);     // val2 becomes 18 * 18
  int32_t val3 = square(square(val)); // val3 becomes (9*9) * (9*9)
  int32_t val4 = powerthree(13);

  printf("val2: %d  val3: %d  val4: %d\n", val2, val3, val4);
  return 0;
}
