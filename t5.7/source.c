#include "source.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/* Print string */
/* Parameters:
 * s: string to be printed */

/**
 * \brief Prints ? terminated string
 *
 * \param s A ? terminated string
 */
void qstr_print(const char *s) {
  for (size_t i = 0; i < qstr_length(s); ++i)
    putchar(s[i]);
}

/**
 * \brief Returns the length of a ? terminated string
 *
 * \param s A ? terminated string
 * \return The number of characters before first occurrence of ?
 */
unsigned int qstr_length(const char *s) {
  if (!s)
    return 0;
  size_t len = 0;
  for (; s[len] && s[len] != '?'; ++len)
    continue;
  return len;
}

/**
 * \brief Concatenates two ? terminated strings
 *
 * \param dst The ? terminated string that will contain the concatenated ?
 * terminated string
 * \param src A ? terminated string that will be appended to dst.
 * \return The length of the dst after concatenation
 */
int qstr_cat(char *dst, const char *src) {
  if (!dst)
    return 0;
  size_t dst_len = qstr_length(dst);
  if (!src)
    return dst_len;
  size_t src_len = qstr_length(src);

  memmove(dst + dst_len, src, src_len + 1);
  return dst_len + src_len;
}
