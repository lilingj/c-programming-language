#include <stdlib.h>
#include <assert.h>
#include "../utils.h"
/*
  将 n 转化为 b进制 数，存到 s 中
*/
void itob(int n, char* s, int b) {
  int sign = n >= 0 ? 1 : -1;
  int i = 0;
  do {
    int val = abs(n % b);
    s[i++] = val <= 9 
      ? val + '0' 
      : val - 10 + 'a';
  } while ((n /= b) != 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i++] = '\0';
  reverse(s);
}

// unit test
int main(void) {
  char s[100];
  itob(-0b100100, s, 2);
  assert_str_equal(s, "-100100");
  itob(0xabcdef, s, 16);
  assert_str_equal(s, "abcdef");
  itob(35 * 36 + 34, s, 36);
  assert_str_equal(s, "zy");
  itob(0765, s, 8);
  assert_str_equal(s, "765");
  itob(0, s, 2);
  assert_str_equal(s, "0");
  return 0;
}