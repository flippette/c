#include "bit_sequence.h"

/* DESCRIPTION:
 * ------------
 * The function extracts a sequence of bits from the argument data. The indexes
 * of the bits that will be extracted are the set bits in mask.
 *
 * The set bits in mask are copied to an unsigned char variable.
 *
 * For example,
 *
 * data = 0101 0101 1010 1010 0101 0101 1010 1010 = 0x55aa55aa
 * mask = 0000 0000 0001 0011 0011 0000 0010 0110 = 0x00133026
 *                     ^   ^^   ^^        ^   ^^
 * retVal =            0   10   01        1   01  = 0x4d
 *
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32 bit integer that will be operated on
 *
 * uint32_t mask: the bit packed data that indicates the bits to be copied to
 * result
 *
 * RETURNS:
 * ------------
 * The extracted sequence stored in a single unsigned char.
 *
 */
uint8_t op_bit_get_sequence(uint32_t data, uint32_t mask) {
  uint8_t out = 0;
  uint8_t i = 0;

  while (mask) {
    uint8_t shr = mask & 1;
    out |= (data & shr) << i;
    i += shr;

    // skip all zeros
    //
    // __builtin_ctz has UB if mask is 0, however that's already checked in the
    // while loop
    shr += __builtin_ctz(mask);
    data >>= shr;
    mask >>= shr;
  }

  return out;
}
