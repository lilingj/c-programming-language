#include "stdio.h"
#include "assert.h"

/*
  @return 返回 x 中右边第 p 位开始右数 n 的字段
  e.g. 
    p = 4, n = 3
    x  : 1 0 1 0 1 0 1 1 0
    idx: 8 7 6 5 4 3 2 1 0
                 -----
                 1 0 1 = 5
*/
unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p - n + 1)) & ~(~0 << n);
}

// unit test
unsigned _getbits(unsigned x, int p, int n) {
  int ret = 0;
  int start_idx = p - n + 1;
  int end_idx = p;
  for (int i = start_idx; i <= end_idx; i++) {
    ret += ((x >> i) & 1) << (i - start_idx);
  }
  return ret;
}
int main(void){
  int p = 2;
  int n = 2;
  for (int  i = 0; i < 100; i++) {
    printf("%d, %d\n", getbits(i, p, n), _getbits(i, p, n));
    assert((getbits(i, p, n) == _getbits(i, p, n)));
  }
  
  return 0;
}
