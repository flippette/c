#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
  int32_t a;
  float f;

  char buf[128];
  fgets((char *)&buf, sizeof(buf), stdin);
  printf("Captured %i\n", sscanf((char *)&buf, "%i %f", &a, &f));
  printf("Integer is %#010x\n", a);
  printf("Floating-point number is %8.3f\n", f);

  return 0;
}
