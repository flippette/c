#include "source.h"
#include <ctype.h>
#include <string.h>

/**
 * \brief Counts alphabetical characters in a string
 *
 * \param str The string to be processed
 * \return The number of alphabetical characters
 */
int count_isalpha(const char *str) {
  if (!str)
    return 0;

  int ret = 0;
  for (size_t i = 0; i < strlen(str); ++i)
    ret += isalpha(str[i]) != 0;

  return ret;
}
