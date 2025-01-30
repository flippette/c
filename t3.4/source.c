#include "source.h"
#include <stdint.h>
#include <stdio.h>

void draw_triangle(uint32_t size) {
  for (uint32_t hashes = 1; hashes <= size; ++hashes) {
    for (uint32_t i = 0; i < size - hashes; ++i)
      printf(".");
    for (uint32_t i = 0; i < hashes; ++i)
      printf("#");
    puts("");
  }
}
