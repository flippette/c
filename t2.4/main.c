#include <stdint.h>
#include <stdio.h>

#include "source.h"

int32_t main(void) {
  printf("%.3f %.3f %.3f\n", fracsum(1, 2, 2, 4), fracsum(1, 4, 1, 8),
         fracsum(4, 3, 5, 6));

  return 0;
}
