#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "../utils.h"

/*
  正负数数量不相等，负数最小值没有对应的正数，所以 n = -n 对最小值不起作用
*/
void itoa(int n, char s[]) {
  int sign = n >= 0 ? 1 : -1;
  int i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

// unit test
int main(void) {
  char s[100];
  itoa(INT32_MIN, s);
  assert(strcmp(s, "-2147483648") == 0);
  itoa(1, s);
  assert(strcmp(s, "1") == 0);
  itoa(0, s);
  assert(strcmp(s, "0") == 0);
  return 0;
}
