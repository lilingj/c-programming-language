#include "assert.h"
#include "stdio.h"

/*
  @return x 循环右移 n 位
*/
unsigned rightrot(unsigned x, int n) {
  return (x << (8 * sizeof(unsigned) - n)) + (x >> n);
}

int main(void){
  assert(rightrot(0b11, 1) == 0x80000001);
  assert(rightrot(0x11111111, 4) == 0x11111111);
  assert(rightrot(0x11110000, 4) == 0x01111000);
  return 0;
}
