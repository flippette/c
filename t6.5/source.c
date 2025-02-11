#include "source.h"
#include <stdlib.h>
#include <string.h>

/**
 * \brief Removes the C comments from the input C code.
 *
 * \param input A code segment that contains some comments. It is a dynamically
 *              allocated string (array of characters).
 * \return A pointer to the polished code.
 */
char *delete_comments(char *input) {
  if (!input)
    return NULL;

  size_t len = strlen(input);

  char *lc = input;
  for (;;) {
    lc = strstr(lc, "//");
    if (!lc)
      break;
    char *nl = strstr(lc + 2, "\n");
    if (!nl)
      break;

    memmove(lc, nl + 1, len - (nl - input));
    len -= nl - lc;
  }

  char *bc = input;
  for (;;) {
    bc = strstr(bc, "/*");
    if (!bc)
      break;
    char *be = strstr(bc, "*/");
    if (!be)
      break;

    memmove(bc, be + 2, len - (be - input));
    len -= be - bc;
  }

  // return realloc(input, len);
  return input;
}
