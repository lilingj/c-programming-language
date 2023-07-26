#include "../utils.h"

/*
  返回 t 在 s 中最右边出现的位置，没有则返回 -1
*/
int strrindex(char s[], char t[]) {
  int tlen = strlen(t);
  int i, j, k;
  for(i = strlen(s) - 1; i >= tlen - 1; i--) {
    for(j = i, k = tlen - 1; k >= 0 && s[j] == t[k]; j--, k--)
      ;
    if (k == -1) {
      return j + 1;
    }
  }
  return -1;
}

//      unit test
int main(void) {
  assert(strrindex("1", "1") == 0);
  assert(strrindex("012345678", "45678") == 4);
  assert(strrindex("01234", "-01234") == -1);
  return 0;
}