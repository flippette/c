#include "source.h"

#include <stdlib.h>
#include <string.h>

/**
 * \brief Concatenates the source string to the destination string.
 *
 * This function appends the source string to the destination string,
 * reallocating memory for the destination string to ensure it can hold the
 * combined result.
 *
 * \param dest A pointer to the destination string. This string will be modified
 *             and should be dynamically allocated.
 * \param src  A pointer to the source string. This string will be appended to
 *             the destination string.
 * \return A pointer to the destination string after concatenation.
 */
char *my_strcat(char *dest, const char *src) {
  size_t src_len = strlen(src);
  size_t dest_len = strlen(dest);
  char *ret = realloc(dest, dest_len + src_len + 1);
  memcpy(ret + dest_len, src, src_len + 1);
  return ret;
}
