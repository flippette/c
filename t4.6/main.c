#include "header.h"
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
  printf("%d\n", validateHeader(1120084906));
  printf("%d\n", createAckHeader(32, 231, 12, 0));
  printf("%d\n", createHeader(98, 162, 13, 1));
  return 0;
}
