#include "source.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Creates a dynamically allocated array and reads the specified number
 * of integers from the standard input stream.
 *
 * \param n The number of integers to be read
 * \return A pointer to the allocated and filled array
 */
int *create_dyn_array(unsigned int n) {
  int *ret = malloc(n * sizeof(int));
  if (!ret)
    return ret;
  for (size_t i = 0; i < n; ++i) {
    int in;
    if (!scanf("%d", &in))
      break;
    ret[i] = in;
  }
  return ret;
}

/**
 * \brief Appends a new element to the existing and dynamically allocated array
 *
 * \param arr The dynamically allocated array of num elements
 * \param num The number of elements in arr
 * \param newval The value of the new element that will be appended
 * \return A pointer to the resized array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval) {
  int *re = realloc(arr, num * sizeof(int));
  if (!re)
    return re;
  re[num] = newval;
  return re;
}
