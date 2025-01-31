#include "header.h"
#include <stdint.h>

/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header
 * is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 *  - SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than
 * each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the
 * header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to FRAME ID
 * field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header
 * is valid, possibly checked using validateHeader function above, and ACK bit
 * is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field
 * if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to SOURCE ADDRESS
 * field.
 */

int validateHeader(uint32_t header) {
  uint8_t sync = header & 63;
  uint8_t ack = header >> 6 & 1;
  uint8_t v = header >> 7 & 1;
  uint8_t type = header >> 8 & 7;
  uint8_t src = header >> 16;
  uint8_t dst = header >> 24;

  return (sync == 0x2a) && (ack ? v : 1) && (ack ? 1 : type) && src && dst &&
         (src ^ dst);
}

int getFrameId(uint32_t header) {
  if (!validateHeader(header))
    return -1;
  else
    return header >> 11 & 31;
}

int getFrameType(uint32_t header) {
  if (!validateHeader(header))
    return -1;
  else if (header >> 6 & 1)
    return 0;
  else
    return header >> 8 & 7;
}

int getSourceAddress(uint32_t header) {
  if (!validateHeader(header))
    return -1;
  else
    return header >> 16 & 255;
}

uint32_t createAckHeader(int destAddress, int sourceAddress, uint8_t frameId,
                         char valid) {
  return (uint32_t)destAddress << 24 | (uint32_t)sourceAddress << 16 |
         (uint32_t)frameId << 11 | (uint32_t)valid << 7 | (1 << 6) | 0x2a | 0;
}

uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId,
                      uint8_t type) {
  return (uint32_t)destAddress << 24 | (uint32_t)sourceAddress << 16 |
         (uint32_t)frameId << 11 | (uint32_t)type << 8 | 0x2a | 0;
}
