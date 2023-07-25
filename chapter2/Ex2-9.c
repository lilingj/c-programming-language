#include "stdio.h"
#include "assert.h"

/*
  x & (x - 1) 可以去掉 x 最右边的 1。分三种情况讨论：
    1. 00……00: 全0的，那么 x & (x - 1) = 0 & 11……11 = 0，没有 1 ，可以说去掉了最右边的 1
    2. ??……?1: 结尾一个 1 的，那么 x & (x - 1) = ??……?1 & ??……?0 = ??……?0，结果去掉了最右边的 1
    3. ??……?100: 结尾若干个 0 的，那么 x & (x - 1) = ??……?100 & ??……?011 = ??……?000，结果去掉了最右边的 1
  x & (x - 1) 的效果由此得之：
    1. x == 0: 不变
    2. x != 0: 去掉 x 最右边的 1
  使用该思想改写bitcount函数，可以优化几个循环
*/
int bitcount(unsigned x) {
  int count = 0;
  for (; x; x = x & (x - 1))
    count++;
  return count;
}

// 书中例子
int _bitcount(unsigned x) {
  int b = 0;
  for (; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

// unit test
int main(void) {
  for (int  i = 0; i < 100; i++) {
    assert(bitcount(i) == _bitcount(i));
  }
  assert(bitcount(0b11110000) == 4);
  return 0;
}
