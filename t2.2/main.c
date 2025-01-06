#include <stdint.h>
#include <stdio.h>

int32_t main() {
  int8_t a = -50;
  uint8_t b = 200;
  uint16_t b2 = 500;
  int32_t c = 0;
  int64_t d = 100000; // FIGHT ME

  printf("%d  %u  %u  %d  %ld\n", a, b, b2, c, d);
  return 0;
}
