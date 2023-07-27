#include<string.h>
#include<assert.h>
#include <stdlib.h>

void reverse(char* s) {
  int len = strlen(s);
  for (int i = 0, j = len - 1; i < j; i++, j--){
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

void assert_str_equal(char* s1, char* s2) {
  assert(strcmp(s1, s2) == 0);
}

void assert_equal(double v1, double v2) {
  assert(fabs(v1 - v2) < 0.000001);
}