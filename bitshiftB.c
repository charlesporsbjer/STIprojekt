#include <stdio.h>

int main() {
  int x = 5; // initialize x to 5

  // left shift x by 1 bit
  x = x << 1;
  printf("x = %d\n", x); // output: x = 10

  // left shift x by 2 bits
  x = x << 2;
  printf("x = %d\n", x); // output: x = 20

  // right shift x by 1 bit
  x = x >> 1;
  printf("x = %d\n", x); // output: x = 10

  // right shift x by 2 bits
  x = x >> 2;
  printf("x = %d\n", x); // output: x = 5

  return 0;
}