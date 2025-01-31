#include "bit_sequence.h"
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
  printf("%08b\n", op_bit_get_sequence(0x55aa55aa, 0x00133026));
  return 0;
}
