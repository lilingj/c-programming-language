#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "../utils.h"

/*
  增加最小宽度参数
*/
void itoa(int n, char s[], int min_len) {
  int sign = n >= 0 ? 1 : -1;
  int i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  while (i < min_len) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}

// unit test
int main(void) {
  char s[100];
  itoa(INT32_MIN, s, 12);
  assert_str_equal(s, " -2147483648");
  itoa(1, s, 0);
  assert_str_equal(s, "1");
  itoa(0, s, 5);
  assert_str_equal(s, "    0");
  return 0;
}
