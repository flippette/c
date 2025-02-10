#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Reverses a given string.
 *
 * This function takes a constant character pointer as input, calculates the
 * length of the string, allocates memory for a new string of the same length,
 * and then fills the new string with the characters of the input string in
 * reverse order. The new string is null-terminated.
 *
 * \param str The input string to be reversed.
 * \return A pointer to the newly allocated reversed string. The caller is
 * responsible for freeing the allocated memory.
 */

char *reverse_string(const char *str) {
  unsigned int len = strlen(str); // Calculate the length of the input string
  char *newstr = malloc(len + 1); // Allocate memory for the new string,
                                  // including space for the null terminator
  unsigned int i;
  for (i = 0; i < len; i++) // Loop through each character of the input string
  {
    newstr[i] = str[len - i - 1]; // Copy characters from the input string to
                                  // the new string in reverse order
  }
  newstr[i] = 0; // Null-terminate the new string
  return newstr; // Return the pointer to the newly allocated reversed string
}

int main(void) {
  char *rev;
  rev = reverse_string("Hi there");
  printf("%s\n", rev);
  free(rev);

  rev = reverse_string("Hello there");
  printf("%s\n", rev);
  free(rev);

  return 0;
}
