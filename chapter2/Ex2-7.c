#include "assert.h"
/*
  @return 将 x 第 p 位右数 n 位反转并返回 x
*/
unsigned invert(unsigned x, int p, int n) {
  int p0 = p - n + 1;
  int l = x & (~(~0 << p0) << 0);
  int m = (~x) & (~(~0 << n) << p0);
  int h = x & (~0 << (p + 1));
  return h + m + l;
}

// unit test
int main(void) {
  assert(invert(0b1010, 1, 1) == 0b1000);
  assert(invert(0b1111, 3, 4) == 0b0);
  return 0;
}
