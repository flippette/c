#include <stdint.h>
#include <stdio.h>

#include "source.h"

int32_t main(void) {
  printf("Length of vector (1,2,3): %f\n", vectorlength(1, 2, 3));
  printf("Length of vector (1,1,1): %f\n", vectorlength(1, 1, 1));
  printf("Length of vector (1,0,0): %f\n", vectorlength(1, 0, 0));
  printf("Length of vector (0.3, 0.3, 0.1): %f\n", vectorlength(0.3, 0.3, 0.1));
  return 0;
}
