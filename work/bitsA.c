#include <stdio.h>

int main() {
  int x = 0x12345678; // some arbitrary value

  // bitwise AND (&)
  int y = x & 0x0000000F; // extract the low 4 bits
  printf("x & 0x0000000F = %x\n", y);

  // bitwise OR (|)
  int z = x | 0x000000F0; // set the low 4 bits to 1
  printf("x | 0x000000F0 = %x\n", z);

  // bitwise XOR (^)
  int w = x ^ 0x000000F0; // toggle the low 4 bits
  printf("x ^ 0x000000F0 = %x\n", w);

  // bitwise NOT (~)
  int v = ~x; // invert all bits
  printf("~x = %x\n", v);

  return 0;
}