#include <stdint.h>
#include <stdio.h>

void *read_int(void *number) {
  if (number == NULL)
    return NULL;

  int ret;
  if (!scanf("%d", &ret))
    return NULL;

  *(int *)number = ret;
  return number;
}

int32_t main(void) {
  int a;
  int *ret = read_int(&a);
  printf("return value: %p\n", ret);
  if (ret)
    printf("reading succeeded: %d\n", a);
  else
    printf("not a valid number\n");

  return 0;
}
