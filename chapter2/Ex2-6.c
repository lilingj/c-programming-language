#include "assert.h"
/*
  @return 将 x 从 p 位开始的 n 位设置为 y 中 最右边 n 位的值，并返回x
*/
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned n0 = ~0 << n; // n 个 0
  unsigned n1 = ~n0; // n 个 1
  unsigned p0 = p - n + 1; // p - p0 + 1 = n
  return (x & (n0 << p0)) | ((n1 & y) << p0);
}

// unit test

int main(void) {
  assert(setbits(0b10101010, 3, 3, 0b010) == 0b10100100);
  assert(setbits(0b0001, 3, 4, 0b0) == 0b0);
  return 0;
}
