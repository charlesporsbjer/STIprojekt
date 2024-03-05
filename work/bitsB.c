#include <stdio.h>

int main() {
  int x = 0x12345678; // 32-bit integer

  // Bitwise AND (&)
  int y = x & 0x0000000F; // y = 0x00000004
  printf("x & 0x0000000F = %x\n", y);

  // Bitwise OR (|)
  int z = x | 0x0000000F; // z = 0x1234567F
  printf("x | 0x0000000F = %x\n", z);

  // Bitwise XOR (^)
  int w = x ^ 0x0000000F; // w = 0x12345675
  printf("x ^ 0x0000000F = %x\n", w);

  // Bitwise SHIFT (>>, <<)
  int shifted = x >> 4; // shifted = 0x0000000E
  printf("x >> 4 = %x\n", shifted);

  return 0;
}